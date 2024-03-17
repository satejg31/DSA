
/*

    @ DATE : 22/10/2023
    @ AUTHOR : SATEJ UPENDRA GANJI
    @ PURPOSE : SERVER FILE FOR THE VECTOR DATA STRUCTURE

*/

#include <stdio.h>
#include <stdlib.h>

#include "../include/vector.h"


/* Vector Creation Routine */
vector_t *create_vector(void)
{
    vector_t *p_vec_int = NULL;
    p_vec_int = (vector_t *)xmalloc(sizeof(vector_t));
    
    p_vec_int->p_vector = NULL;
    p_vec_int->size = 0;

    return (p_vec_int);
}

/* Vector Specific Routines */
status_t push_back(vector_t *p_vec_int, data_t new_data)
{
    p_vec_int->p_vector = (data_t *)realloc(p_vec_int->p_vector, (p_vec_int->size + 1) * sizeof(data_t));
    if(p_vec_int->p_vector == NULL)
    {
        fprintf(stderr, "Error in Memory Allocation");
        return (EXIT_FAILURE);
    }

    p_vec_int->size = p_vec_int->size + 1;
    p_vec_int->p_vector[p_vec_int->size - 1] = new_data;

    return (SUCCESS); 
}

void show(vector_t *p_vec_int, const char* msg)
{
    if(msg)
    {
        puts(msg);
    }

    int i = 0;
    printf("[START]-");
    while(i < p_vec_int->size)
    {
        printf("[%d]-", p_vec_int->p_vector[i]);
        ++i;
    }

    printf("[END]\n");
}

status_t destroy_vector(vector_t *p_vec_int)
{
    free(p_vec_int->p_vector);
    p_vec_int->p_vector = NULL;
    free(p_vec_int);
    p_vec_int = NULL;

    return (SUCCESS);
}

