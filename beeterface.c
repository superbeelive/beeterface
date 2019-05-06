#include <stdlib.h>

#include "main_win.h"
#include "modif_win.h"

void destroy (GtkWidget *widget, gpointer data)
{
     gtk_main_quit ();
}        

void modif (GtkWidget *widget, gpointer data)
{
    modif_win_show( data ) ;
}

int main (int argc, char *argv[])
{

//DECLARATIONS

    main_win_t*  fenetre ;
    modif_win_t* fenetre_modif ;
    
    gtk_init (&argc, &argv);

    fenetre = main_win_new() ;
    fenetre_modif = modif_win_new() ;

    main_win_show( fenetre ) ;

//FONCTIONS 
    g_signal_connect (fenetre->button_quit, "clicked", G_CALLBACK(destroy),NULL);
    g_signal_connect (fenetre->button_enregistrer, "clicked", G_CALLBACK(modif), fenetre_modif);

//AFFICHAGE 
  gtk_main ();

  
  
  main_win_del( fenetre ) ;
  
  return 0;

}
