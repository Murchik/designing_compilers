CC=g++
CFLAGS=

BISON_SOURCES	= input.y
FLEX_SOURCES	= input.l

PROG=prog.txt

TARGET=a.out

BISON := $(shell command -v bison 2> /dev/null)
FLEX := $(shell command -v flex 2> /dev/null)

all: $(TARGET)

run: $(TARGET) $(PROG)
	./$(TARGET) $(PROG)

ifndef BISON
	$(error bison is not available. Please install bison)
endif
ifndef FLEX
	$(error flex is not available. Please install flex)
endif

AST_HEADERS := ast.h
AST_SOURCES := ast.c

BISON_INCLUDE_TARGETS	:= y.tab.h
BISON_C_TARGETS			:= y.tab.c

BISON_TARGETS := $(BISON_C_TARGETS) $(BISON_INCLUDE_TARGETS)
$(BISON_TARGETS): $(BISON_SOURCES)
	bison -dy $<

FLEX_TARGETS := lex.yy.c
$(FLEX_TARGETS): $(FLEX_SOURCES)
	flex $(FLEX_SOURCES)

$(TARGET): $(BISON_TARGETS) $(FLEX_TARGETS) $(AST_HEADERS) $(AST_SOURCES)
	$(CC) -o $@ $(CFLAGS) $(BISON_C_TARGETS) $(FLEX_TARGETS) $(AST_SOURCES)

.PHONY: clean
clean:
	$(RM) $(TARGET) $(BISON_TARGETS) $(FLEX_TARGETS)
