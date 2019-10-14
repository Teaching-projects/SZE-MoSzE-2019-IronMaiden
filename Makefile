all: main.o System.o Directory.o
	g++ -o a.out main.o System.o Directory.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Directory.o: Directory.cpp
	g++ -std=c++11 -c Directory.cpp

System.o: System.cpp
	g++ -std=c++11 -c System.cpp

a.out:main.o Directory.o System.o
	g++ -o a.out main.o Directory.o System.o

clean: 
	rm *.o