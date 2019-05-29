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


//DECLARATION FENETRES 
    main_win_t *win_main;
    modif_win_t *win_modif;
    auteur_win_t *win_auteur;

//DECLARATION OBJETS 
    projet_t *bidule;
    auteur_t *auteur;

    gtk_init(&argc, &argv);

//DEFINITION DES FENETRES  
    win_main = main_win_new();
    win_modif = modif_win_new();
    win_auteur = auteur_win_new();

//DEFINITION DES OBJETS
    bidule = projet_new();
    auteur = auteur_new();

//EMBALLAGE PAPIER KDO
    bidule->auteur = auteur;


//Affichage de la fenêtre principale 
    main_win_show(win_main);

//Fonctions 
    
    g_signal_connect(win_main->button_quit, 
    			"clicked", 
			G_CALLBACK(callback_destroy),
		     	NULL);
    
    g_signal_connect(win_main->button_enregistrer, 
    			"clicked", 
			G_CALLBACK(callback_modif), 
			win_modif);			//Affiche win modif quand appui sur bouton

    g_signal_connect(win_main->button_auteur, 
    		   	"clicked",
			G_CALLBACK(callback_auteur), 
			win_auteur);



    gtk_main();


    main_win_del(win_main);
    modif_win_del(win_modif);
    auteur_win_del(win_auteur);


    return 0;

}
