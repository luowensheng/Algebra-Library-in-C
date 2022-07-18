# Algebra-Library-in-C

Running for Mac or linux
```
source run.sh
```

```c
#include "stdio.h"
#include "./algebra/expression.h"
#include "./algebra/globals.h"
#define let __auto_type
#include <string.h> 

int main(){

    let v1 = var_parse("-2x^2"); 
    let v2 = var_parse("9x^2");


    let v3 = var_derivative(&v2);
    
    var_show(&v3); // 18.00x^1

    let expression = expression_add(&v1, &v2);
    
    expression_show(&expression); // expression -> 7.00x^2

    FREE_POINTERS_THEN_EXIT;
}

```
