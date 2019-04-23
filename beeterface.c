#include <gtk/gtk.h>

void destroy (GtkWidget *widget, gpointer data)
{
     gtk_main_quit ();
}        



int main (int argc, char *argv[])
{

//Declarations 

    GtkWidget *window; //Fenêtre d'acceuil 
    GtkWidget *box_principal; //Boite principale contenant les autres boites 
    GtkWidget *button_quit; //Bouton quitter 
    GtkWidget *box_up; //Boite la plus haute 


    gtk_init (&argc, &argv);
    
    //Creation de la fenêtre principale 
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    box_principal = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    button_quit = gtk_button_new (); //Definition sur deux lignes  
    gtk_button_set_label ((GtkButton*)button_quit,"Quitter"); 
    box_up = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);



//Rangement des boxs & Widgets 
    
    //Boite PRINCIPALE 
    gtk_container_add (GTK_CONTAINER (window), box_principal);
        //Dans la boite principale :
        gtk_box_pack_start(GTK_BOX(box_principal), box_up, TRUE, TRUE, 0);
        //Dans box_up
        gtk_box_pack_start(GTK_BOX(box_up), button_quit, FALSE, FALSE, 0);

//Fonctions liees
    g_signal_connect (button_quit, "clicked", G_CALLBACK(destroy),NULL);

//Autre 


//Affichage 
   
    gtk_widget_show (box_principal);
    gtk_widget_show (box_up);


    gtk_widget_show (button_quit);

    gtk_widget_show (window);


  gtk_main ();
    return 0;

}
