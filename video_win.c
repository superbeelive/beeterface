#include <stdlib.h>
#include "video_win.h" 

video_win_t* video_win_new() {
    
    video_win_t* tmp ; 
    tmp = malloc ( sizeof(video_win_t) ) ; 

    //DECLARATION VARIABLES 

    //CREATION WIDGET  
    tmp->window = gtk_window_new (GTK_WINDOW_TOPLEVEL) ; 
    tmp->box_principal = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0 ) ; 
    
    //RANGEMENT 

    //AUTRE
    gtk_window_set_title ( GTK_WINDOW (tmp->window), "Vidéo") ;

    return tmp ; 
}

void video_win_show ( video_win_t* nemo ) {
    gtk_widget_show ( nemo->window ) ; 
    gtk_widget_show_all ( nemo->box_principal ) ; 
}

void video_win_del ( video_win_t* nemo ) {
    free ( nemo ) ; 
}
