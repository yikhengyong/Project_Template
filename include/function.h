// Variables and functions declared in function.h can be used across different .c files

#ifndef FUNCTION_H
#define FUNCTION_H

/* ========================= Global Variables ========================= */

/**
* @brief  [Global Variable] Custom error code
*/
extern signed char errorCode;

/**
* @brief  [Global Variable] May use as iteration in each function and won't affect each other.
*/
extern signed int i;


/* ========================= Function Declarations ========================= */

/**
 * @file    compare-strings.c
 * @brief	Custom string comparison function
 * @param	str1 - Available string
 * @param	str2 - Target string
 * @return	0 if the strings are equal, non-zero otherwise.
 *          NOTE: the non-zero magnitude has no defined meaning and must
 *          NOT be used for ordering (e.g. sorting) — the return type is
 *          unsigned, so it cannot represent a signed difference.
 */
unsigned int compare_strings(const char* str1, const char* str2);

/**
 * @file    custom-function.c
 * @brief	Display i value in function which at different .c file
 * @return	None
 */
void custom_function(void);

#endif // FUNCTION_H 
