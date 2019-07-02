#include <stdlib.h>
#include "win_color.h"


color_win_t* color_win_new() {
    color_win_t* tmp ; 
    tmp = malloc ( sizeof(color_win_t) ) ;
      
    
    //CREATION
    //window
    tmp->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    
    //box
    tmp->box_principale = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->grid_btn = gtk_grid_new() ; 

    //colors 
    gdk_rgba_parse (tmp->red, "#ff0000" ) ; 

    //btn
    tmp->btn_red = gtk_color_button_new_with_rgba (tmp->red) ; 
  
    //label
    tmp->label_test = gtk_label_new("test") ;
    
    //RANGEMENT 
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principale);
         gtk_box_pack_start(GTK_BOX(tmp->box_principale), tmp->grid_btn, FALSE, FALSE, 0);
             gtk_grid_attach(GTK_GRID (tmp->grid_btn), tmp->btn_red, 1,1,1,1 ) ;
         gtk_box_pack_start(GTK_BOX(tmp->box_principale), tmp->label_test, FALSE, FALSE, 0);

    return tmp ; 
}

void color_win_show ( color_win_t* tmp ) {
    gtk_widget_show ( tmp->window ) ; 
    gtk_widget_show_all ( tmp->box_principale ) ; 
}

void color_win_del ( color_win_t* tmp ) {
    free ( tmp ) ;
}


