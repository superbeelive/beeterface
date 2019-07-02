#ifndef COLOR_WIN_H
#define COLOR_WIN_H 

#include <gtk/gtk.h>

typedef struct {
    
    GtkWidget* window ; 
    GtkWidget* box_principale ; 
    GtkWidget* grid_btn ; 

    GtkWidget* btn_red ; 
    GtkWidget* btn_blue ;
    GtkWidget* btn_green ; 
    GtkWidget* btn_yellow ;
    GtkWidget* btn_pink ;

    GtkWidget* img_btn_red ; 
    GtkWidget* img_btn_blue ;
    GtkWidget* img_btn_green ; 
    GtkWidget* img_btn_yellow ;
    GtkWidget* img_btn_pink ;

} color_win_t ;

color_win_t* color_win_new() ; 
void color_win_show ( color_win_t* ) ; 
void color_win_del ( color_win_t* ) ; 

#endif
