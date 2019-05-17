#include <stdlib.h>
#include <stdio.h>

#include "annotations.h"

int main (int argc, char *argv[]) {

        oblong_t* ficus;
        ficus = oblong_new() ; 
        oblong_show ( ficus ) ;
        
        printf("\n") ;

        oblong_set_description ( ficus, "C'est un joli mot ça" ) ;
        char* test1 ;
        test1 = oblong_get_description ( ficus ) ;
        printf ( "descripion : %s\n", test1 ) ;
        

        oblong_set_x_start ( ficus, 0 ) ;
        int test2 ;
        test2 = oblong_get_x_start ( ficus ) ;
        printf ( "x départ : %d\n", test2 ) ;


        oblong_set_y_start ( ficus, 1 ) ;
        int test3 ;
        test3 = oblong_get_y_start ( ficus ) ;
        printf ( "y départ : %d\n", test3 ) ;


        oblong_set_x_end ( ficus, 2 ) ;
        int test4 ;
        test4 = oblong_get_x_end( ficus ) ;
        printf ( "x fin : %d\n", test4 ) ;


        oblong_set_y_end ( ficus, 3 ) ;
        int test5 ;
        test5 = oblong_get_y_end ( ficus ) ;
        printf ( "y fin : %d\n", test5 ) ;

        oblong_set_time_start ( ficus ) ;
        char* test6 ;
        test6 = oblong_get_time_start ( ficus ) ; 
        printf ( "Date de début : %s\n", test6 ) ; 

        oblong_del ( ficus ) ; 

        return 0;
}
