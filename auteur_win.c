#include <stdlib.h>
#include "auteur_win.h"

auteur_win_t* auteur_win_new() {

    auteur_win_t* tmp ; 
    tmp = malloc ( sizeof(auteur_win_t) ) ;

//CREATION
    tmp->window = gtk_window_new (GTK_WINDOW_TOPLEVEL) ;

    tmp->box_principal = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0) ;
    tmp->box_up = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0) ;
    tmp->box_down = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0) ; 
    tmp->box_left = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0) ;
    tmp->box_middle = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0) ;
    tmp->box_right = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0) ;
    
    tmp->label_title = gtk_label_new ("Auteur") ;
    tmp->label_name = gtk_label_new ("Nom") ;
    tmp->label_first_name = gtk_label_new ("Prénom") ;
    tmp->label_email = gtk_label_new ("Email") ;

    tmp->entry_name = gtk_entry_new() ; 
    tmp->entry_first_name = gtk_entry_new() ; 
    tmp->entry_email = gtk_entry_new() ; 

    tmp->img_modify1 = gtk_image_new_from_file ("images/modif.png") ; 
    tmp->button_modify1 = gtk_button_new() ; 
    gtk_button_set_image (GTK_BUTTON (tmp->button_modify1), tmp->img_modify1) ; 

    tmp->img_modify2 = gtk_image_new_from_file ("images/modif.png") ; 
    tmp->button_modify2 = gtk_button_new() ; 
    gtk_button_set_image (GTK_BUTTON (tmp->button_modify2), tmp->img_modify2) ; 

    tmp->img_modify3 = gtk_image_new_from_file ("images/modif.png") ; 
    tmp->button_modify3 = gtk_button_new() ; 
    gtk_button_set_image (GTK_BUTTON (tmp->button_modify3), tmp->img_modify3) ; 

//RANGEMENT 
    //WINDOW 
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principal) ; 
    //BOX_PRINCIPAL
    gtk_box_pack_start (GTK_BOX(tmp->box_principal), tmp->box_up, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX(tmp->box_principal), tmp->box_down, TRUE, TRUE, 0);
        //BOX_UP
        gtk_box_pack_start (GTK_BOX(tmp->box_up), tmp->label_title, TRUE, TRUE, 0) ;
        //BOX_DOWN
        gtk_box_pack_start (GTK_BOX(tmp->box_down), tmp->box_left, TRUE, TRUE, 0) ;
        gtk_box_pack_start (GTK_BOX(tmp->box_down), tmp->box_middle, TRUE, TRUE, 0) ; 
        gtk_box_pack_start (GTK_BOX(tmp->box_down), tmp->box_right, TRUE, TRUE, 0) ; 
            //BOX LEFT 
            gtk_box_pack_start (GTK_BOX(tmp->box_left), tmp->label_name, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_left), tmp->label_first_name, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_left), tmp->label_email, TRUE, TRUE, 0) ; 
            //BOX MIDDLE 
            gtk_box_pack_start (GTK_BOX(tmp->box_middle), tmp->entry_name, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_middle), tmp->entry_first_name, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_middle), tmp->entry_email, TRUE, TRUE, 0) ; 
            //BOX RIGHT
            gtk_box_pack_start (GTK_BOX(tmp->box_right), tmp->button_modify1, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_right), tmp->button_modify2, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_right), tmp->button_modify3, TRUE, TRUE, 0) ; 
            

        
//AUTRE
        gtk_window_set_title ( GTK_WINDOW (tmp->window), "Auteur") ;

    return tmp ;
}


void auteur_win_show ( auteur_win_t* tmp ) {
    //AFFICHER
    gtk_widget_show ( tmp->window ) ; 
    gtk_widget_show_all ( tmp->box_principal ) ;
}

void auteur_win_del ( auteur_win_t* w ) {
    free ( w ) ;
}

