# This will compile the grade report files
all: program

program: personType.o studentType.o courseType.o testProgram.o
	g++ -o program personType.o studentType.o courseType.o testProgram.o

personType.o: personType.cpp
	g++ -c personType.cpp

studentType.o: studentType.cpp
	g++ -c studentType.cpp

courseType.o: courseType.cpp
	g++ -c courseType.cpp

testProgram.o: testProgram.cpp
	g++ -c testProgram.cpp

clean: 
	rm -rf *.o program
