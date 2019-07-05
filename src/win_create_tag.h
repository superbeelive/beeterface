#ifndef CREATE_TAG_WIN_H
#define CREATE_TAG_WIN_H

#include <gtk/gtk.h>

typedef struct {

    GtkWidget* window ; 
    GtkWidget* box_principal ;

    GtkWidget* box_entry ;
    GtkWidget* box_btn_quit ; 

    GtkWidget* entry_tag ; 

    GtkWidget* btn_add_tag ; 
    GtkWidget* btn_ann ; 
    GtkWidget* btn_enr ;
    
} create_tag_win_t ; 

create_tag_win_t* create_tag_win_new() ; 
void create_tag_win_show ( create_tag_win_t* ) ; 
void create_tag_win_del ( create_tag_win_t* ) ; 

#endif
