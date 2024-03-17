
/*
   
    @ DATE : 17/10/2023
    @ AUTHOR : SATEJ UPENDRA GANJI
    @ PURPOSE : HEADER FILE FOR THE SINGLY LINKED LIST 
                
*/

#ifndef _SLL_H 
#define _SLL_H

#include "common.h"

/* typedefs */

typedef struct node_sll node_sll_t;
typedef node_sll_t list_sll_t;


/* Data Layout */

struct node_sll
{
    data_t data;
    struct node_sll *next;
};

/* List Creation Routine */

list_sll_t *create_list_sll();


/* List Data Insertion Routines */

status_t insert_beginning_sll(list_sll_t *p_list, data_t new_data);
status_t insert_end_sll(list_sll_t *p_list, data_t new_data);
status_t insert_after_sll(list_sll_t *p_list, data_t new_data, data_t e_data);
status_t insert_before_sll(list_sll_t *p_list, data_t new_data, data_t e_data);

/* List Data Retreival Routines */

status_t get_begin_sll(list_sll_t *p_list, data_t *p_beg_data);
status_t get_end_sll(list_sll_t *p_list, data_t *p_end_data);
status_t pop_begin_sll(list_sll_t *p_list, data_t *p_popped_data);
status_t pop_end_sll(list_sll_t *p_list, data_t *p_popped_data);

/* List Data Removal Routines */

status_t remove_begin_sll(list_sll_t *p_list);
status_t remove_end_sll(list_sll_t *p_list);
status_t remove_data_sll(list_sll_t *p_list, data_t r_data);


/* List Query Routines */

len_t get_list_length_sll(list_sll_t *p_list);
bool is_list_empty_sll(list_sll_t *p_list);
int get_element_count_sll(list_sll_t *p_list, data_t element_data);
bool list_contains_sll(list_sll_t *p_list, data_t element_data);
void show_list_sll(list_sll_t *p_list, const char *msg);

/* List Deletion Routine */

status_t destroy_list_sll(list_sll_t **pp_list);

/* List Operation Routines */

list_sll_t *concat_list_sll(list_sll_t *p_list1, list_sll_t *p_list2);
list_sll_t *merge_list_sll(list_sll_t *p_list1, list_sll_t *p_list2);
list_sll_t *get_reversed_list_sll(list_sll_t *p_list);
status_t append_list_sll(list_sll_t *p_list1, list_sll_t *p_list2);
status_t reverse_list_sll(list_sll_t *p_list);
status_t list_to_array_sll(list_sll_t *p_list, data_t **pp_data_array, size_t *p_size);
list_sll_t *array_to_list_sll(data_t *p_array, size_t arr_size);


/* List Auxillary routines */

void generic_insert_sll(node_sll_t *p_beg, node_sll_t *p_mid, node_sll_t *p_end);
void generic_delete_sll(node_sll_t *p_prev_node, node_sll_t *p_delete_node);

void get_last_node_sll(list_sll_t *p_list, node_sll_t **pp_last_node);
void get_node_and_prev_sll(list_sll_t *p_list, data_t s_data, node_sll_t **pp_node, node_sll_t **pp_prev_node);
void get_last_node_and_prev_sll(list_sll_t *p_list, node_sll_t **pp_last_node, node_sll_t **pp_prev_node);

node_sll_t *locate_node_sll(list_sll_t *p_list, data_t search_data);
node_sll_t *get_list_node_sll(data_t new_data);


#endif /* _SLL_H */
