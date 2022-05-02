CC=g++
CFLAGS=

BISONSOURCES=input.y
FLEXSOURCES=input.l

PROG=prog.txt

EXECUTABLE=a.out

BISON := $(shell command -v bison 2> /dev/null)
FLEX := $(shell command -v flex 2> /dev/null)

all: $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE) $(PROG)

a.out:
ifndef BISON
	$(error bison is not available. Please install bison)
endif
	bison -dy $(BISONSOURCES)
ifndef FLEX
	$(error flex is not available. Please install flex)
endif
	flex $(FLEXSOURCES)
	$(CC) $(CFLAGS) tree.cpp lex.yy.c y.tab.c -o $(EXECUTABLE)

clean:
	rm -rf *.yy.c *.tab.h *.tab.c $(EXECUTABLE)
