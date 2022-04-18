#include <iostream>
#include <fstream>
using namespace std;
#include "ReadUtils.h"
// This demonstrates how to use the two new cstring functions in readutils
int main() {
    char *ptr1 = createCharPtr("Hello");
    char *ptr2 = createCharPtr(ptr1);
    cout << " ptr1 contents = " << ptr1 << endl;
    cout << " ptr2 contents = " << ptr2 << endl;

    delete [] ptr2;
    ptr2 = createCharPtr("Goodbye");
    cout << " ptr2 contents = " << ptr2 << endl;



    // Always do a delete before changing the pointer.
    delete [] ptr1;
    cout << "Enter a sentence: ";
    ptr1 = readCString(cin, '\n');
    cout << " ptr1 contents = " << ptr1 << endl;

    ifstream inFile("examples.txt");
    while(inFile.peek() != EOF) {
        // Always do a delete before changing the pointer.
        delete [] ptr2;
        ptr2 = readCString(inFile, ';');
        cout << " ptr2 contents = " << ptr2 << endl;
    }



    delete [] ptr1;
    delete [] ptr2;


   return 0;
}
