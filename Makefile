CC = gcc
CDFLAGS = -W -Wall
LDFLAGS = 

all: test

test: auteur.o test.o an_cross.o
	$(CC) -o $@ $^ $(LDFLAGS)

%o: %.c
	$(CC) -c $^ $(CFLAGS)

.PHONY: clean 
clean:
	rm -f *.o
	rm -f test
	rm -f *~
