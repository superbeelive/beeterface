#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void _throw_error( char* file, int line, char* msg, int death ) {

    fprintf(stderr, "ERROR %s:%d %s\n", file, line, msg ) ;
    if ( death ) {
        exit(EXIT_FAILURE) ;
    }

}

void indent( int n ) {
    int i ;
    for (i=0; i<n; i++)
        printf("\t");
}
