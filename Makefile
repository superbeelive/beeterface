CC = gcc
CFLAGS = -g `pkg-config --cflags gtk+-3.0`
LDFLAGS = `pkg-config --libs gtk+-3.0`

beeterface: beeterface.o main_win.o modif_win.o auteur_win.o an_arrow.o an_cross.o an_measure.o an_moving_cross.o an_oblong.o an_text.o auteur.o camera.o color.o main_win.o projet.o tag.o video.o interface.o queen.o win_callback_auteur.o video_win.o camera_win.o win_callback_camera.o win_callback_video.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f *.o 
	rm -f beeterface
	rm -f *~





