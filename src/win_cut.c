#include <stdlib.h>
#include "win_cut.h"

cut_win_t* cut_win_new() { 

    cut_win_t* tmp ; 
    tmp = malloc ( sizeof(cut_win_t) ) ; 
     
   //CREATION
   tmp->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

   //box
   tmp->box_principal = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);


   //RANGEMENT
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principal);

   //PLACEMENT 
    gtk_container_set_border_width (GTK_CONTAINER (tmp->window), 10 );
    gtk_window_set_title (GTK_WINDOW (tmp->window), "Couper"); 


    return tmp ; 
}

void cut_win_show ( cut_win_t* tmp ) {

    gtk_widget_show ( tmp->window ) ; 
    gtk_widget_show_all ( tmp->box_principal ) ; 
}

void cut_win_del ( cut_win_t* tmp ) {
    free ( tmp ) ;
}
