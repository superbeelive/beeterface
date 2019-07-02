#include <stdio.h>
#include <stdlib.h> 

#include "queen.h"

#define TAB_TAILLE 128

queen_t* queen_new() {
    queen_t* ficus ;
    ficus = malloc ( sizeof(queen_t) ) ; 
    ficus->interface = interface_new() ; 
    ficus->projet = projet_new() ; 
    
    return ficus ; 
}

void queen_del ( queen_t* ficus ) {
    interface_del ( ficus->interface ) ; 
    projet_del ( ficus->projet ) ; 
    free ( ficus ) ; 
}


