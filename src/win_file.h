#ifndef FILE_WIN_H
#define FILE_WIN_H

#include <gtk/gtk.h>

typedef struct {

    GtkWidget* window ; 
    GtkWidget* box_principal ;

    GtkWidget* box_up ; 
    GtkWidget* box_middle ;
    GtkWidget* box_down ; 

    GtkWidget* label_tri ;
    GtkWidget* combo_tri ; 
    GtkWidget* search_tri ;

    GtkWidget* scroll_tag ;
    GtkWidget* label_tag ; 

    GtkWidget* btn_quit ;
    GtkWidget* btn_open ; 

} file_win_t ; 

file_win_t* file_win_new() ; 
void file_win_show ( file_win_t* ) ; 
void file_win_del ( file_win_t* ) ; 

#endif
