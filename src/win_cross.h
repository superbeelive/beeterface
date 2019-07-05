#ifndef WIN_CROSS_H
#define WIN_CROSS_H

#include <gtk/gtk.h>

typedef struct {
    
    GtkWidget* window ; 
    GtkWidget* box_principal ; 
    
    GtkWidget* box_left ;
    GtkWidget* box_right ; 
    
    GtkWidget* box_description ;
    GtkWidget* box_video ; 
    GtkWidget* box_time ; 
    GtkWidget* box_label_time ; 
    GtkWidget* box_btn_video ; 
    GtkWidget* box_def_time_deb ; 
    GtkWidget* box_def_time_fin ; 

    GtkWidget* box_name ;
    GtkWidget* box_tag ; 
    GtkWidget* box_btn_tag ; 
    GtkWidget* box_txt_tag ;
    GtkWidget* box_txt_ss_tag1 ;
    GtkWidget* box_txt_ss_tag2 ;
    GtkWidget* box_scroll_tag ; 
    GtkWidget* box_meta ; 
    GtkWidget* box_text_meta ; 
    GtkWidget* box_btn_quit ;
    
    //frame
    GtkWidget* frame_tag ; 
    GtkWidget* frame_meta ; 

    //scroll
    GtkWidget* scroll_tag ;

    //GRID 
    GtkWidget* grid_meta ; 
    //IMG
    GtkWidget* img_ex_video ; 

    //LABEL
    GtkWidget* label_name ; 
    GtkWidget* label_desc ;
    GtkWidget* label_time_deb ; 
    GtkWidget* label_time_fin ;

    GtkWidget* label_title_tag ; 
    GtkWidget* label_test ;
    GtkWidget* label_test2 ;
    GtkWidget* label_test3 ;

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

    GtkWidget* label_enr_timed ; 
    GtkWidget* label_enr_timef ; 
    GtkWidget* label_timed ;
    GtkWidget* label_timef ;

    //ENTRY 
    GtkWidget* entry_name ; 

    //BTN
    GtkWidget* btn_name ; 
    GtkWidget* img_btn_ok_name ;
    GtkWidget* img_btn_mod_name ;

    GtkWidget* btn_cut ;
    GtkWidget* btn_play ;
    GtkWidget* btn_av ;
    GtkWidget* btn_rec ;

    GtkWidget* btn_enr ;
    GtkWidget* btn_ann ; 
    
    GtkWidget* btn_enr_timed ;
    GtkWidget* btn_enr_timef ;
    
    GtkWidget* btn_add_tag ; 
    GtkWidget* btn_remove_tag ;

    GtkWidget* btn_note ; 
    //OTHER
    GtkTextBuffer* buffer_description ; 
    GtkWidget* text_description ;

    GtkWidget* scale_time ; 
    GtkAdjustment* adj_time ;

    //sep
    GtkWidget* sep ;
    GtkWidget* sep2 ;
    GtkWidget* sep3 ;

} cross_win_t ;

cross_win_t* cross_win_new () ; 
void cross_win_show ( cross_win_t* ) ;
void cross_win_del ( cross_win_t* ) ; 

#endif 
