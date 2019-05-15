#include <stdlib.h>
#include <stdio.h>

#include "annotations.h"

int main (int argc, char *argv[]) {

        cross_t* miaou;
        miaou = cross_new() ; 
        cross_show ( miaou ) ;
        
        printf("\n") ;

        cross_set_description ( miaou, "Chat qui tombe" ) ;
        char* test1 ;
        test1 = cross_get_description ( miaou ) ;
        printf ( "descripion : %s\n", test1 ) ;

        cross_set_x ( miaou , 123 ) ;
        int test2 ;
        test2 = cross_get_x ( miaou ) ;
        printf ( "x : %d\n", test2) ;

        cross_set_y ( miaou , 456 ) ; 
        int test3 ;
        test3 = cross_get_y ( miaou ) ; 
        printf ( "y : %d\n", test3) ; 
        
        return 0;
}
