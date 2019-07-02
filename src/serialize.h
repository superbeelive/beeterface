#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <rpc/xdr.h>

typedef struct {
    void *data;             // actual data
    int position;           // where shall the next data be stored or read
    size_t size;            // size of allocated memory
} buffer_t ;

buffer_t* buffer_new() ;
void buffer_del ( buffer_t*) ;

void xdrbuffer_create( XDR* xdrs, buffer_t* buffer, enum xdr_op op ) ;
void xdrbuffer_destroy( XDR* xdrs ) ;

#endif
