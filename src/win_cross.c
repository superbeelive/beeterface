#include <stdlib.h>
#include "win_cross.h" 

cross_win_t* cross_win_new() {
    cross_win_t* tmp ;
    tmp = malloc ( sizeof(cross_win_t) ) ;
   
    //CREATION
    tmp->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    tmp->box_principal = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    
    tmp->box_left = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_right = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    
    tmp->box_name = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_description = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_time = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_label_time = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_btn_video = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_def_time_deb = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_def_time_fin = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    
    tmp->box_tag = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_info = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_btn_quit = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    
    
    //RANGEMENT 
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principal);

    gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->box_left, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->box_right, FALSE, FALSE, 0);

        //box_left
        gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_name, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_description, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_time, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_label_time, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_btn_video, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_def_time_deb, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_def_time_fin, FALSE, FALSE, 0);
   
        //box_right
        gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_tag, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_info, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_btn_quit, FALSE, FALSE, 0);


    //PLACEMENT 
    gtk_window_set_title (GTK_WINDOW (tmp->window), "Annotation : croix") ; 
    gtk_container_set_border_width (GTK_CONTAINER (tmp->window), 10 );



    return tmp ; 
}

void cross_win_show ( cross_win_t* tmp ) {
    gtk_widget_show ( tmp->window ) ;
    gtk_widget_show_all ( tmp->box_principal ) ; 
}

void cross_win_del ( cross_win_t* tmp ) { 
    free ( tmp ) ; 
}
