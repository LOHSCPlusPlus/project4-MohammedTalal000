#include "CropDB.h"
#include "ReadUtils.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
Create the DB and load the default .txt file using the private readFile function.
*/
CropDB::CropDB(){
    numCrops = 0;
    readFile("cropTiny.txt");
}

/**
Ask the user to specify a db name, and then load the data using the private function
*/
void CropDB::reload(){
    char filename[100];
    cout << "Enter the crop input filename: ";
    cin >> filename;
    readFile(filename);
}

/**
Get the name of the file and then write the data out to file.
*/
void CropDB::printToFile(){
    string filename;
    cout << "Enter the crop output filename: ";
    cin >> filename;
    ofstream file(filename);
    for (int index = 0; index < numCrops; index++) {
        crops[index].print(file);    
    }
}

/**
Insert a new entry at an index specified by the user.
The values will be read from the console.
*/
void CropDB::insert(){
    if (numCrops < MAX_CROPS) {
        int insertIndex = getValidIndex();
        for (int index = numCrops; index > insertIndex; index--) {
            crops[index] = crops[index - 1];
        }
        crops[insertIndex].readFromUser();
        numCrops++;
    }
    else {
        cout << "Database is full" << endl;
    }
    
}

/**
Add a new entry at the end of the current array.
The values will be read from the console.
*/
void CropDB::add(){
    if (numCrops < MAX_CROPS) {
        crops[numCrops].readFromUser();
        numCrops++;
    }
    else {
        cout << "Database is full" << endl;
    }
}

/**
Get an index from the user. Then collapse the array so that 
the array loses the index specified.
*/
void CropDB::remove(){
    if (numCrops > 0) {
        int delIndex = getValidIndex();
        for (int index = delIndex; index < numCrops - 1; index++) {
            crops[index] = crops[index + 1];
        }
        numCrops--;
    }
    else {
        cout << "Database is empty" << endl;
    }
}

/**
Print all the crop info with ids between the values specified by
the user.
*/
void CropDB::search(){
    double min = readDouble("Enter the min crop code to find: ");
    double max = readDouble("Enter the max crop code to find: ");
    print(true, min, max);
}

/**
Print all the entries.
*/
void CropDB::print() {
    print(false, 0, 0);
}

/**
Print a menu with the things the user is allowed to do with this database.
If we add new functions, we'll expand this function so that the user is presented
with new options.
*/
void CropDB::dbMenu(){
    // This will let us use meaningful names in the switch.
    enum MenuOptions{
        PRINT = 1, // enum will automatically add 1 to the values that follow
        SAVE_TO_FILE,
        INSERT,
        ADD,
        REMOVE,
        SEARCH,
        RELOAD,
        QUIT,
    };
    // cstrings we will print as menu options.
    const char *options[] = {
        "Print DB",
        "Save DB to file",
        "Insert a new entry",
        "Add a new entry to the end",
        "Remove an entry",
        "Search for crops with codes within a range",
        "Reload the DB from a file",
        "Quit"
    };

    // Spin here until the user enters the QUIT value.
    int option = -1;
    while(option != QUIT) {
        // Print the menu options (we use index - 1) because 
        // the first option is 1, but the first entry in the array
        // is at index 0.
        for (int index = PRINT; index <= QUIT; index++) {
            cout << index << ") " << options[index - 1] << endl;
        }
        option = readInt("Enter your selection: ");
        switch(option) {
            case PRINT:
                print();
                break;
            case SAVE_TO_FILE:
                printToFile();
                break;
            case INSERT:
                insert();
                break;
            case ADD:
                add();
                break;
            case REMOVE:
                remove();
                break;
            case SEARCH:
                search();
                break;
            case RELOAD:
                reload();
                break;
            case QUIT:
                break;
            default:
                cout << "Invalid selection!" << endl;
                break;
        }
    }
    
}

/** 
Private functions
*/

/**
    Loops asking the user for an index within the range of crops.
    used by the remove and insert function.
*/
int CropDB::getValidIndex() {
    int index = -1;
    while (index < 0 || index >= numCrops) {
        cout << "Enter an index between 0 and " << numCrops << ": ";
        index = readInt("");
    }
    return index;
}
/**
    Loops and prints out the crops to the screen.
    If searchRange is true, then it only prints crops between min and max.
    Used by print and search
*/
void CropDB::print(bool searchRange, double min, double max) {
    for (int index = 0; index < numCrops; index++) {
        if (searchRange == false or crops[index].codeIsBetween(min, max)) {
            cout << "Index " << index << ": ";
            crops[index].print(cout);
        }
    }
}

/**
Loads the crop info from the file specified. 
Used in the constructor and reload functions.
*/
void CropDB::readFile(const char fileName[]) {
    ifstream file(fileName);
    numCrops = 0;
    while(file.peek() != EOF && numCrops < MAX_CROPS) {
        crops[numCrops].readFromFile(file);
        numCrops++;
    }
    if (numCrops == 0) {
        cout << "There is no crop data in " << fileName << " did you spell it correctly?" << endl;
    }
}
