#include <stdlib.h>
#include "win_create_tag.h"

create_tag_win_t* create_tag_win_new() { 

    create_tag_win_t* tmp ; 
    tmp = malloc ( sizeof(create_tag_win_t) ) ; 
     
   //CREATION
   tmp->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

   //box
   tmp->box_principal = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
   tmp->box_entry = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
   tmp->box_btn_quit = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);

   tmp->entry_tag = gtk_entry_new() ;

   tmp->btn_add_tag = gtk_button_new_with_label ("Ajouter") ; 
   tmp->btn_ann = gtk_button_new_with_label ("Annuler") ; 
   tmp->btn_enr = gtk_button_new_with_label ("Enregistrer") ; 

   //RANGEMENT
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principal);

   //PLACEMENT 
    gtk_container_set_border_width (GTK_CONTAINER (tmp->window), 10 );
    gtk_window_set_title (GTK_WINDOW (tmp->window), "Créer un Tag"); 
    
    gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->box_entry,  FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->box_btn_quit,  FALSE, FALSE, 0);
        
        gtk_box_pack_start(GTK_BOX(tmp->box_entry), tmp->entry_tag,  FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_entry), tmp->btn_add_tag,  FALSE, FALSE, 0);

        gtk_box_pack_start(GTK_BOX(tmp->box_btn_quit), tmp->btn_ann,  FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_btn_quit), tmp->btn_enr,  FALSE, FALSE, 0);

    gtk_window_set_default_size ( GTK_WINDOW (tmp->window), 10, 10 ) ; 
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->box_btn_quit), 5) ; 
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->entry_tag), 2) ; 

    gtk_widget_set_halign ( GTK_WIDGET (tmp->box_btn_quit), GTK_ALIGN_END ) ; 
    gtk_widget_set_valign ( GTK_WIDGET (tmp->box_btn_quit), GTK_ALIGN_END ) ; 

    return tmp ; 
}

void create_tag_win_show ( create_tag_win_t* tmp ) {

    gtk_widget_show ( tmp->window ) ; 
    gtk_widget_show_all ( tmp->box_principal ) ; 
}

void create_tag_win_del ( create_tag_win_t* tmp ) {
    free ( tmp ) ;
}
