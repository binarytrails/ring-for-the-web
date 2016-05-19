CXX=clang++
CXXFLAGS=-std=c++11 -Wall -Wextra -Wfatal-errors -pedantic -O3 
EXE=http-parser

all: main.o parserHTTP.o
	$(CXX) $(CXXFLAGS) main.o parserHTTP.o -o $(EXE)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

parserHTTP.o: parserHTTP.cpp
	$(CXX) $(CXXFLAGS) -c parserHTTP.cpp

clean:
	rm http-parser *.o
