ReadUtilsExample : ReadUtilsExample.o ReadUtils.o 
	g++ -g ReadUtilsExample.o ReadUtils.o -o ReadUtilsExample

ReadUtilsExample.o : ReadUtilsExample.cpp  ReadUtils.h
	g++ -g -Wall -c ReadUtilsExample.cpp  -o ReadUtilsExample.o


ReadUtils.o : ReadUtils.cpp  
	g++ -g -Wall -c ReadUtils.cpp  -o ReadUtils.o

