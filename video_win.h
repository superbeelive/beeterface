#ifndef VIDEO_WIN_H
#define VIDEO_WIN_H 

#include <gtk/gtk.h>

#include "video.h" 


typedef struct {

    GtkWidget *window ; 
    GtkWidget *box_principal ; 
    
    GtkWidget *box_up ; 
    GtkWidget *box_down ; 
    GtkWidget *box_left ; 
    GtkWidget *box_middle ; 
    GtkWidget *box_right ;

    GtkWidget *label_name_video ; 

    GtkWidget *label_name_ruche ; 
    GtkWidget *label_n_ruche ; 
    GtkWidget *label_n_cadre ;
    GtkWidget *label_description ;
    GtkWidget *label_date ; 
    GtkWidget *label_auteur ; 
    GtkWidget *label_camera ; 


    GtkWidget *entry_name_ruche ; 
    GtkWidget *entry_n_ruche ; 
    GtkWidget *entry_n_cadre ;
    GtkWidget *entry_description ;
    GtkWidget *entry_date ; 
    GtkWidget *entry_auteur ; 
    GtkWidget *entry_camera ; 


    GtkWidget *img_btn_modify_name_ruche_modif ;
    GtkWidget *img_btn_modify_name_ruche_ok ; 
    GtkWidget *btn_modify_name_ruche ;

    GtkWidget *img_btn_modify_n_ruche_modif ;
    GtkWidget *img_btn_modify_n_ruche_ok ; 
    GtkWidget *btn_modify_n_ruche ;

    GtkWidget *img_btn_modify_n_cadre_modif ;
    GtkWidget *img_btn_modify_n_cadre_ok ; 
    GtkWidget *btn_modify_n_cadre ;

    GtkWidget *img_btn_modify_description_modif ;
    GtkWidget *img_btn_modify_description_ok ; 
    GtkWidget *btn_modify_description ;

    int cnt_modif_name_ruche ; 
    int cnt_modif_n_ruche ; 
    int cnt_modif_n_cadre ; 
    int cnt_modif_description ; 


} video_win_t ;

//win_auteur.c
video_win_t* video_win_new() ; 
void video_win_del ( video_win_t* ) ; 
void video_win_show ( video_win_t* ) ;
void video_win_fill( video_win_t*, video_t*) ; 
void video_button_modify_name_ruche_modif( video_win_t* win, video_t* video ) ; 
void video_button_modify_name_ruche_ok( video_win_t* win, video_t* video ) ; 

void video_button_modify_n_ruche_modif( video_win_t* win, video_t* video ) ; 
void video_button_modify_n_ruche_ok( video_win_t* win, video_t* video ) ; 

void video_button_modify_n_cadre_modif( video_win_t* win, video_t* video ) ; 
void video_button_modify_n_cadre_ok( video_win_t* win, video_t* video ) ; 

void video_button_modify_description_modif( video_win_t* win, video_t* video ) ; 
void video_button_modify_description_ok( video_win_t* win, video_t* video ) ; 

#endif
