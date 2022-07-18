#include "./variable.h"
#include "./globals.h"
#include "stdbool.h"
#include <ctype.h>
#include <string.h> 
#include "./utils.h"
#include "./varpaser.h"


var_t var_new(float coef, char letter, int pow){
    
    var_t variable = {coef, letter, pow};
    return variable;
}

var_t* var_to_pointer(var_t* v){
    
    var_t* p = new_pointer(sizeof(var_t));
     
     p->coef = v->coef;
     p->letter = v->letter;
     p->pow = v->pow;

     return p;
}


var_t var_parse(char* s){
     
    varparser_t varparser = varparser_new();

    float coef;
    char* name;
    int pow;

    int i = 0; 
    bool dot_found = false;

    for (int i=0; i< strlen(s); i++ ) {
       
       char c = s[i];

       switch (c)
       {
        case '.':
            varparser_set_dot_loc(&varparser);
            break;

        case '-':
            varparser_set_is_negative(&varparser, true);
            break;

        default:

            if (isalpha(c)){
                varparser_set_letter(&varparser, c);
            } 
            else if (isdigit(c)){
                varparser_push(&varparser, c);
            }

            break;
       }
    } 
    
    return var_new( 
                varparser_multiplier_tofloat(&varparser),
                varparser.letter, 
                varparser_exp_toint(&varparser)
    );
}



void var_show(var_t* v){
    printf("%.2f%c^%d\n", v->coef, v->letter, v->pow);
}

char* var_tostring(var_t* v){
   
   char* str = new_pointer(sizeof(v));
   sprintf(str, "%.2f%c^%d", v->coef, v->letter, v->pow);

   return str;
}

var_t* var_new_pointer(float coef, char letter, int pow){
  
    var_t* varp = new_pointer(sizeof(var_t));
    
    varp->coef = coef;
    varp->letter = letter;
    varp->pow = pow;

    return varp;
}

var_t* var_parse_to_pointer(char* s){
    var_t v = var_parse(s);
    return var_to_pointer(&v);
}

var_t var_copy(var_t* self){
    var_t v = var_new(self->coef, self->letter, self->pow);
    return v;
}


var_t var_derivative(var_t* self){

    int pow = self->pow - 1;
    var_t result = var_new(self->coef*self->pow, self->letter, self->pow-1);
    return result;
}

var_t var_n_derivative(var_t* self, int n){
    
    var_t result = var_copy(self);
    for (size_t i = 0; i < n; i++)
    {
        var_t ans = var_derivative(&result);

        result.coef = ans.coef;
        result.letter = ans.letter;
        result.pow = ans.pow;
    }
    
    return result;
}


