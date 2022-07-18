#include "./globals.h"

#define MAX_POINTERS 100


typedef struct {
   void* list[MAX_POINTERS];
} Globals;

Globals globals;
int COUNTER = 0;



void append_pointer(void* variable){
    globals.list[COUNTER++] = variable;
}


void* get_pointer(int i){
     return globals.list[i];
}

void* new_pointer(size_t _size){

    void* variable = malloc(_size);
    append_pointer(variable);

    return variable;

}

void free_pointer(void* p){
   
    if (p==NULL) return;

    free(p);
    p = NULL;  

}

void free_all(){

    for (int i = 0; i < COUNTER; i++)
    { 
        void* p = get_pointer(i);
        free_pointer(p);
    }

}

