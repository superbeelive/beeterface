#include <stdlib.h>

#include "queen.h"
void callback_destroy(GtkWidget * widget, gpointer data)
{
    gtk_main_quit();
}

void callback_modif(GtkWidget * widget, gpointer data)
{
    queen_t* tmp ;
    tmp = data ;
    modif_win_show(tmp->interface->win_modif);

}

void callback_auteur(GtkWidget * widget, gpointer data)
{
    queen_t* tmp ;
    tmp = data ;
    // Remplissage de la fenêtre avec le contenu de auteur 
    auteur_win_fill(tmp->interface->win_auteur, tmp->projet->auteur ) ; 
    
    //Apparition de la fenêtre
    auteur_win_show(tmp->interface->win_auteur); 
}

void callback_auteur_modify_name(GtkWidget* widget, gpointer data)
{
    queen_t* tmp ; 
    tmp = data ;
    if ( tmp->interface->win_auteur->modif == 0 )  
    auteur_button_modify_name(tmp->interface->win_auteur, tmp->projet->auteur ) ;     
    else 
    auteur_button_modify_ok_name(tmp->interface->win_auteur, tmp->projet->auteur ) ;
}


int main(int argc, char *argv[])
{


//Création de la grande structure
    queen_t * queen;

//Initialisation de GTK
    gtk_init(&argc, &argv);

//Définition de la grande structure
    queen = queen_new();

//Affichage de la fenêtre principale 
    main_win_show(queen->interface->win_main);

//////FONCTIONS///////
//Fenêtre MAIN     
    g_signal_connect(queen->interface->win_main->button_quit, 
    			"clicked", 
		    	G_CALLBACK(callback_destroy),
		     	NULL);
    
    g_signal_connect(queen->interface->win_main->button_enregistrer, 
    			"clicked", 
			    G_CALLBACK(callback_modif), 
			    queen);			//Affiche win modif quand appui sur bouton

    g_signal_connect(queen->interface->win_main->button_auteur, 
    		   	"clicked",
			    G_CALLBACK(callback_auteur), 
			    queen);
//Fenêtre AUTEUR 
    g_signal_connect(queen->interface->win_auteur->button_modify1,
            "clicked",
            G_CALLBACK(callback_auteur_modify_name),
            queen);


//Fonction attend event.     
    gtk_main();

//Suppr des éléments
    queen_del(queen) ; 

    return 0;

}
