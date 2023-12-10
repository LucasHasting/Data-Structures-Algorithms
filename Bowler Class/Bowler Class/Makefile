# This will compile the grade report files
all: program

program: Bowler.o JuniorBowler.o driver.o
	g++ -o program Bowler.o JuniorBowler.o driver.o 

Bowler.o: Bowler.cpp
	g++ -c Bowler.cpp

JuniorBowler.o: JuniorBowler.cpp
	g++ -c JuniorBowler.cpp

driver.o: driver.cpp
	g++ -c driver.cpp

clean: 
	rm -rf *.o program
