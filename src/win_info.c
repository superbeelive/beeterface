#include <stdlib.h>
#include "win_info.h"

info_win_t* info_win_new() {
    info_win_t* tmp ; 
    tmp = malloc ( sizeof(info_win_t) ) ; 
    
    //CREATION
    //window
    tmp->window = gtk_window_new (GTK_WINDOW_TOPLEVEL ) ; 
    gtk_window_set_title ( GTK_WINDOW (tmp->window), "Information") ;
      
    //box
    tmp->box_principal = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0) ; 
    tmp->box_camera = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0) ; 
    tmp->box_auteur = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0) ; 
    tmp->box_ruche = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0) ; 
    //notebook
    tmp->notebook = gtk_notebook_new( ) ;
    gtk_notebook_popup_enable (GTK_NOTEBOOK(tmp->notebook));
    gtk_notebook_set_scrollable(GTK_NOTEBOOK(tmp->notebook), TRUE);
    gtk_notebook_set_tab_pos(GTK_NOTEBOOK(tmp->notebook), GTK_POS_TOP);
    gtk_notebook_append_page_menu (GTK_NOTEBOOK(tmp->notebook), tmp->box_camera, NULL, NULL ) ;
    gtk_notebook_append_page_menu (GTK_NOTEBOOK(tmp->notebook), tmp->box_auteur, NULL, NULL)  ;

    //label
    tmp->test_camera = gtk_label_new("test test \n test") ; 
    tmp->test_auteur = gtk_label_new("test test \n test") ; 

    //RANGEMENT 
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principal);
    gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->notebook,  FALSE, FALSE, 0);
    
    gtk_box_pack_start(GTK_BOX(tmp->box_camera), tmp->test_camera,  FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(tmp->box_auteur), tmp->test_auteur,  FALSE, FALSE, 0);

    //PLACEMENT
    gtk_container_set_border_width (GTK_CONTAINER(tmp->window), 10 );

    return tmp ;      
}

void info_win_show ( info_win_t* w ) {
    gtk_widget_show (w->window) ; 
    gtk_widget_show_all (w->box_principal) ; 
}

void info_win_del ( info_win_t* w ) {
    free ( w ) ;
}

