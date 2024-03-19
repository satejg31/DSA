
/*
    @ DATE : 22/10/2023
    @ AUTHOR : SATEJ UPENDRA GANJI
    @ PURPOSE : SERVER IMPLEMENTATION FOR THE COMMON FUNCTIONS

*/

#include <stdlib.h>
#include <stdio.h>

#include "../include/common.h"

void *xmalloc(size_t nr_bytes)
{
    void *p = NULL;

    p = malloc(nr_bytes);
    if(p == NULL)
    {
        fprintf(stderr, "Error in allocation of memory");
        exit(EXIT_FAILURE);
    }

    return (p);
}