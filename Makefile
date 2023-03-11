CXX = g++
CXXFLAGS = -Wall

BookDB.o: BookDB.cpp

clean:
	-rm BookDB.o
	-rm demo

build: demo.cpp BookDB.o
	$(CXX) $(CXXFLAGS) -o BookDB demo.cpp BookDB.o