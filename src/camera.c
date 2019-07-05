#include <stdio.h>
#include <stdlib.h>

#include "camera.h"
#include "utils.h"

#define STRING_SIZE 128

const char* camera_type_to_string( camera_type_t T ) {
    switch (T) {
        case CAM_USB_UVC : 
            return "CAM_USB_VC" ;
        case CAM_ETH : 
            return "CAM_ETH" ;
        default:
            return "Unknown Camera";
    }
} 

camera_t* camera_new(){
    camera_t* cam;
    cam = malloc (sizeof(camera_t));
    if ( cam == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    cam->name = malloc (STRING_SIZE);
    if ( cam->name == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    cam->model = malloc (STRING_SIZE);
    if ( cam->model == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    cam->serial = malloc (STRING_SIZE);
    if ( cam->serial == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    cam->notes = malloc (STRING_SIZE);
    if ( cam->notes == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    cam->hw_handle = malloc (STRING_SIZE);
    if ( cam->hw_handle == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    sprintf(cam->name, "Nom_de_la_camera");
    sprintf(cam->model, "Modele_de_la_camera");
    sprintf(cam->serial, "00000");
    cam->type = CAM_USB_UVC ;
    sprintf(cam->notes, "Description_de_la_cam");

    return cam;
}

void camera_del ( camera_t* camera_a_dell) {
    free (camera_a_dell->name);
    free (camera_a_dell->model);
    free (camera_a_dell->serial);
    free (camera_a_dell->notes);
    free (camera_a_dell);
}

void camera_show ( int ind, camera_t* cam ) {
    indent (ind ) ;
    printf("Camera:\n");
    indent(ind) ;
    printf("  Name: %s\n",cam->name ) ;
    indent(ind) ;
    printf("  Model: %s\n", cam->model ) ;
    indent(ind) ;
    printf("  Serial: %s\n", cam->serial ) ;
    indent(ind) ;
    printf("  Type : %s\n", camera_type_to_string(cam->type) ) ;
    indent(ind) ;
    printf("  Hw_handle : %s\n", cam->hw_handle ) ;
    indent(ind) ;
    printf("  Notes :\n");
    indent(ind) ;
    printf("  %s\n", cam->notes ) ;
}

void camera_set_name (camera_t* camera_a_set, const char* name){
    sprintf(camera_a_set->name,"%s",name);
}

char* camera_get_name (camera_t* camera_a_get){
    return camera_a_get->name;
}

void camera_set_model (camera_t* camera_a_set, const char* model){
    sprintf(camera_a_set->model,"%s",model);
}

char* camera_get_model (camera_t* camera_a_get){
    return camera_a_get->model;
}

void camera_set_serial (camera_t* camera_a_set, const char* serial){
    sprintf(camera_a_set->serial,"%s",serial);
}

char* camera_get_serial (camera_t* camera_a_get){
    return camera_a_get->serial;
}

void camera_set_type (camera_t* camera_a_set, camera_type_t type){
    camera_a_set->type = type ;
}

camera_type_t camera_get_type (camera_t* camera_a_get){
    return camera_a_get->type;
}

void camera_set_notes (camera_t* camera_a_set, const char* notes){
    sprintf(camera_a_set->notes,"%s",notes);
}

char* camera_get_notes (camera_t* camera_a_get){
    return camera_a_get->notes;
}

void camera_set_hw_handle (camera_t* camera_a_set, const char* handle){
    sprintf(camera_a_set->hw_handle,"%s",handle);
}

char* camera_get_hw_handle (camera_t* camera_a_get){
    return camera_a_get->hw_handle;
}
