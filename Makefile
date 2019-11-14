all: a.out Directory.o System.o File.o
	g++ -o a.out main.o Directory.o System.o File.o

a.out: main.cpp System.h
	g++ -std=c++11 -c main.cpp

File.o: File.h
	g++ -std=c++11 -c File.cpp

Directory.o: Directory.h File.h
	g++ -std=c++11 -c Directory.cpp

System.o: System.h Directory.h 
	g++ -std=c++11 -c System.cpp

clean: 
	rm *.o
	rm a.out
