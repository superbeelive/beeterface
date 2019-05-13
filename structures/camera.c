#include <stdio.h>
#include <stdlib.h>

#include "camera.h"

#define TAILLE 128

camera_t* camera_new(){
    camera_t* cam;
    cam = malloc (sizeof(camera_t));
    cam->name = malloc (TAILLE);
    cam->model = malloc (TAILLE);
    cam->nserie = malloc (TAILLE);
    cam->type = malloc (TAILLE);
    cam->description = malloc (TAILLE);

    sprintf(cam->name, "Nom_de_la_camera");
    sprintf(cam->model, "Modele_de_la_camera");
    sprintf(cam->nserie, "00000");
    sprintf(cam->type, "USB_RESEAU");
    sprintf(cam->description, "Description_de_la_cam");

    return cam;
}

void camera_del ( camera_t* camera_a_dell) {
    free (camera_a_dell->name);
    free (camera_a_dell->model);
    free (camera_a_dell->nserie);
    free (camera_a_dell->type);
    free (camera_a_dell->description);
    free (camera_a_dell);
}

void camera_show ( camera_t* camera_a_show) {
    printf("%s %s %s %s %s\n",camera_a_show->name,
                      camera_a_show->model,
                      camera_a_show->nserie, 
                      camera_a_show->type,
                      camera_a_show->description);
}


//Name 
void camera_set_name (camera_t* camera_a_set, char* name){
    sprintf(camera_a_set->name,"%s",name);
}

char* camera_get_name (camera_t* camera_a_get){
    return camera_a_get->name;
}


//Model

void camera_set_model (camera_t* camera_a_set, char* model){
    sprintf(camera_a_set->model,"%s",model);
}


char* camera_get_model (camera_t* camera_a_get){
    return camera_a_get->model;
}

//Nserie

void camera_set_nserie (camera_t* camera_a_set, char* nserie){
    sprintf(camera_a_set->nserie,"%s",nserie);
}

char* camera_get_nserie (camera_t* camera_a_get){
    return camera_a_get->nserie;
}

//Type

void camera_set_type (camera_t* camera_a_set, char* type){
    sprintf(camera_a_set->type,"%s",type);
}

char* camera_get_type (camera_t* camera_a_get){
    return camera_a_get->type;
}

//Description

void camera_set_description (camera_t* camera_a_set, char* description){
    sprintf(camera_a_set->description,"%s",description);
}

char* camera_get_description (camera_t* camera_a_get){
    return camera_a_get->description;
}

