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
    GtkWidget* box_text_tag ;
    GtkWidget* box_scroll_tag ;
    GtkWidget* box_left ;
    GtkWidget* box_right ;
    GtkWidget* box_tag_dispo ; 

    GtkWidget* frame_tag ; 

    GtkWidget* search ; 
  

    GtkWidget* btn_tag ;
    GtkWidget* btn_create_tag ;
    GtkWidget* btn_ann ;
    GtkWidget* btn_enr ;

    GtkWidget* entry_tag ;

    GtkWidget *scroll ;
    GtkWidget* label_search ; 
    GtkWidget *label_test ; 
    GtkWidget *label_test2 ; 
    GtkWidget *label_test3 ; 
    GtkWidget* label_tag_dispo ; 
    
    GtkWidget* sep ; 
   
    GtkTextBuffer* buffer_tag_list ; 
    GtkWidget* text_tag_list ;
    int cnt_edit ; 

} tag_win_t ;

//tag_win.c
tag_win_t* tag_win_new() ;
void tag_win_show ( tag_win_t* nemo ) ;  
void tag_win_del ( tag_win_t* nemo ) ; 


void tag_btn_edit_modif ( tag_win_t* win ) ;
void tag_btn_edit_ok( tag_win_t* win ) ;
#endif
