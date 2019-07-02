#ifndef TAG_WIN_H
#define TAG_WIN_H

#include <gtk/gtk.h>
#include "tag.h"

typedef struct {
    
    GtkWidget *window ; 
    GtkWidget *box_principal ;
    GtkWidget *box_up ; 
    GtkWidget *box_down ; 

    GtkWidget *search ; 
    
    GtkWidget *entry_edit ; 
    
    GtkWidget *btn_edit ; 
    GtkWidget *img_btn_edit_modif ;
    GtkWidget *img_btn_edit_ok ;  

    GtkWidget *scroll ;
    GtkWidget *label_test ; 

    int cnt_edit ; 

} tag_win_t ;

//tag_win.c
tag_win_t* tag_win_new() ;
void tag_win_show ( tag_win_t* nemo ) ;  
void tag_win_del ( tag_win_t* nemo ) ; 


void tag_btn_edit_modif ( tag_win_t* win ) ;
void tag_btn_edit_ok( tag_win_t* win ) ;
#endif
