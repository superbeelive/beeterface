#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <rpc/xdr.h>

#include "utils.h"
#include "serialize.h"

#define INITIAL_BUFFER_SIZE 128 


void buffer_reserve_space( buffer_t* b, size_t bytes ) ;


buffer_t* buffer_new() {

    buffer_t* b ;
    b = malloc ( sizeof(buffer_t ) ) ;
    if ( b==NULL ) {
        throw_error( "malloc failed", 1 ) ;
        return NULL ;
    }

    b->data = malloc(INITIAL_BUFFER_SIZE);
    if ( b->data==NULL ) {
        throw_error( "malloc failed", 1 ) ;
        return NULL ;
    }

    b->size = INITIAL_BUFFER_SIZE;
    b->next = 0;

    return b ;
}


void buffer_del ( buffer_t* b) {
    free( b->data ) ;
    free( b ) ;
}


void buffer_reserve_space( buffer_t* b, size_t bytes ) {
    if ( (b->next + bytes) > ( b->size )) {
        b->data = realloc( b->data, b->size * 2 ) ;
        b->size *= 2 ;
    }
}


int buffer_write( char* iohandle, char* buf, int nbytes ) {
    buffer_t* b = (buffer_t*) iohandle ;
    buffer_reserve_space( b, nbytes ) ;
    memcpy((char*)b->data + n->next, buf, nbytes ) ;
    b->next += sizeof(int) ;
    return nbytes ;                         // FIXME
}



