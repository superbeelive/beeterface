#include <stdlib.h>
#include "win_file.h"

file_win_t* file_win_new() { 

    file_win_t* tmp ; 
    tmp = malloc ( sizeof(file_win_t) ) ; 
     
   //CREATION
   tmp->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

   //box
   tmp->box_principal = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
   
   tmp->box_up = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
   tmp->box_middle = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
   tmp->box_down = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0) ;

   //scroll
   tmp->scroll_tag = gtk_scrolled_window_new (NULL, NULL) ; 

   //label
   tmp->label_tri = gtk_label_new("Trier par") ;
   tmp->label_tag = gtk_label_new("test \n test \n test") ;

   //combo
   tmp->combo_tri = gtk_combo_box_text_new() ;
   gtk_combo_box_text_insert_text ((GtkComboBoxText*) tmp->combo_tri, 1,"Ruche") ;
   gtk_combo_box_text_insert_text ((GtkComboBoxText*) tmp->combo_tri, 2,"Camera") ;
   gtk_combo_box_text_insert_text ((GtkComboBoxText*) tmp->combo_tri, 3,"Auteur") ; 
   gtk_combo_box_text_insert_text ((GtkComboBoxText*) tmp->combo_tri, 4,"Date") ; 
   gtk_combo_box_text_insert_text ((GtkComboBoxText*) tmp->combo_tri, 5,"Tag") ;
   
   //search
   tmp->search_tri = gtk_search_entry_new() ; 

   //btn
   tmp->btn_quit = gtk_button_new_with_label ("Quitter");
   tmp->btn_open = gtk_button_new_with_label ("Ouvrir");


   //RANGEMENT
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principal) ;
  
        gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->box_up, FALSE, FALSE, 0) ;
        gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->box_middle, FALSE, FALSE, 0) ;
        gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->box_down, FALSE, FALSE, 0) ;

            gtk_box_pack_start(GTK_BOX(tmp->box_up), tmp->label_tri, FALSE, FALSE, 0) ;
            gtk_box_pack_start(GTK_BOX(tmp->box_up), tmp->combo_tri, FALSE, FALSE, 0) ;
            gtk_box_pack_start(GTK_BOX(tmp->box_up), tmp->search_tri, FALSE, FALSE, 0) ;

            gtk_box_pack_start(GTK_BOX(tmp->box_middle), tmp->scroll_tag, TRUE, TRUE, 0) ;
                 gtk_container_add (GTK_CONTAINER (tmp->scroll_tag), tmp->label_tag) ;

            gtk_box_pack_start(GTK_BOX(tmp->box_down), tmp->btn_quit, FALSE, FALSE, 0) ;
            gtk_box_pack_start(GTK_BOX(tmp->box_down), tmp->btn_open, FALSE, FALSE, 0) ;
        

   //PLACEMENT 
    gtk_container_set_border_width (GTK_CONTAINER (tmp->window), 10 ) ;
    gtk_window_set_title (GTK_WINDOW (tmp->window), "Fichiers") ; 
    gtk_window_set_default_size ( GTK_WINDOW (tmp->window), 30, 30 ) ; 

    //tri
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->label_tri), 5) ; 
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->combo_tri), 5) ; 
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->search_tri), 5) ; 
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_tag), GTK_ALIGN_START ) ;

    //tag
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->scroll_tag), 5) ; 

    //btn
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->box_down), 5) ; 
    gtk_widget_set_margin_start (GTK_WIDGET (tmp->btn_quit), 200) ; 

    
    return tmp ; 
}

void file_win_show ( file_win_t* tmp ) {

    gtk_widget_show ( tmp->window ) ; 
    gtk_widget_show_all ( tmp->box_principal ) ; 
}

void file_win_del ( file_win_t* tmp ) {
    free ( tmp ) ;
}
