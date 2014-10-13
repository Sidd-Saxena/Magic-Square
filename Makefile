CFILES = Maintest2.c Magicsquare2.c
HFILES = Magicsquare.h
CC = gcc
CFLAGS = -Wall -lm
OBJFILES = Maintest2.o

all: $(CFILES)
	$(CC) $(CFLAGS) -o $(OBJFILES) $(CFILES)

run: all $(OBJFILES)
	./$(OBJFILES)

clean:
	rm –f *.o $(OBJFILES)