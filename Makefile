a.out:main.o File.o Directory.o System.o
	g++ -o a.out main.o Directory.o System.o File.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

File.o: File.cpp
	g++ -std=c++11 -c File.cpp

Directory.o: Directory.cpp
	g++ -std=c++11 -c Directory.cpp

System.o: System.cpp
	g++ -std=c++11 -c System.cpp

clean: 
	rm *.o
	rm a.out
