CC=gcc
CFLAGS=-lfl
SOURCES=words.l

PROG=prog.txt

EXECUTABLE=a.out

FLEX := $(shell command -v flex 2> /dev/null)

all: $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE) $(PROG)

a.out:
ifndef FLEX
	$(error flex is not available. Please install flex)
endif
	flex $(SOURCES)
	$(CC) lex.yy.c -o $(EXECUTABLE) $(CFLAGS)

clean:
	rm -rf *.yy.c $(EXECUTABLE)
