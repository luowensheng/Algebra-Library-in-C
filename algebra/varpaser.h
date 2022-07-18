#ifndef VARPARSER_H
#define VARPARSER_H

#define MAX_NUM_LEN 5

typedef struct {

    int* multipliers;
    int* exponents;
    int n_multipliers;
    int len;
    int n_exponents;
    int dot_loc;
    int letter_loc;
    char letter;
    bool is_negative;
    bool exp_is_negative;


} varparser_t;



varparser_t varparser_new(){

    varparser_t varparser;
    varparser.exponents = new_pointer(sizeof(int)*MAX_NUM_LEN);
    varparser.multipliers = new_pointer(sizeof(int)*MAX_NUM_LEN);
    varparser.n_multipliers = 0;
    varparser.n_exponents = 0;
    varparser.len = 0;
    varparser.dot_loc = -1;
    varparser.is_negative = false;
    varparser.letter_loc = -1;
    varparser.exp_is_negative = false;

    return varparser;
}

void varparser_set_is_negative(varparser_t* self, bool is_negative){
    
    if (self->letter_loc!=-1){
        self->exp_is_negative = true;
    } else {
       self->is_negative = is_negative;
    }
}

void varparser_push(varparser_t* self, char c){
    
    int x = atoi(&c);
    bool letter_found = self->letter_loc!=-1;

    if (!letter_found){
        
        if (self->n_exponents > MAX_NUM_LEN ) return;

        self->multipliers[self->n_multipliers++] = x;

    } else {
      
        if (self->n_multipliers > MAX_NUM_LEN ) return;
    
        self->exponents[self->n_exponents++] = x;
    
    }

    self->len++;

}

void varparser_set_dot_loc(varparser_t* self){

    if (self->dot_loc != -1){
       return;     
    }     
    self->dot_loc = self->len;
}

void varparser_set_letter(varparser_t* self, char c){

    if (self->letter_loc != -1){
       return;     
    }     
    self->letter_loc = self->len;
    self->letter = c;
}


char* varparser_tostring(varparser_t* self){
     
    char* str = new_pointer(sizeof(self));
    
    int start = 0;
    int n_mul = 0;
    int n_exp = 0;

    if (self->is_negative){
       str[0] = '-';        
       start = 1;
    }

    for (size_t i = 0; i < self->len; i++)
    {
        if (i == self->dot_loc){
            str[start++ +i] = '.';
        }

        if( i == self->letter_loc){
            str[start++ +i] = self->letter;
            str[start++ +i] = '^';
        }

        if (i >= self->n_multipliers){
            str[start+i] = self->exponents[n_exp++] + '0';
        } else {
            str[start+i] = self->multipliers[n_mul++] + '0';
        }

    }

    return str;
    
}

void varparser_show(varparser_t* self){

    char* num_str = varparser_tostring(self);
    printf("\nvarparser->%s\n",num_str);
}

float varparser_multiplier_tofloat(varparser_t* self){
     
     float num = (float) int_arr_to_int(self->multipliers, self->n_multipliers);
     float s = (self->is_negative)? -1: 1; 
     return s*num/pow10(self->dot_loc);
}

int varparser_exp_toint(varparser_t* self){
     
     int num = int_arr_to_int(self->exponents, self->n_exponents);
     int s = (self->exp_is_negative)? -1: 1; 
     return s * num;
}

#endif

