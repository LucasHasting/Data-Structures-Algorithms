all: program


program: boxTypeImp.o rectangleTypeImp.o testProgInheritance.o 	
	g++ boxTypeImp.o rectangleTypeImp.o testProgInheritance.o -o program

boxTypeImp.o: boxTypeImp.cpp
	g++ -c boxTypeImp.cpp

rectangleTypeImp.o: rectangleTypeImp.cpp
	g++ -c rectangleTypeImp.cpp

testProgInheritance.o: testProgInheritance.cpp
	g++ -c testProgInheritance.cpp

clean:
	rm -rf *.o program
