CC=g++
CFLAGS=-c -Wall -g

SOURCES=$(wildcard *.cpp)

OBJ_DIR=obj
OBJECTS=$(SOURCES:.cpp=.o)

BIN_DIR=bin
EXECUTABLE=out

all: $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	clear
	rm -rf $(EXECUTABLE) *.o
