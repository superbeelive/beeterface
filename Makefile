CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0`
LDFLAGS = `pkg-config --libs gtk+-3.0`

beeterface: beeterface.o projet.o main_win.o modif_win.o auteur_win.o auteur.o an_arrow.o an_cross.o an_measure.o an_moving_cross.o an_oblong.o an_text.o camera.o color.o main_win.o tag.o


	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f *.o 
	rm -f beeterface
	rm -f *~
