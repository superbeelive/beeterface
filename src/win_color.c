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

    //btn
    tmp->btn_red = gtk_button_new ();
        tmp->img_btn_red =  gtk_image_new_from_file ("./images/colors/red.png");
        gtk_button_set_image (GTK_BUTTON (tmp->btn_red), tmp->img_btn_red);

    tmp->btn_blue = gtk_button_new ();
        tmp->img_btn_blue =  gtk_image_new_from_file ("./images/colors/blue.png");
        gtk_button_set_image (GTK_BUTTON (tmp->btn_blue), tmp->img_btn_blue);

    tmp->btn_green = gtk_button_new ();
        tmp->img_btn_green =  gtk_image_new_from_file ("./images/colors/green.png");
        gtk_button_set_image (GTK_BUTTON (tmp->btn_green), tmp->img_btn_green);

    tmp->btn_yellow = gtk_button_new ();
        tmp->img_btn_yellow =  gtk_image_new_from_file ("./images/colors/yellow.png");
        gtk_button_set_image (GTK_BUTTON (tmp->btn_yellow), tmp->img_btn_yellow);

    tmp->btn_pink = gtk_button_new ();
        tmp->img_btn_pink =  gtk_image_new_from_file ("./images/colors/pink.png");
        gtk_button_set_image (GTK_BUTTON (tmp->btn_pink), tmp->img_btn_pink);

    
    //RANGEMENT 
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principale);
         gtk_box_pack_start(GTK_BOX(tmp->box_principale), tmp->grid_btn, FALSE, FALSE, 0);
             gtk_grid_attach(GTK_GRID (tmp->grid_btn), tmp->btn_red, 1,1,1,1 ) ;
             gtk_grid_attach(GTK_GRID (tmp->grid_btn), tmp->btn_blue, 1,2,1,1 ) ;
             gtk_grid_attach(GTK_GRID (tmp->grid_btn), tmp->btn_green, 2,1,1,1 ) ;
             gtk_grid_attach(GTK_GRID (tmp->grid_btn), tmp->btn_yellow, 2,2,1,1 ) ;
             gtk_grid_attach(GTK_GRID (tmp->grid_btn), tmp->btn_pink, 3,1,1,1 ) ;
             //gtk_grid_attach(GTK_GRID (tmp->grid_btn), tmp->btn_red, 3,2,1,1 ) ;

    return tmp ; 
}

void color_win_show ( color_win_t* tmp ) {
    gtk_widget_show ( tmp->window ) ; 
    gtk_widget_show_all ( tmp->box_principale ) ; 
}

void color_win_del ( color_win_t* tmp ) {
    free ( tmp ) ;
}


