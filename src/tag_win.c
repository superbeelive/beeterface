#include <stdlib.h>
#include "tag_win.h"


tag_win_t* tag_win_new() {
    
    tag_win_t* tmp ; 
    tmp = malloc ( sizeof(tag_win_t) ) ; 
    
    //DECLARATION DES VARIABLES 
    tmp->cnt_edit = 0 ;

    //CREATION WIDGET / CONTAINER 
    //Window Definition
    tmp->window = gtk_window_new (GTK_WINDOW_TOPLEVEL) ; 
   
    gtk_window_set_title ( GTK_WINDOW (tmp->window), "Tag") ;
    gtk_window_set_default_size ( GTK_WINDOW (tmp->window), 50, 70 ) ; 
    gtk_window_unmaximize (GTK_WINDOW (tmp->window));
    gtk_container_set_border_width (GTK_CONTAINER (tmp->window), 10 );
    
    tmp->box_principal = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0 ) ; 
    tmp->box_up = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0 ) ; 
    tmp->box_down = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0 ) ; 
   
    //Widget box up
    tmp->search = gtk_search_entry_new() ; 

    tmp->entry_edit = gtk_entry_new() ; 
    tmp->btn_edit = gtk_button_new() ; 
    tmp->img_btn_edit_modif = gtk_image_new_from_file ("/usr/share/beeterface/images/modif.png") ; 
    tmp->img_btn_edit_ok = gtk_image_new_from_file ("/usr/share/beeterface/images/ok.png") ; 
    gtk_button_set_image (GTK_BUTTON (tmp->btn_edit), tmp->img_btn_edit_modif ) ; 


    g_object_ref (tmp->img_btn_edit_modif) ; 
    g_object_ref (tmp->img_btn_edit_ok) ; 

    //Widget box down
    
    tmp->scroll = gtk_scrolled_window_new (NULL, NULL) ; 
    tmp->label_test = gtk_label_new ("Je suis un test de texte bonjour.\ntest \ntest \ntest \ntest") ; 


    //RANGEMENT
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principal) ; 
        //Box Principale
        gtk_box_pack_start (GTK_BOX(tmp->box_principal), tmp->box_up, FALSE, FALSE, 0);
        gtk_box_pack_start (GTK_BOX(tmp->box_principal), tmp->box_down, TRUE, TRUE, 0);
        
            //Box_up 
            gtk_box_pack_start (GTK_BOX(tmp->box_up), tmp->search, FALSE, FALSE, 0);
            gtk_box_pack_start (GTK_BOX(tmp->box_up), tmp->entry_edit, FALSE, FALSE, 0);
            gtk_box_pack_start (GTK_BOX(tmp->box_up), tmp->btn_edit, FALSE, FALSE, 0);
        
            //Box_Down
            gtk_box_pack_start (GTK_BOX(tmp->box_down), tmp->scroll, TRUE, TRUE, 0);
                //Dans scroll
                gtk_container_add (GTK_CONTAINER(tmp->scroll), tmp->label_test) ;

    //PLACEMENT 
    gtk_widget_set_margin_end ( GTK_WIDGET (tmp->search), 100 ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_test), GTK_ALIGN_START ) ;
    gtk_widget_set_margin_top ( GTK_WIDGET (tmp->scroll), 10 ) ;
        return tmp ; 
}

void tag_win_show ( tag_win_t* nemo ) {
    gtk_widget_show ( nemo->window ) ; 
    gtk_widget_show_all ( nemo->box_principal ) ; 
}


void tag_win_del ( tag_win_t* nemo ) {
    free ( nemo ) ;
    g_object_unref (nemo->img_btn_edit_modif) ; 
    g_object_unref (nemo->img_btn_edit_ok) ; 

}

