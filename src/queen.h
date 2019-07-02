#ifndef QUEEN_H 
#define QUEEN_H

#include "interface.h"
#include "projet.h" 

typedef struct {
    interface_t* interface ; 
    projet_t* projet ; 
} queen_t ; 

queen_t* queen_new() ; 
void queen_del ( queen_t* ) ; 
 
#endif 
