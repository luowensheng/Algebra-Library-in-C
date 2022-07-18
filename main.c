// https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
// https://stackoverflow.com/questions/6280055/how-do-i-check-if-a-variable-is-of-a-certain-type-compare-two-types-in-c

#include "stdio.h"
#include "./algebra/expression.h"
#include "./algebra/globals.h"
#define let __auto_type
#include <string.h> 

void utils_sort_string (char* string) {
   char temp;

   int i, j;
   int n = strlen(string);

   printf("String before sorting - %s \n", string);

   for (i = 0; i < n-1; i++) {
      for (j = i+1; j < n; j++) {
         if (string[i] > string[j]) {
            temp = string[i];
            string[i] = string[j];
            string[j] = temp;
         }
      }
   }
   
   printf("String after sorting  - %s \n", string);
}

int main(){

    let v1 = var_parse("-2x^2"); 
    let v2 = var_parse("9x^2");

    let string = "rjhqejkrwnqfw";

   //  utils_sort_string(string);


    let v3 = var_derivative(&v2);
    
    var_show(&v3);

    let expression = expression_add(&v1, &v2);
    
    expression_show(&expression);

    FREE_POINTERS_THEN_EXIT;
}