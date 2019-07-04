#include <stdlib.h>
#include "win_file.h"

file_win_t* file_win_new() { 

    file_win_t* tmp ; 
    tmp = malloc ( sizeof(file_win_t) ) ; 
     
   //CREATION
   tmp->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

   //box
   tmp->box_principal = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);


   //RANGEMENT
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principal);

   //PLACEMENT 
    gtk_container_set_border_width (GTK_CONTAINER (tmp->window), 10 );
    gtk_window_set_title (GTK_WINDOW (tmp->window), "Fichiers"); 



    return tmp ; 
}

void file_win_show ( file_win_t* tmp ) {

    gtk_widget_show ( tmp->window ) ; 
    gtk_widget_show_all ( tmp->box_principal ) ; 
}

void file_win_del ( file_win_t* tmp ) {
    free ( tmp ) ;
}
