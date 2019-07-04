#ifndef TAG_WIN_H
#define TAG_WIN_H

#include <gtk/gtk.h>
#include "tag.h"

typedef struct {
    
    GtkWidget* window ; 
    GtkWidget* box_principal ;
    GtkWidget* box_up ; 
    GtkWidget* box_down ; 
    GtkWidget* box_btn ; 

    GtkWidget* box_tag ; 
    GtkWidget* box_left ;
    GtkWidget* box_middle ; 
    GtkWidget* box_right ; 

    GtkWidget* search ; 
   
    GtkWidget* btn_tag ;
    GtkWidget* btn_ann ;
    GtkWidget* btn_enr ;

    GtkWidget* entry_tag ;

    GtkWidget *scroll ;
    GtkWidget *label_test ; 
    GtkWidget *label_test2 ; 
    GtkWidget *label_test3 ; 

    int cnt_edit ; 

} tag_win_t ;

//tag_win.c
tag_win_t* tag_win_new() ;
void tag_win_show ( tag_win_t* nemo ) ;  
void tag_win_del ( tag_win_t* nemo ) ; 


void tag_btn_edit_modif ( tag_win_t* win ) ;
void tag_btn_edit_ok( tag_win_t* win ) ;
#endif
