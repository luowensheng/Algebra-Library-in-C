#ifndef EQUATION_H
#define EQUATION_H

#include "stdio.h"
#include "stdlib.h"
#include "./variable.h"



typedef struct
{
    var_t* vars;
    int n_vars;

} equation_t;


void eq_show(var_t* v);

char* eq_tostring(var_t* v);

var_t eq_create(char* s);




#endif

