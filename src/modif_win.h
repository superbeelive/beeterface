#ifndef MODIF_WIN_H
#define MODIF_WIN_H

#include <gtk/gtk.h>

//const gchar* names[] = {"test1", "test2", "test3", "test4" };


typedef struct {

    GtkWidget *window ; //Fenetre changements
    
    //BOX
    GtkWidget *box_principale ;    
    GtkWidget *box_left ;    
    GtkWidget *box_right ;
    
    GtkWidget *box_video ;
    GtkWidget *box_time ;
    GtkWidget *box_label_time ;
    GtkWidget *box_tool_video ; 
    
    GtkWidget *box_tool_an ; 
    GtkWidget *box_an ; 
    GtkWidget *box_tag ; 
    
    GtkWidget *box_btn_tag ; 


    //GRID 
    GtkWidget *grid_tool_video ;
    GtkWidget *grid_tool_an ; 
    
    //OTHER BOX
    GtkWidget* scroll_an ;  
    GtkWidget* scroll_tag ;  
    GtkWidget* frame_tool_an ; 
    //IMAGE
    GtkWidget *img_video ;
    
    //LABEL
    GtkWidget *label_title_video ;
    GtkWidget *label_title_tag ; 
    GtkWidget *label_title_an ; 
    
    GtkWidget *label_time_deb;
    GtkWidget *label_time_fin;
    
    GtkWidget *label_test ; 
    GtkWidget *label_test2 ; 

    //BUTTON
    GtkWidget* button_list[4];
    GtkWidget* image_button_list[4];
    
    GtkWidget* btn_an_cross ;
    GtkWidget* btn_an_circle ; 
    GtkWidget* btn_an_oblong ;
    GtkWidget* btn_an_arrow ;
    GtkWidget* btn_an_measure ;
    GtkWidget* btn_an_moving_cross ;
    GtkWidget* btn_an_text ;
    GtkWidget* btn_color ;
    GtkWidget* btn_erase ;

    GtkWidget* img_btn_an_cross ;
    GtkWidget* img_btn_an_circle ; 
    GtkWidget* img_btn_an_oblong ;
    GtkWidget* img_btn_an_arrow ;
    GtkWidget* img_btn_an_measure ;
    GtkWidget* img_btn_an_moving_cross ;
    GtkWidget* img_btn_an_text ;
    GtkWidget* img_btn_color ; 
    GtkWidget* img_btn_erase ; 

    GtkWidget* button_add_tag ;
    GtkWidget* button_remove_tag ; 
    //SEPARATOR
    GtkWidget* sep ;
    GtkWidget* sep2 ; 
    
    //OTHER WIDGET  
    GtkWidget *barre_temps;
    GtkAdjustment *adjustement_barre_temps;
    

    
} modif_win_t ; //typedef + struct sur la même ligne

//pré déclaration des fonctions 
modif_win_t* modif_win_new() ; 
void modif_win_show( modif_win_t* ) ;
void modif_win_del( modif_win_t* ) ;

#endif
