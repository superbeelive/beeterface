#ifndef MODULE_H
#define MODULE_H

#include "camera.h"
#include "sensor.h"

typedef struct {
    char* name ;            // nom du module
    char* notes ;           // notes ou description
    int pos_x ;             // Representation graphique 2D
    int pos_y ;
    int width ;
    int height ;
    
    camera_t** cameras ;    // Liste de cameras
    int nb_cameras ;
    int cameras_size ;

    sensor_t** sensors ;    // Liste de modules
    int nb_sensors ;
    int sensors_size ;

} module_t ;


module_t* module_new() ;
void module_del( module_t*) ;
void module_show( int, module_t*, int ) ;

void module_set_name( module_t*, const char* ) ;
char* module_get_name(module_t*) ;

void module_set_notes( module_t*, const char* ) ;
char* module_get_notes( module_t*) ;

void module_del_camera( module_t*, int ) ;
void module_add_camera( module_t*, camera_t*) ;

void module_del_sensor( module_t*, int ) ;
void module_add_sensor( module_t*, sensor_t* ) ;

#endif
