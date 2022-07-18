#include <stdio.h>
#include <string.h>

#ifndef UTILS_H
#define UTILS_H




long pow10(int n){

    long x = 1;

    for (int i = 0; i < n; i++)
    {
       x*= 10;
    }
    
    return x;
}

int int_arr_to_int(int* arr, int num_el){
    
    int num = 0;
    
    for( int i =0; i<= num_el; i++ ){
        num += arr[i]*(pow10(num_el-i-1));
    }
    

    return num;

} 



#endif