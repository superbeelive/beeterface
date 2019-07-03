#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <rpc/xdr.h>

#include "author.h"
#include "camera.h"
#include "video.h"
#include "color.h"
#include "projet.h"

typedef struct {
    void *data;             // actual data
    int position;           // where shall the next data be stored or read
    size_t size;            // size of allocated memory
} buffer_t ;

buffer_t* buffer_new() ;
void buffer_del ( buffer_t*) ;

void xdrbuffer_create( XDR*, buffer_t*, enum xdr_op ) ;
void xdrbuffer_destroy( XDR* ) ;

int xdr_auteur( XDR*, author_t* ) ;
int xdr_camera( XDR*, camera_t* ) ;
int xdr_video( XDR*, video_t* ) ;
int xdr_color( XDR*, color_t* ) ;
int xdr_projet( XDR*, projet_t* ) ;

#endif
