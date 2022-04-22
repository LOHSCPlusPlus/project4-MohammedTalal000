#include "CropInfo.h"
#include "ReadUtils.h"
#include <cstring>
#include <iostream>
using namespace std;
/**
Clear all the values to zero.
*/
CropInfo::CropInfo(){
    name = nullptr;
    yieldsByYear = new double[NUM_YEARS];
    cropCode = 0;
    for (int index = 0; index < NUM_YEARS; index++) {
        yieldsByYear[index] = 0;
    }
}

CropInfo::CropInfo(const CropInfo &other){
    name = nullptr;
    yieldsByYear = new double[NUM_YEARS];
    cropCode = 0;
    name = createCharPtr(other.name);
    for (int index = 0; index < NUM_YEARS; index++) {
        yieldsByYear[index] = other.yieldsByYear[index];
    }
}

void CropInfo::operator=(const CropInfo &other){
  delete[] name;
  name = createCharPtr(other.name);
  for (int index = 0; index < NUM_YEARS; index++) {
      yieldsByYear[index] = other.yieldsByYear[index];
  }
}

CropInfo::~CropInfo(){
  delete[] name;
  delete[] yieldsByYear;
}
/**
Loads the information from the file specified
*/
void CropInfo::readFromFile(istream &file) {
    file >> cropCode;
    file.ignore(100, ';');
    delete [] name;
    name = readCString(file, ';');
    for (int index = 0; index < NUM_YEARS; index++) {
        file >> yieldsByYear[index];
        // Either ignore the ; or \n after each year.
        if (file.peek() != EOF) {
            file.ignore(1, file.peek());
        }
    }
}
/**
Very similar to readFromFile, but we are prompting the user
for the values.
*/
void CropInfo::readFromUser(){
    cropCode = readDouble("Enter the crop code: ");
    cin.ignore(100, '\n');
    cout << "Enter the crop name: ";
    delete [] name;
    name = readCString(cin, '\n');
    for (int index = 0; index < NUM_YEARS; index++) {
        // Create the prompt here, no prompt sent to readDouble.
        cout << "Enter the yield for the year " <<  START_YEAR + index << ": ";
        yieldsByYear[index] = readDouble("");
    }
}
/**
Print the data to a file or the screen depending on the value in out.
*/
void CropInfo::print(ostream &out){
    out << cropCode << ";";
    out << name;
    for (int index = 0; index < NUM_YEARS; index++) {
        out << ";"; // Print the semi-colon for the prior entry so we can end with \n
        out << yieldsByYear[index];
    }
    out << endl; // The last entry does not have a ';' instead it ends with a \n
}

/**
 Returns true if the cropCode is between the two values passed in, false otherwise.
*/
bool CropInfo::codeIsBetween(double lowerBound, double upperBound){
    return (cropCode >= lowerBound && cropCode <= upperBound);
}
