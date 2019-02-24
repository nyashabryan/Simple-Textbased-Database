# Makefile for C++ programs
# Nyasha Bryan Katemauswa
# 24 February 2019

# include dependencies; rules below

include incl.defs

# Directories
SRC=./src
BIN=./bin

CC=g++
CCFLAGS=-std=c++11
SOURCES=main.cpp
OBJECTS=main.o

main: $(OBJECTS)
	$(CC) $(CCFLAGS) $(OBJECTS) -o main $(LIBS)

.cpp.o:
	$(CC) $(CCFLAGS) -c $<

# Type "make depend" to make dependencies
depend:
	$(CC) -M $(SOURCES) > incl.defs
