#include <gtk/gtk.h>

void destroy (GtkWidget *widget, gpointer data)
{
     gtk_main_quit ();
}        



int main (int argc, char *argv[])
{

//DECLARATIONS

    GtkWidget *window; //Fenêtre d'acceuil 
    GtkWidget *box_principal; //Boite principale contenant les autres boites 
    GtkWidget *button_quit; //Bouton quitter 
    GtkWidget *box_up; //Boite la plus haute 
    GtkWidget *box_all; //Reste de la zone 
    GtkWidget *image_exemple; //Image pour repérer où sera la vidéo
    GtkWidget *box_menu_droit; //Boite pour la droite de la vidéo
    GtkWidget *sep; //Separateur vertical  entre image et selecteur fichier
    GtkWidget *fichiers; 

    gtk_init (&argc, &argv);

//CREATION    
    //Fenêtre principale 
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    //BOITES 
    box_principal = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    box_up = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    box_all = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    box_menu_droit = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    
    //BOUTONS
    button_quit = gtk_button_new (); //Definition sur deux lignes  
    gtk_button_set_label ((GtkButton*)button_quit,"Quitter"); 

    //IMAGES  
    image_exemple = gtk_image_new_from_file ("images/bee.jpg");

    //AUTRES 
    fichiers = gtk_places_sidebar_new ();
    sep = gtk_separator_new(GTK_ORIENTATION_VERTICAL);


//Rangement des boxs & Widgets 
    
    //Boite PRINCIPALE 
    gtk_container_add (GTK_CONTAINER (window), box_principal);
        //Dans la boite principale :
        gtk_box_pack_start(GTK_BOX(box_principal), box_up, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box_principal), box_all, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box_principal), box_menu_droit, TRUE, TRUE, 0);

            //Dans box_up
            gtk_box_pack_start(GTK_BOX(box_up), button_quit, FALSE, FALSE, 0);
       
            //Dans box_all
            gtk_box_pack_start(GTK_BOX(box_all), image_exemple, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(box_all), sep, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(box_all), fichiers, FALSE, FALSE, 0);


//FONCTIONS 
    g_signal_connect (button_quit, "clicked", G_CALLBACK(destroy),NULL);

//AUTRE 
    gtk_window_set_title (GTK_WINDOW (window), "BEETERFACE"); //Nomme la fenêtre 



//AFFICHAGE 
  
    //BOX
    gtk_widget_show (box_principal);
    gtk_widget_show (box_up);
    gtk_widget_show (box_all);
    gtk_widget_show (box_menu_droit);
    
    //BUTTONS
    gtk_widget_show (button_quit);
    
    //IMAGE
    gtk_widget_show (image_exemple);

    //AUTRE
    gtk_widget_show (sep);
    gtk_widget_show (fichiers);


    //FENETRE
    gtk_widget_show (window);


  gtk_main ();
    return 0;

}
