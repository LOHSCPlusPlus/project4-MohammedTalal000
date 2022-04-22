#pragma once
#include <fstream>
using namespace std;
class CropInfo{
    public:
        CropInfo();
        ~CropInfo();
        void readFromFile(istream &file);
        void readFromUser();
        void print(ostream &out);
        bool codeIsBetween(double lowerBound, double upperBound);
        void operator=(const CropInfo &other);
        CropInfo(const CropInfo &other);
    private:
        enum {
              NUM_YEARS = 19,
              START_YEAR = 2000};
        double cropCode;
        char *name;
        double *yieldsByYear;
        
};
