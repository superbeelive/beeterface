#include <stdlib.h>
#include <stdio.h>

#include "annotations.h"

int main (int argc, char *argv[]) {

        measure_t* ouaf;
        ouaf = measure_new() ; 
        measure_show ( ouaf ) ;
        
        printf("\n") ;

        measure_set_description ( ouaf, "Chien qui danse" ) ;
        char* test1 ;
        test1 = measure_get_description ( ouaf ) ;
        printf ( "descripion : %s\n", test1 ) ;

        measure_set_value ( ouaf , 123 ) ;
        int test2 ;
        test2 = measure_get_value ( ouaf ) ;
        printf ( "Mesure : %d\n", test2) ;

        measure_del (ouaf) ; 

        return 0;
}
