#include <stdlib.h>

#include "beeterface.h"

void callback_destroy(GtkWidget * widget, gpointer data)
{
    gtk_main_quit();
}

void callback_modif(GtkWidget * widget, gpointer data)
{
    modif_win_show(data);
}

void callback_auteur(GtkWidget * widget, gpointer data)
{
    auteur_win_show(data);	// Etape 1 : Faire apparaitre la fenetre 
    				// Etape 2 : Remplir la fenetre avec le contenu de auteur
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

//Fonctions 
    
    g_signal_connect(queen->interface->win_main->button_quit, 
    			"clicked", 
		    	G_CALLBACK(callback_destroy),
		     	NULL);
    
    g_signal_connect(queen->interface->win_main->button_enregistrer, 
    			"clicked", 
			    G_CALLBACK(callback_modif), 
			    queen->interface->win_modif);			//Affiche win modif quand appui sur bouton

    g_signal_connect(queen->interface->win_main->button_auteur, 
    		   	"clicked",
			    G_CALLBACK(callback_auteur), 
			    queen->interface->win_auteur);



    gtk_main();

//Suppr des éléments
    queen_del(queen) ; 

    return 0;

}
