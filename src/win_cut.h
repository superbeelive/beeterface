#ifndef CUT_WIN_H
#define CUT_WIN_H

#include <gtk/gtk.h>

typedef struct {

    GtkWidget* window ; 
    GtkWidget* box_principal ; 
    GtkWidget* box_left ; 
    GtkWidget* box_right ; 

    GtkWidget* box_video ; 
    GtkWidget* box_time ; 
    GtkWidget* box_label_time ; 
    
    GtkWidget* box_def_timed ;
    GtkWidget* box_def_timef ;
    GtkWidget* box_quit ; 
    
    GtkWidget* label_def_timed ; 
    GtkWidget* label_def_timef ;
    GtkWidget* label_timed ; 
    GtkWidget* label_timef ;

    GtkWidget* label_time_start ;
    GtkWidget* label_time_end ; 
    
    GtkWidget* btn_timed ;
    GtkWidget* btn_timef ;

    GtkWidget* btn_enr ;
    GtkWidget* btn_ann ; 

    GtkWidget* img_ex_video ; 

    GtkWidget *scale_tmp;
    GtkAdjustment *adjustement_tmp ;

} cut_win_t ; 

cut_win_t* cut_win_new() ; 
void cut_win_show ( cut_win_t* ) ; 
void cut_win_del ( cut_win_t* ) ; 

#endif
