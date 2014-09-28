CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=src/main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=algorithm.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LFGLAGS) $(OBJECTS) -o $@

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $< -o $@

clear:
	rm -f $(OBJECTS)
