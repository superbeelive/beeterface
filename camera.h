#ifndef CAMERA_H
#define CAMERA_H

typedef struct {
    char* name;
    char* model;
    char* nserie;
    char* type;
    char* description;
} camera_t ; 


camera_t* camera_new() ;
void camera_del (camera_t*);
void camera_show (camera_t*);

// Name
void camera_set_name (camera_t*, char* name);
char* camera_get_name (camera_t*);

// Model
void camera_set_model (camera_t*, char* model);
char* camera_get_model (camera_t*);

// Nserie
void camera_set_nserie (camera_t*, char* nserie);
char* camera_get_nserie (camera_t*);

// Type
void camera_set_type (camera_t*, char* type);
char* camera_get_type (camera_t*);

// Description
void camera_set_description (camera_t*, char* description);
char* camera_get_description (camera_t*);


#endif
