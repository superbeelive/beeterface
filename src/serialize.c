#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "serialize.h"

#define INITIAL_BUFFER_SIZE 1024 


void buffer_reserve_space( buffer_t* b, size_t bytes ) ;
int buffer_read( void* iohandle, void* buf, int nbytes ) ;
int buffer_write( void* iohandle, void* buf, int nbytes ) ;



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
    b->position = 0;

    return b ;
}


void buffer_del ( buffer_t* b) {
    free( b->data ) ;
    free( b ) ;
}


void buffer_reserve_space( buffer_t* b, size_t bytes ) {
    if ( (b->position + bytes) > ( b->size )) {
        b->data = realloc( b->data, b->size * 2 ) ;
        b->size *= 2 ;
    }
}


int buffer_write( void* iohandle, void* buf, int nbytes ) {
    buffer_t* b = (buffer_t*) iohandle ;
    buffer_reserve_space( b, nbytes ) ;
    memcpy(b->data + b->position, buf, nbytes ) ;
    b->position += nbytes ;
    return nbytes ;                         // FIXME
}

int buffer_read( void* iohandle, void* buf, int nbytes ) {
    int actual_read_size ;
    buffer_t* b = (buffer_t*) iohandle ;
    actual_read_size = MIN( nbytes, b->size - b->position ) ;
    memcpy( buf, b->data + b->position, actual_read_size ) ;
    b->position += actual_read_size ;
    return actual_read_size ;
}

void xdrbuffer_create( XDR* xdrs, buffer_t* buffer, enum xdr_op op ) {
    xdrrec_create( xdrs, 0, 0, (char*) buffer, &buffer_read, &buffer_write ) ;
    xdrs->x_op = op ;
    if ( op == XDR_DECODE ) {
        xdrrec_skiprecord( xdrs ) ;
    }
}

void xdrbuffer_destroy( XDR* xdrs ) {
    if ( xdrs->x_op == XDR_ENCODE ) {
    xdrrec_endofrecord( xdrs, 1) ;
    }
    xdr_destroy( xdrs ) ;
}
