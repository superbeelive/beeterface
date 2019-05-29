#include <stdlib.h>
#include <stdio.h>

#include "annotations.h"

int main (int argc, char *argv[]) {

        measure_t* ficus;
        ficus = measure_new() ; 
        measure_show ( ficus ) ;
        
        printf("\n-----------------------------------------------------\n") ;

        measure_set_description ( ficus, "C'est un joli mot ça" ) ;
        char* test1 ;
        test1 = measure_get_description ( ficus ) ;
        printf ( "descripion : %s\n", test1 ) ;
        

        measure_set_description ( ficus, "PONEY") ;
        char* test5 ;
        test5 = measure_get_description ( ficus ) ;
        printf ( "y fin : %s\n", test5 ) ;

        measure_set_time_start ( ficus ) ;
        char* test6 ;
        test6 = measure_get_time_start ( ficus ) ; 
        printf ( "Date de début : %s\n", test6 ) ; 

        measure_del ( ficus ) ; 


        return 0;
}
