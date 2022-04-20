CC=gcc
CFLAGS=-lfl
SOURCES=words.l

PROG=prog.txt

EXECUTABLE=a.out

all: $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE) $(PROG)

a.out:
	flex $(SOURCES)
	$(CC) lex.yy.c -o $(EXECUTABLE) $(CFLAGS)

clean:
	rm -rf lex.yy.c $(EXECUTABLE)
