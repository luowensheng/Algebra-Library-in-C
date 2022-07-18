#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "stdio.h"
#include "stdlib.h"
#include "./variable.h"
#define MAX_EXPRESSION_VARS 5

typedef struct {
  var_t** variables;
  int len;
} expression_t;

void expression_push(expression_t* self, var_t* variable);


expression_t expression_new(var_t** variable, int num_el);
// expression_t expression_new(const char* str, int x);

expression_t expression_operation(var_t* self, var_t* other, float func(float x, float y));


expression_t expression_add(var_t* self, var_t* other);
// expression_t expression_add(char* self, char* other);

expression_t expression_sub(var_t* self, var_t* other);
// expression_t expression_sub(char* self, char* other);

expression_t expression_mul(var_t* self, var_t* other);
// expression_t expression_mul(char* self, char* other);

expression_t expression_div(var_t* self, var_t* other);
// expression_t expression_div(char* self, char* other);

char* expression_tostring(expression_t* self);

void expression_show(expression_t* self);


#endif

