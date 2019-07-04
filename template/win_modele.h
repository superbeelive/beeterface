#ifndef FILE_WIN_H
#define FILE_WIN_H

#include <gtk/gtk.h>

typedef struct {

    GtkWidget* window ; 
    GtkWidget* box_principal ; 

} file_win_t ; 

file_win_t* file_win_new() ; 
void file_win_show ( file_win_t* ) ; 
void file_win_del ( file_win_t* ) ; 

#endif
