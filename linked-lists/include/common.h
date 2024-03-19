/*

    @ DATE : 17/10/2023
    @ AUTHOR NAME : SATEJ UPENDRA GANJI
    @ PURPOSE : THIS FILE CONTAINS THE COMMON TYPEDEFS AND PRE-PROCESSOR DIRECTIVES.

*/

#ifndef _COMMON_H
#define _COMMON_H

typedef int data_t;
typedef int len_t;
typedef int bool;
typedef int status_t;
typedef unsigned long size_t;


#define TRUE                    1
#define FALSE                   0
#define SUCCESS                 1
#define FAILURE                 0
#define LIST_EMPTY              2
#define LIST_DATA_NOT_FOUND     3


/* List Memory Allocation Routine */

void *xmalloc(size_t nr_bytes);

#endif /* _COMMON_H */