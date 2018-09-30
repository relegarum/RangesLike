CC = g++
CXXFLAGS = -Wall -Wpedantic -Wextra -Werror -std=c++17

SOURCES = main.cpp
EXECUTABLE_NAME = functional

all:
	$(CC) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE_NAME)
	
