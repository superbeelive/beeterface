#include <stdlib.h>
#include <stdio.h>

#include "color.h"

int main (int argc, char *argv[]) {

        color_t* ficus;

        ficus = color_new() ; 
        color_show ( ficus ) ;

        color_set_name ( ficus, "PONEY" ) ;
        char* nom ;
        nom = color_get_name (ficus) ;
        printf("nom %s",nom); 

        printf ("\n") ; 
        color_set_R ( ficus, 12 ) ;
        int col1 ; 
        col1 = color_get_R ( ficus ) ;
        printf ("R : %d", col1) ;


        color_del ( ficus ) ;

        return 0;
}
