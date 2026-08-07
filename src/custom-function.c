/**
 * @file    custom-function.c
 * @brief	Display i value in function which at different .c file
 * @return	None
*/


#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void custom_function() {
    
    int* ptr = (int*)malloc(sizeof(int)); // Allocate memory for one integer
    i = 1234;
    printf("i value in funtion_in_src():%d\n", i);
    //ptr = NULL;

    if (!ptr) {
        errorCode = -2;
        fprintf(stderr, "Error Code [%i] : Pointer is NULL. \n", errorCode);
    }

    free(ptr); // Free the allocated memory when done
}

