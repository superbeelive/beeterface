#include <stdlib.h>
#include "camera_win.h" 

camera_win_t* camera_win_new() {
    
    camera_win_t* tmp ; 
    tmp = malloc ( sizeof(camera_win_t) ) ; 

    //DECLARATION VARIABLES 

    //CREATION WIDGET  
    tmp->window = gtk_window_new (GTK_WINDOW_TOPLEVEL) ; 
    tmp->box_principal = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0 ) ; 
    
    //RANGEMENT 

    //AUTRE
    gtk_window_set_title ( GTK_WINDOW (tmp->window), "Camera") ;

    return tmp ; 
}

void camera_win_show ( camera_win_t* nemo ) {
    gtk_widget_show ( nemo->window ) ; 
    gtk_widget_show_all ( nemo->box_principal ) ; 
}

void camera_win_del ( camera_win_t* nemo ) {
    free ( nemo ) ; 
}
