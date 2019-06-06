#ifndef CAMERA_WIN_H
#define CAMERA_WIN_H 

#include <gtk/gtk.h>

#include "camera.h" 


typedef struct {

    GtkWidget *window ; 
    GtkWidget *box_principal ; 


} camera_win_t ;

//win_auteur.c
camera_win_t* camera_win_new() ; 
void camera_win_del ( camera_win_t* ) ; 
void camera_win_show ( camera_win_t* ) ;

#endif
