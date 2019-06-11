#ifndef CAMERA_WIN_H
#define CAMERA_WIN_H 

#include <gtk/gtk.h>

#include "camera.h" 


typedef struct {

    GtkWidget *window ; 
    GtkWidget *box_principal ; 

    GtkWidget *box_up ; 
    GtkWidget *box_down ; 
    GtkWidget *box_left ; 
    GtkWidget *box_middle ; 
    GtkWidget *box_right ;
    
    GtkWidget *label_title ; 
    GtkWidget *label_name ;
    GtkWidget *label_model ; 
    GtkWidget *label_nserie ; 
    GtkWidget *label_type ;
    GtkWidget *label_description ;
    
    GtkWidget *entry_name ;
    GtkWidget *entry_model ; 
    GtkWidget *entry_nserie ; 
    GtkWidget *entry_type ;
    GtkWidget *entry_description ;

    GtkWidget *img_btn_modify_name_modif ;
    GtkWidget *img_btn_modify_name_ok ; 
    GtkWidget *btn_modify_name ;

    GtkWidget *img_btn_modify_model_modif ;
    GtkWidget *img_btn_modify_model_ok ; 
    GtkWidget *btn_modify_model ;
    
    GtkWidget *img_btn_modify_nserie_modif ;
    GtkWidget *img_btn_modify_nserie_ok ; 
    GtkWidget *btn_modify_nserie ;
    
    GtkWidget *img_btn_modify_type_modif ;
    GtkWidget *img_btn_modify_type_ok ; 
    GtkWidget *btn_modify_type ;
    
    GtkWidget *img_btn_modify_description_modif ;
    GtkWidget *img_btn_modify_description_ok ; 
    GtkWidget *btn_modify_description ;
   
    int cnt_modif_name ; 
    int cnt_modif_model ; 
    int cnt_modif_nserie ; 
    int cnt_modif_type ; 
    int cnt_modif_description ; 

    
} camera_win_t ;

//win_camera.c
camera_win_t* camera_win_new() ; 
void camera_win_del ( camera_win_t* ) ; 
void camera_win_show ( camera_win_t* ) ;

//win_callback_camera.c
void camera_win_fill( camera_win_t*, camera_t* ) ; 
void camera_button_modify_name_modif( camera_win_t* win, camera_t* camera ) ; 
void camera_button_modify_name_ok ( camera_win_t* win, camera_t* auteur ) ;

void camera_button_modify_model_modif( camera_win_t* win, camera_t* camera ) ; 
void camera_button_modify_model_ok ( camera_win_t* win, camera_t* auteur ) ;

void camera_button_modify_nserie_modif( camera_win_t* win, camera_t* camera ) ; 
void camera_button_modify_nserie_ok ( camera_win_t* win, camera_t* auteur ) ;

void camera_button_modify_type_modif( camera_win_t* win, camera_t* camera ) ; 
void camera_button_modify_type_ok ( camera_win_t* win, camera_t* auteur ) ;

void camera_button_modify_description_modif( camera_win_t* win, camera_t* camera ) ; 
void camera_button_modify_description_ok ( camera_win_t* win, camera_t* auteur ) ;

#endif
