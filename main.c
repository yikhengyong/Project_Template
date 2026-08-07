/**
* @file     main.c
* @brief    Print out result
* @return   None
*/

#include <stdio.h>
#include "function.h" 

/* 
 ========================= Global Variable Definitions =========================
 * function.h only *declares* these (extern). This is the single translation
 * unit that actually *defines* them — required so the program links under
 * GCC 10+/Clang, which default to -fno-common. 
 ================================================================================
 */

signed char errorCode = 0;
signed int i = 0;

void function(void);

int main(void) {

    // Step 1: Display default value of global variable i
    printf("i default value:%d\n", i);

    // Step 2: Test custom function:compare_string 
    unsigned int compare_result = compare_strings("string1", "string2");
    compare_result == 0 ? printf("Strings are equal\n") : printf("Strings are different\n");

    // Step 3: Functions in main.c
    function();

    // Step 4: Function in header file
    custom_function();

    // Step 5: Update Global Variable i
    i = 2;

    printf("i value in main():%d\n", i);

    // Cleanup
    printf("Error Codes:%d\n", errorCode);

    errorCode = 0;

    return 0;
}


/**
* @brief  Display i value in function which in main.c
* @return None
*/

void function(void) {

    printf("Hello, World!\n");
    i = -99999;
    printf("i value in funtion():%d\n", i);

}

