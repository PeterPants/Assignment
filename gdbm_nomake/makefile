CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES= lab3.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hello
GDBM=-I/opt/gdbm-1.8.3/include
NEW=-lgdbm

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(GDBM) $(LDFLAGS) $(OBJECTS) $(NEW) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ 

