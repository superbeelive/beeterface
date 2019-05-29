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

void callback__modify()
{
}



int main(int argc, char *argv[])
{

    interface_t* interface ;

//DECLARATION OBJETS 
    projet_t *bidule;
    auteur_t *auteur;

    gtk_init(&argc, &argv);

//DEFINITION DES OBJETS
    bidule = projet_new();
    auteur = auteur_new();

//EMBALLAGE PAPIER KDO
    bidule->auteur = auteur;


    interface = interface_new();



//Affichage de la fenêtre principale 
    main_win_show(interface->win_main);

//Fonctions 
    
    g_signal_connect(interface->win_main->button_quit, 
    			"clicked", 
			G_CALLBACK(callback_destroy),
		     	NULL);
    
    g_signal_connect(interface->win_main->button_enregistrer, 
    			"clicked", 
			G_CALLBACK(callback_modif), 
			interface->win_modif);			//Affiche win modif quand appui sur bouton

    g_signal_connect(interface->win_main->button_auteur, 
    		   	"clicked",
			G_CALLBACK(callback_auteur), 
			interface->win_auteur);



    gtk_main();

    interface_del(interface) ;

    return 0;

}
