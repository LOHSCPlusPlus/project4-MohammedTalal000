CropDB : CropDB.o CropInfo.o ReadUtils.o CropMain.o 
	g++ -g CropDB.o CropInfo.o ReadUtils.o CropMain.o -o CropDB

CropDB.o : CropDB.cpp CropDB.h ReadUtils.h CropInfo.h 
	g++ -g -Wall -c CropDB.cpp  -o CropDB.o


CropInfo.o : CropInfo.cpp ReadUtils.h CropInfo.h 
	g++ -g -Wall -c CropInfo.cpp  -o CropInfo.o

ReadUtils.o : ReadUtils.cpp ReadUtils.h 
	g++ -g -Wall -c ReadUtils.cpp  -o ReadUtils.o

CropMain.o : CropMain.cpp ReadUtils.h CropInfo.h CropDB.h 
	g++ -g -Wall -c CropMain.cpp  -o CropMain.o

