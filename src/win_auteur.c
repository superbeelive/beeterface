#include <stdlib.h>
#include "win_auteur.h"

auteur_win_t* auteur_win_new() {
    
    auteur_win_t* tmp ; 
    tmp = malloc ( sizeof(auteur_win_t) ) ;
    

    //variables 
    // Déclaration de modif... ?  
    tmp->button_modif_1 = 0 ;
    tmp->button_modif_2 = 0 ;
    tmp->button_modif_3 = 0 ;

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

    tmp->img_modify1 = gtk_image_new_from_file ("/usr/share/beeterface/images/modif.png") ; 
    tmp->img_modify_ok1 = gtk_image_new_from_file ("/usr/share/beeterface/images/ok.png") ; 
    tmp->button_modify1 = gtk_button_new() ; 
    gtk_button_set_image (GTK_BUTTON (tmp->button_modify1), tmp->img_modify1) ; 

    g_object_ref (tmp->img_modify1);
    g_object_ref (tmp->img_modify_ok1);
    

    tmp->img_modify2 = gtk_image_new_from_file ("/usr/share/beeterface/images/modif.png") ; 
    tmp->img_modify_ok2 = gtk_image_new_from_file ("/usr/share/beeterface/images/ok.png") ; 
    tmp->button_modify2 = gtk_button_new() ; 
    gtk_button_set_image (GTK_BUTTON (tmp->button_modify2), tmp->img_modify2) ; 

    g_object_ref (tmp->img_modify2);
    g_object_ref (tmp->img_modify_ok2);


    tmp->img_modify3 = gtk_image_new_from_file ("/usr/share/beeterface/images/modif.png") ; 
    tmp->img_modify_ok3 = gtk_image_new_from_file ("/usr/share/beeterface/images/ok.png") ; 
    tmp->button_modify3 = gtk_button_new() ; 
    gtk_button_set_image (GTK_BUTTON (tmp->button_modify3), tmp->img_modify3) ; 

    g_object_ref (tmp->img_modify3);
    g_object_ref (tmp->img_modify_ok3);
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
            

        
//PLACEMENT
        //Window
        gtk_window_set_title ( GTK_WINDOW (tmp->window), "Auteur") ;
        gtk_window_set_default_size ( GTK_WINDOW (tmp->window), 30, 30 ) ; 
        gtk_window_unmaximize (GTK_WINDOW (tmp->window));
        gtk_container_set_border_width (GTK_CONTAINER (tmp->window), 10 );

        //Text
        gtk_widget_set_halign ( GTK_WIDGET (tmp->label_name), GTK_ALIGN_START ) ;
        gtk_widget_set_halign ( GTK_WIDGET (tmp->label_first_name), GTK_ALIGN_START ) ;
        gtk_widget_set_halign ( GTK_WIDGET (tmp->label_email), GTK_ALIGN_START ) ;

        gtk_widget_set_margin_end (GTK_WIDGET (tmp->label_name), 10 ) ;
        gtk_widget_set_margin_end (GTK_WIDGET (tmp->label_first_name), 10 ) ;
        gtk_widget_set_margin_end (GTK_WIDGET (tmp->label_email), 10 ) ;

        gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->label_title), 10) ; 
    return tmp ;
}


void auteur_win_show ( auteur_win_t* tmp ) {
    //AFFICHER
    gtk_widget_show ( tmp->window ) ; 
    gtk_widget_show_all ( tmp->box_principal ) ;
}

void auteur_win_del ( auteur_win_t* w ) {
    
    g_object_unref (w->img_modify1);
    g_object_unref (w->img_modify_ok1);

    g_object_unref (w->img_modify2);
    g_object_unref (w->img_modify_ok2);

    g_object_unref (w->img_modify3);
    g_object_unref (w->img_modify_ok3);

    free ( w ) ;
}


