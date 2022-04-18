#pragma once
#include <fstream>
using namespace std;
class CropInfo{
    public:
        CropInfo();
        void readFromFile(istream &file);
        void readFromUser();
        void print(ostream &out);
        bool codeIsBetween(double lowerBound, double upperBound);
    private:
        enum {MAX_NAME_LEN = 60,
              NUM_YEARS = 19,
              START_YEAR = 2000};
        double cropCode;
        char name[MAX_NAME_LEN];
        double yieldsByYear[NUM_YEARS];
        
};
