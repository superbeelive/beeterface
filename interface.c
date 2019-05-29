#include <stdio.h>
#include <stdlib.h>
#include "interface.h"


interface_t* interface_new() {
	interface_t* tmp ;
	tmp = malloc ( sizeof(interface_t) ) ;

        tmp->win_main = main_win_new();
    	tmp->win_modif = modif_win_new();
    	tmp->win_auteur = auteur_win_new();

	return tmp ;
}


void interface_del ( interface_t* tmp ) {
	main_win_del( tmp->win_main ) ;
	modif_win_del( tmp->win_modif ) ;
	auteur_win_del ( tmp->win_auteur ) ;
	free ( tmp ) ;
}
