#ifndef VARIABLE_H
#define VARIABLE_H

// #include "stdio.h"
// #include "stdlib.h"



typedef struct
{
    float coef;
    char letter;
    int pow;

} var_t;


void var_show(var_t* v);

char* var_tostring(var_t* v);

var_t var_new(float coef, char letter, int pow);

var_t* var_new_pointer(float coef, char letter, int pow);

var_t var_parse(char* s);

var_t* var_parse_to_pointer(char* s);

var_t var_derivative(var_t* self);

var_t var_n_derivative(var_t* self, int n);

var_t var_copy(var_t* self);




#endif

