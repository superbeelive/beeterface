#ifndef AUTEUR_WIN_H 
#define AUTEUR_WIN_H

#include <gtk/gtk.h>
#include "author.h"

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
    GtkWidget *label_first_name ; 
    GtkWidget *label_email ;

    GtkWidget *entry_name ; 
    GtkWidget *entry_first_name ; 
    GtkWidget *entry_email ;

    GtkWidget *button_modify1 ; 
    GtkWidget *button_modify2 ; 
    GtkWidget *button_modify3 ; 
    
    GtkWidget *img_modify1 ; 
    GtkWidget *img_modify2 ; 
    GtkWidget *img_modify3 ; 

    GtkWidget *img_modify_ok1 ;
    GtkWidget *img_modify_ok2 ;
    GtkWidget *img_modify_ok3 ;



    GtkWidget *label_test ;

    int button_modif_1 ;
    int button_modif_2 ;
    int button_modif_3 ;
    
    
  } auteur_win_t ; 
//win_auteur.c
auteur_win_t* auteur_win_new() ; 
void auteur_win_del ( auteur_win_t* ) ; 
void auteur_win_show ( auteur_win_t* ) ;

//win_callback_auteur.c
void auteur_win_fill( auteur_win_t* win, author_t* auteur ) ;
void auteur_button_modify_name( auteur_win_t* win, author_t* auteur );
void auteur_button_modify_ok_name( auteur_win_t* win, author_t* auteur );
void auteur_button_modify_first_name( auteur_win_t* win, author_t* auteur ) ;
void auteur_button_modify_ok_first_name ( auteur_win_t* win, author_t* auteur ) ; 
void auteur_button_modify_email( auteur_win_t* win, author_t* auteur ) ; 
void auteur_button_modify_ok_email ( auteur_win_t* win, author_t* auteur ) ;      
#endif 
