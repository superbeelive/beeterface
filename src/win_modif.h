#ifndef MODIF_WIN_H
#define MODIF_WIN_H

#include <gtk/gtk.h>



typedef struct {

    GtkWidget *window ; //Fenetre changements
    
    //BOX
    GtkWidget* box_principale ;    
    GtkWidget* box_left ;    
    GtkWidget* box_right ;
    
    GtkWidget* box_video ;
    GtkWidget* box_time ;
    GtkWidget* box_label_time ;
    GtkWidget* box_label_timef ;
    GtkWidget* box_tool_video ; 
    
    GtkWidget* box_tool_an ; 
    GtkWidget* box_an ; 
    GtkWidget* box_tag ;
    GtkWidget* box_btn_tag ;
    GtkWidget* box_meta ;
    GtkWidget* box_quit ;
    
    GtkWidget* box_scroll_an ;
    GtkWidget* box_scroll_tag ; 

    GtkWidget* box_text_an ; 
    GtkWidget* box_text_tag ;
    GtkWidget* box_text_ss_tag1 ; 
    GtkWidget* box_text_ss_tag2 ; 
    GtkWidget* box_text_meta ; 


    //FRAME
    GtkWidget* frame_tool_an ;
    GtkWidget* frame_an ;
    GtkWidget* frame_meta ;
    
    //SCROLL
    GtkWidget* scroll_an ;  
    GtkWidget* scroll_tag ; 
    GtkWidget* scroll_meta ;
    
    //GRID 
    GtkWidget* grid_tool_video ;
    GtkWidget* grid_tool_an ; 
    GtkWidget* grid_meta ; 
    


    //IMAGE
    GtkWidget *img_video ;
    
    //LABEL
    GtkWidget *label_title_video ;
   
    GtkWidget* label_title_tag ;

    GtkWidget *label_time_deb;
    GtkWidget *label_time_fin;
    
    GtkWidget *label_test ; 
    GtkWidget *label_test2 ;
    GtkWidget *label_test3 ;

    GtkWidget* label_name_ruche ;
    GtkWidget* label_description ;
    GtkWidget* label_camera ;
    GtkWidget* label_nruche ;
    GtkWidget* label_ncadre ;

    GtkWidget* label_info_name_ruche ;
    GtkWidget* label_info_description ;
    GtkWidget* label_info_camera ;
    GtkWidget* label_info_nruche ;
    GtkWidget* label_info_ncadre ;

    //BUTTON
    
    GtkWidget* btn_cut ;
    GtkWidget* btn_play ;
    GtkWidget* btn_av ;
    GtkWidget* btn_rec ;

    GtkWidget* btn_enr ;
    GtkWidget* btn_ann ; 


    GtkWidget* btn_an_cross ;
    GtkWidget* btn_an_circle ; 
    GtkWidget* btn_an_box ;
    GtkWidget* btn_an_arrow ;
    GtkWidget* btn_an_measure ;
    GtkWidget* btn_an_moving_cross ;
    GtkWidget* btn_an_text ;

    GtkWidget* img_btn_an_cross ;
    GtkWidget* img_btn_an_circle ; 
    GtkWidget* img_btn_an_oblong ;
    GtkWidget* img_btn_an_arrow ;
    GtkWidget* img_btn_an_measure ;
    GtkWidget* img_btn_an_moving_cross ;
    GtkWidget* img_btn_an_text ;

    GtkWidget* btn_add_tag ;
    GtkWidget* btn_remove_tag ; 
    //SEPARATOR
    GtkWidget* sep ;
    GtkWidget* sep2 ;
    GtkWidget* sep_tag1 ; 
    GtkWidget* sep_tag2 ; 

    
    //OTHER WIDGET  
    GtkWidget *barre_temps;
    GtkAdjustment *adjustement_barre_temps;
    

    
} modif_win_t ; //typedef + struct sur la même ligne

//pré déclaration des fonctions 
modif_win_t* modif_win_new() ; 
void modif_win_show( modif_win_t* ) ;
void modif_win_del( modif_win_t* ) ;

#endif
