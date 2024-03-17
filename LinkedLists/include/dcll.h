
/*
   
    @ DATE : 17/10/2023
    @ AUTHOR : SATEJ UPENDRA GANJI
    @ PURPOSE : HEADER FILE FOR THE DOUBLY CIRCULAR LINKED LIST 
        
*/

#ifndef _DCLL_H
#define _DCLL_H

#include "common.h"

/* typedefs */

typedef struct node_dcll node_dcll_t;
typedef node_dcll_t list_dcll_t;

/* Data Layout */

struct node_dcll
{
    data_t data;
    struct node_dcll *prev;
    struct node_dcll *next;
};

/* List Creation Routine */

list_dcll_t *create_list_dcll(void);

/* List data Insertion Routines */

status_t insert_beginning_dcll(list_dcll_t *p_list, data_t new_data);
status_t insert_end_dcll(list_dcll_t *p_list, data_t new_data);
status_t insert_after_dcll(list_dcll_t *p_list, data_t new_data, data_t e_data);
status_t insert_before_dcll(list_dcll_t *p_list, data_t new_data, data_t e_data);

/* List data retreival Routines */

status_t get_begin_dcll(list_dcll_t *p_list, data_t *p_data);
status_t get_end_dcll(list_dcll_t *p_list, data_t *p_data);
status_t pop_begin_dcll(list_dcll_t *p_list, data_t *p_popped_data);
status_t pop_end_dcll(list_dcll_t *p_list, data_t *p_popped_data);

/* List Data Removal Routines */

status_t remove_begin_dcll(list_dcll_t *p_list);
status_t remove_end_dcll(list_dcll_t *p_list);
status_t remove_data_dcll(list_dcll_t *p_list, data_t remove_data);

/* List Query Routines */

len_t get_list_length_dcll(list_dcll_t *p_list);
bool is_list_empty_dcll(list_dcll_t *p_list);
int get_element_count_dcll(list_dcll_t *p_list, data_t element_data);
bool list_contains_dcll(list_dcll_t *p_list, data_t element_data);
void show_list_dcll(list_dcll_t *p_list, const char* msg);

/* List deletion Routine */

status_t destroy_list_dcll(list_dcll_t **pp_list);

/* List operation Routines */

list_dcll_t *concat_list_dcll(list_dcll_t *p_list1, list_dcll_t *p_list2);
list_dcll_t *merge_list_dcll(list_dcll_t *p_list1, list_dcll_t *p_list2);
list_dcll_t *get_reversed_list_dcll(list_dcll_t *p_list);
status_t reverse_list_dcll(list_dcll_t *p_list);
status_t append_list_dcll(list_dcll_t *p_list1, list_dcll_t *p_list2);
status_t list_to_array_dcll(list_dcll_t *p_list, data_t **pp_data_array, size_t *p_size);
list_dcll_t *array_to_list_dcll(data_t *p_array, size_t arr_size);

/* List Auxillary Routines */

void generic_insert_dcll(node_dcll_t *p_beg, node_dcll_t *p_mid, node_dcll_t *p_end);
void generic_delete_dcll(node_dcll_t *p_delete_node);

node_dcll_t *get_list_node_dcll(data_t new_data);
node_dcll_t *locate_node_dcll(list_dcll_t *p_list, data_t search_data);


#endif  /* _DCLL_H */
