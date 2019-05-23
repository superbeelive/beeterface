#include <stdlib.h>

#include "beeterface.h"

void destroy (GtkWidget *widget, gpointer data)
{
     gtk_main_quit ();
}        

void modif (GtkWidget *widget, gpointer data)
{
    modif_win_show( data ) ;
}

void auteur (GtkWidget *widget, gpointer data)
{
    auteur_win_show(data) ; 
}

void click_modify (){
}



int main (int argc, char *argv[])
{


//DECLARATION FENETRES 
    main_win_t*  win_main ;
    modif_win_t* win_modif ;
    auteur_win_t* win_auteur ; 
    
//DECLARATION OBJETS 
    projet_t* bidule ; 
    auteur_t* auteur ; 

    gtk_init (&argc, &argv);

//DEFINITION DES FENETRES  
    win_main = main_win_new() ;
    win_modif = modif_win_new() ;
    win_auteur = auteur_win_new() ; 

//DEFINITION DES OBJETS
    bidule = projet_new() ; 
    auteur = auteur_new() ; 
 
//EMBALLAGE PAPIER KDO
    bidule->auteur = auteur ; 

auteur_win_fill( win_auteur, auteur ) ;

//Affichage de la fenêtre principale 
    main_win_show( win_main ) ;

//Fonctions 
    g_signal_connect (win_main->button_quit, "clicked", G_CALLBACK(destroy),NULL);
    g_signal_connect (win_main->button_enregistrer, "clicked", G_CALLBACK(modif), win_modif); //Affiche win modif quand appui sur bouton
    g_signal_connect (win_main->button_auteur, "clicked", G_CALLBACK(auteur), win_auteur); 
   // g_signal_connect (win_auteur->button_modify1, "clicked", G_CALLBACK(click_modify), NULL);


  gtk_main ();

   
  main_win_del( win_main ) ;
  modif_win_del ( win_modif ) ; 
  auteur_win_del ( win_auteur ) ;
  

  return 0;

}
