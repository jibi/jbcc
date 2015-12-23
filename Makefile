CC=clang
CFLAGS=-c -Wall -pedantic -I include -g -std=gnu11
LDFLAGS=
SOURCES=src/main.c src/source.c src/lex.c src/debug.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=jbcc

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(EXECUTABLE) $(OBJECTS)
