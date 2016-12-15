CXX = g++
CC = gcc
CFLAGS = -c 
CXXFLAGS = -c  -std=c++11

CXXSOURCES = \
	CMTreeMiner.cpp \
	../trees/tree.cpp
OBJECT = \
	CMTreeMiner.o\
	tree.o
BINARY = CMTreeMiner

program: 
	$(CXX) $(CXXFLAGS) $(CXXSOURCES)
	$(CXX) $(OBJECT) -o $(BINARY)

all: 
	program


.PHONY: clean
clean:
	$(RM) -rf $(OUTPUTDIR)
	$(RM) ./*.gc??
	$(RM) ./*.o