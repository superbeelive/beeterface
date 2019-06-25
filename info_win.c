#include <stdlib.h>
#include "info_win.h"

info_win_t* info_win_new() {
    info_win_t* tmp ; 
    tmp = malloc ( sizeof(info_win_t) ) ; 
    
    //CREATION
    //window
    tmp->window = gtk_window_new (GTK_WINDOW_TOPLEVEL ) ; 
    gtk_window_set_title ( GTK_WINDOW (tmp->window), "Information") ;
    //gtk_container_set_border_width (GTK_CONTAINER (tmp->box_principal), 10 );
    
    //box
    tmp->box_principal = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0) ; 
    tmp->box_text = gtk_box_new ( GTK_ORIENTATION_VERTICAL, 0 ) ; 
    
    //label
    tmp->label_title = gtk_label_new("Informations") ; 
    
    //RANGEMENT 
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principal);
        //Box_principale
        gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->box_text, FALSE, FALSE, 0);
        //gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->label_title, FALSE, FALSE, 0);
            //Box_text
            //gtk_box_pack_start(GTK_BOX(tmp->box_text), tmp->label_title, FALSE, FALSE, 0);
            
    return tmp ;      
}

void info_win_show ( info_win_t* w ) {
    gtk_widget_show (w->window) ; 
    gtk_widget_show (w->box_principal) ; 
}

void info_win_del ( info_win_t* w ) {
    free ( w ) ;
}

