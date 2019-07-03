#include <stdio.h>
#include <stdlib.h>

#include "camera.h"

#define TAILLE 128

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
    cam->name = malloc (TAILLE);
    cam->model = malloc (TAILLE);
    cam->serial = malloc (TAILLE);
    cam->description = malloc (TAILLE);

    sprintf(cam->name, "Nom_de_la_camera");
    sprintf(cam->model, "Modele_de_la_camera");
    sprintf(cam->serial, "00000");
    cam->type = CAM_USB_UVC ;
    sprintf(cam->description, "Description_de_la_cam");

    return cam;
}

void camera_del ( camera_t* camera_a_dell) {
    free (camera_a_dell->name);
    free (camera_a_dell->model);
    free (camera_a_dell->serial);
    free (camera_a_dell->description);
    free (camera_a_dell);
}

void camera_show ( camera_t* camera_a_show) {
    printf("%s %s %s %d %s\n",camera_a_show->name,
                      camera_a_show->model,
                      camera_a_show->serial, 
                      camera_a_show->type,
                      camera_a_show->description);
}


//Name 
void camera_set_name (camera_t* camera_a_set, const char* name){
    sprintf(camera_a_set->name,"%s",name);
}

char* camera_get_name (camera_t* camera_a_get){
    return camera_a_get->name;
}


//Model

void camera_set_model (camera_t* camera_a_set, const char* model){
    sprintf(camera_a_set->model,"%s",model);
}


char* camera_get_model (camera_t* camera_a_get){
    return camera_a_get->model;
}

//Nserie

void camera_set_serial (camera_t* camera_a_set, const char* serial){
    sprintf(camera_a_set->serial,"%s",serial);
}

char* camera_get_serial (camera_t* camera_a_get){
    return camera_a_get->serial;
}

//Type

void camera_set_type (camera_t* camera_a_set, camera_type_t type){
    camera_a_set->type = type ;
}

camera_type_t camera_get_type (camera_t* camera_a_get){
    return camera_a_get->type;
}

//Description

void camera_set_description (camera_t* camera_a_set, const char* description){
    sprintf(camera_a_set->description,"%s",description);
}

char* camera_get_description (camera_t* camera_a_get){
    return camera_a_get->description;
}

