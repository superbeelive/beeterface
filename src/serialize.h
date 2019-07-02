#ifndef SERIALIZE_H
#define SERIALIZE_H



typedef struct {
    void *data;             // actual data
    int next;               // where shall the next data be stored
    size_t size;            // size of allocated memory
} buffer_t ;

buffer_t* buffer_new() ;
void buffer_del ( buffer_t*) ;



#endif
