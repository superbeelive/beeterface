#ifndef VIDEO_WIN_H
#define VIDEO_WIN_H 

#include <gtk/gtk.h>

#include "video.h" 


typedef struct {

    GtkWidget *window ; 
    GtkWidget *box_principal ; 


} video_win_t ;

//win_auteur.c
video_win_t* video_win_new() ; 
void video_win_del ( video_win_t* ) ; 
void video_win_show ( video_win_t* ) ;

#endif
