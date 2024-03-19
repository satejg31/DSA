
/*
   
    @ DATE : 17/10/2023
    @ AUTHOR : SATEJ UPENDRA GANJI
    @ PURPOSE : HEADER FILE FOR THE DOUBLY LINKED LIST 

*/

#ifndef _DLL_H
#define _DLL_H

#include "common.h"

/* typedefs */

typedef struct node_dll node_dll_t;
typedef node_dll_t list_dll_t;

/* Data Layout */

struct node_dll
{
    data_t data;
    struct node_dll *prev;
    struct node_dll *next;
};

/* List Creation Routine */

list_dll_t *create_list_dll();

/* List data insertion Routines */

status_t insert_beginning_dll(list_dll_t *p_list, data_t new_data);
status_t insert_end_dll(list_dll_t *p_list, data_t new_data);
status_t insert_after_dll(list_dll_t *p_list, data_t new_data, data_t e_data);
status_t insert_before_dll(list_dll_t *p_list, data_t new_data, data_t e_data);

/* List data retireval Routines */

status_t get_begin_dll(list_dll_t* p_list, data_t *p_data);
status_t get_end_dll(list_dll_t *p_list, data_t *p_data);
status_t pop_begin_dll(list_dll_t *p_list, data_t *p_popped_data);
status_t pop_end_dll(list_dll_t *p_list, data_t *p_popped_data);

/* List Data Removal Routines */

status_t remove_begin_dll(list_dll_t *p_list);
status_t remove_end_dll(list_dll_t *p_list);
status_t remove_data_dll(list_dll_t *p_list, data_t remove_data);

/* List Query Routines */

bool is_list_empty_dll(list_dll_t *p_list);
len_t get_list_length_dll(list_dll_t *p_list);
int get_element_count_dll(list_dll_t *p_list, data_t element_data);
bool list_contains_dll(list_dll_t *p_list, data_t element_data);
void show_list_dll(list_dll_t *p_list, const char *msg);

/* List Deletion Routines */

status_t destroy_list_dll(list_dll_t **p_list);

/* List Operation Routines */

list_dll_t *concat_list_dll(list_dll_t *p_list1, list_dll_t *p_list2);
list_dll_t *merge_list_dll(list_dll_t *p_list1, list_dll_t *p_list2);
list_dll_t *get_reversed_list_dll(list_dll_t *p_list);
status_t reverse_list_dll(list_dll_t *p_list);
status_t append_list_dll(list_dll_t *p_list1, list_dll_t *p_list2);
status_t list_to_array_dll(list_dll_t *p_list, data_t **pp_data_array, size_t *p_size);
list_dll_t *array_to_list_dll(data_t *p_array, size_t arr_size);

/* List Auxillary Routines */

void generic_insert_dll(node_dll_t *p_beg, node_dll_t *p_mid, node_dll_t *p_end);
void generic_delete_dll(node_dll_t *p_delete_node);

node_dll_t *get_list_node_dll(data_t new_data);
node_dll_t *locate_list_node_dll(list_dll_t *p_list, data_t search_data);
void get_last_node_dll(list_dll_t *p_list, node_dll_t **pp_last_node);


#endif /* _DLL_H */
