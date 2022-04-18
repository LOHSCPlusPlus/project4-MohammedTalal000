#include "Video.h"
#include <cstring>
Video::Video() {
    name = new char [50];
    strcpy(name, "unknown");
}
Video::~Video() {
    delete [] name;
}
