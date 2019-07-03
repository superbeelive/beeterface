#ifndef WIN_CROSS_H
#define WIN_CROSS_H

#include <gtk/gtk.h>

typedef struct {
    
    GtkWidget* window ; 
    GtkWidget* box_principal ; 
    
    GtkWidget* box_left ;
    GtkWidget* box_right ; 
    
    GtkWidget* box_name ;
    GtkWidget* box_description ;
    GtkWidget* box_time ; 
    GtkWidget* box_label_time ; 
    GtkWidget* box_btn_video ; 
    GtkWidget* box_def_time_deb ; 
    GtkWidget* box_def_time_fin ; 

    GtkWidget* box_tag ; 
    GtkWidget* box_info ; 
    GtkWidget* box_btn_quit ;

    //IMG
    
    //LABEL


} cross_win_t ;

cross_win_t* cross_win_new () ; 
void cross_win_show ( cross_win_t* ) ;
void cross_win_del ( cross_win_t* ) ; 

#endif 
