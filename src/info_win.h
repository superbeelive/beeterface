#ifndef INFO_WIN_H
#define INFO_WIN_H

#include <gtk/gtk.h>

typedef struct {

    GtkWidget *window ; 
    GtkWidget *box_principal ;
    GtkWidget *box_text ; 
    GtkWidget *label_title ;     

} info_win_t ;

info_win_t* info_win_new() ; 
void info_win_show ( info_win_t* win ) ; 
void info_win_del ( info_win_t* win ) ; 

#endif 
