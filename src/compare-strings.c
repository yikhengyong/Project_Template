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


#include <stdio.h>
#include "function.h"

unsigned int compare_strings(const char* str1, const char* str2) {

    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }

    return *(unsigned char*)str1 - *(unsigned char*)str2;
}
