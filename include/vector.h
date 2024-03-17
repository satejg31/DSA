
/*
    @ DATE : 22/10/2023
    @ AUTHOR : SATEJ UPENDRA GANJI
    @ PURPOSE : HEADER FILE FOR THE VECTOR DATA STRUCTURE

*/

#ifndef _VECTOR_H 
#define _VECTROR_H

#include "common.h"

typedef struct vector vector_t;

struct vector 
{
    data_t *p_vector;
    size_t size;
};

/* Vector Creation Routine */
vector_t *create_vector(void);

/* Vector Specific Routines */
status_t push_back(vector_t *p_vector, data_t new_data);
void show(vector_t *p_vec, const char* msg);
status_t destroy_vector(vector_t *p_vec);

#endif  /* _VECTOR_H */