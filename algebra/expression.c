#include "./expression.h"
#include "./globals.h"
#include "./operations.h"
#include <string.h>

void expression_push(expression_t* self, var_t* variable){
    self->variables[self->len++] = variable;
}


expression_t expression_new(var_t** variable, int num_el){
    
    expression_t expression;
    expression.len = 0;
   
    expression.variables = new_pointer(sizeof(var_t)*MAX_EXPRESSION_VARS);
   
    for (int i = 0; i < num_el; i++)
    {
       expression_push(&expression, variable[i]);
    }
    
    return expression;
}

// expression_t expression_new(const char* str){
//    var_t variable =  var_parse(str);
//    return expression_new(&variable);
// }



expression_t expression_add(var_t* self, var_t* other){

   return expression_operation(self, other, &operation_add);
}

expression_t expression_operation(var_t* self, var_t* other, float func(float x, float y)){
  
  if (self->letter == other->letter){
  
    if (self->pow == other->pow){
            
            var_t* res = var_new_pointer(func(self->coef,other->coef), self->letter, self->pow);

            var_t* arr[1] = {res};
            
            return expression_new(arr, 1);
        }
   }

   var_t* arr[2] = {self, other};

   return expression_new(arr, 2);
}


// expression_t expression_add(char* self, char* other){
   
//    var_t x = var_parse(self);
//    var_t y = var_parse(other);

//    return operation_add(&x, &y);
// }



expression_t expression_sub(var_t* self, var_t* other){
   return expression_operation(self, other, &operation_sub);
}


// expression_t expression_sub(char* self, char* other){
//    var_t x = var_parse(self);
//    var_t y = var_parse(other);
    
//     expression_sub(&x, &y);
// }



expression_t expression_mul(var_t* self, var_t* other){
   return expression_operation(self, other, &operation_mul);
}


// expression_t expression_mul(char* self, char* other){
//    var_t x = var_parse(self);
//    var_t y = var_parse(other);
    
//     expression_mul(&x, &y);
// }



expression_t expression_div(var_t* self, var_t* other){
   return expression_operation(self, other, &operation_div);
}


// expression_t expression_div(char* self, char* other){
//    var_t x = var_parse(self);
//    var_t y = var_parse(other);
    
//     expression_div(&x, &y);
// }


char* expression_tostring(expression_t* self){

   char* str = new_pointer(sizeof(self));

   for (int i = 0; i < self->len; i++)
   {
       if (i>0){
          strcat(str, " + ");
       }
       strcat(str, var_tostring(self->variables[i]));
   }

   return str;
   
}

void expression_show(expression_t* self){
     
     char* str = expression_tostring(self);
     printf("\nexpression-> %s\n", str); 

}

