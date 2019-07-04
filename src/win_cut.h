#ifndef CUT_WIN_H
#define CUT_WIN_H

#include <gtk/gtk.h>

typedef struct {

    GtkWidget* window ; 
    GtkWidget* box_principal ; 

} cut_win_t ; 

cut_win_t* cut_win_new() ; 
void cut_win_show ( cut_win_t* ) ; 
void cut_win_del ( cut_win_t* ) ; 

#endif
