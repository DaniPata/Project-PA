CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Ciclu_Eulerian.c Fleury.c Fleury.h Ros.c Ros.h
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=Ciclu_Eulerian

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@