#include <stdlib.h>
#include <stdio.h>

#include "annotations.h"

int main (int argc, char *argv[]) {

        moving_cross_t* axolot;
        axolot = moving_cross_new() ; 
        moving_cross_show ( axolot ) ;
        
        printf("\n") ;

        moving_cross_set_description ( axolot, "Axolot noyé" ) ;
        char* test1 ;
        test1 = moving_cross_get_description ( axolot ) ;
        printf ( "descripion : %s\n", test1 ) ;

        moving_cross_del ( axolot ) ;
        return 0;
}
