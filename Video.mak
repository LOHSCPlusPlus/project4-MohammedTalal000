Video : Video.o VideoMain.o 
	g++ -g Video.o VideoMain.o -o Video

Video.o : Video.cpp Video.h ReadUtils.h
	g++ -g -Wall -c Video.cpp  -o Video.o


VideoMain.o : VideoMain.cpp  Video.h 
	g++ -g -Wall -c VideoMain.cpp  -o VideoMain.o

