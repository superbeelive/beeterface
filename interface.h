#ifndef INTERFACE_H
#define INTERFACE_H

#include "main_win.h"
#include "modif_win.h"
#include "auteur_win.h"



typedef struct {

	main_win_t* win_main ;	
	modif_win_t* win_modif ;
	auteur_win_t* win_auteur ;

} interface_t ;


interface_t* interface_new() ;
void interface_del ( interface_t*) ;

#endif
