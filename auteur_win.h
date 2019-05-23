#ifndef AUTEUR_WIN_H 
#define AUTEUR_WIN_H

#include <gtk/gtk.h>

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
    
  } auteur_win_t ; 

auteur_win_t* auteur_win_new() ; 
void auteur_win_del ( auteur_win_t* ) ; 
void auteur_win_show ( auteur_win_t* ) ;

#endif 
