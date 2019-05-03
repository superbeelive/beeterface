CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0`
LDFLAGS = `pkg-config --libs gtk+-3.0`

beeterface: beeterface.o main_win.o modif_win.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f *.o 
	rm -f beeterface
	rm -f *~
