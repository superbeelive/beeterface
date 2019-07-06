#include <stdio.h>
#include <stdlib.h>

#include "module.h"
#include "utils.h"


module_t* module_new() {
    module_t* tmp ;
    tmp = (module_t*) malloc(sizeof(module_t)) ;
    if ( tmp==NULL ) {
        throw_error("malloc failed", 1 ) ;
        return NULL ;
    }
    tmp->notes=(char*) malloc( STRING_SIZE ) ;
    if ( tmp->notes == NULL ) {
        throw_error("malloc failed", 1 ) ;
        return NULL ;
    }
    tmp->cameras = (camera_t**) malloc ( BLOC_SIZE * sizeof(camera_t*) ) ;
    if ( tmp->cameras == NULL ) {
        throw_error("malloc failed", 1 ) ;
        return NULL ;
    }
    tmp->sensors = (sensor_t**) malloc ( BLOC_SIZE * sizeof(sensor_t*) ) ;
    if ( tmp->sensors == NULL ) {
        throw_error("malloc failed", 1 ) ;
        return NULL ;
    }
    sprintf(tmp->name, "Unnamed module") ;
    sprintf(tmp->notes,"N/A") ;
    tmp->pos_x = 0 ;
    tmp->pos_y = 0 ;
    tmp->width = 10 ;
    tmp->height = 10 ;
    tmp->nb_cameras = 0 ;
    tmp->cameras_size = BLOC_SIZE ;
    tmp->nb_sensors = 0 ;
    tmp->sensors_size = BLOC_SIZE ;
    return tmp ;
}

void module_del( module_t* mod ) {
    int i ;
    free(mod->name) ;
    free(mod->notes) ;
    for (i=0;i<mod->nb_cameras;i++) {
        camera_del(mod->cameras[i]) ;
    }
    free(mod->cameras) ;
    for (i=0; i<mod->nb_sensors;i++) {
        sensor_del( mod->sensors[i] ) ;
    }
    free(mod->sensors) ;
    free(mod) ;
}

void module_show( int ind, module_t* mod, int recur ) {
    int i ;
    indent(ind) ;
    printf("Module:\n") ;
    indent(ind) ;
    printf("  Name: %s\n", mod->name ) ;
    indent(ind) ;
    printf("  Notes:\n");
    indent(ind) ;
    printf("  %s\n", mod->notes ) ;
    if ( recur ) {
        for (i=0; i<mod->nb_cameras; i++)
            camera_show( ind+1, mod->cameras[i] ) ;
        for (i=0; i<mod->nb_sensors; i++)
            sensor_show( ind+1, mod->sensors[i] ) ;
    }
}

void module_set_name( module_t* mod, const char* name) {
    sprintf(mod->name,"%s",name) ;
}

char* module_get_name( module_t* mod ) {
    return mod->name ;
}

void module_set_notes( module_t* mod, const char* notes) {
    sprintf(mod->notes,"%s",notes) ;
}

char* module_get_notes( module_t* mod ) {
    return mod->notes ;
}

void module_del_camera( module_t* mod, int n ) {
    int i ;
    if ((n<0) || (n >= mod->nb_cameras)) {
        throw_error("invalid index",0);
        return ;
    }
   camera_del(mod->cameras[n]) ;
   for(i=n+1;i<mod->nb_cameras;i++) {
        mod->cameras[i-1]=mod->cameras[i] ;
   }
   mod->nb_cameras -= 1 ;
}

void module_del_sensor( module_t* mod, int n ) {
    int i ;
    if ((n<0) || (n >= mod->nb_sensors)) {
        throw_error("invalid index",0);
        return ;
    }
   sensor_del(mod->sensors[n]) ;
   for(i=n+1;i<mod->nb_sensors;i++) {
        mod->sensors[i-1]=mod->sensors[i] ;
   }
   mod->nb_sensors -= 1 ;
}

void module_add_camera( module_t* module, camera_t* camera ) {
    if (module->nb_cameras == module->cameras_size ) {
        module->cameras = reallocarray( module->cameras, module->cameras_size+BLOC_SIZE, sizeof(camera_t*) ) ;
        module->cameras_size += BLOC_SIZE ;
    }
    module->cameras[module->nb_cameras] = camera ;
    module->nb_cameras +=1 ;
}

void module_add_sensor( module_t* module, sensor_t* sensor ) {
    if (module->nb_sensors == module->sensors_size ) {
        module->sensors = reallocarray( module->sensors, module->sensors_size+BLOC_SIZE, sizeof(sensor_t*) ) ;
        module->sensors_size += BLOC_SIZE ;
    }
    module->sensors[module->nb_sensors] = sensor ;
    module->nb_sensors +=1 ;
}
