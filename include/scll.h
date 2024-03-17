
/*
   
    @ DATE : 17/10/2023
    @ AUTHOR : SATEJ UPENDRA GANJI
    @ PURPOSE : HEADER FILE FOR THE SINGLY CIRCULAR LINKED LIST 
                
*/

#ifndef _SCLL_H
#define _SCLL_H

#include "common.h"

/* typedefs */

typedef struct node_scll node_scll_t;
typedef node_scll_t list_scll_t;

/* Data Layout */

struct node_scll
{
    data_t data;
    struct node_scll *next;
};

/* List Creation Routine */

list_scll_t *create_list_scll();

/* List Data Insertion Routines */

status_t insert_beginning_scll(list_scll_t *p_list, data_t new_data);
status_t insert_end_scll(list_scll_t *p_list, data_t new_data);
status_t insert_after_scll(list_scll_t *p_list, data_t new_data, data_t e_data);
status_t insert_before_scll(list_scll_t *p_list, data_t new_data, data_t e_data);

/* List data retreival Routines */

status_t get_begin_scll(list_scll_t *p_list, data_t *p_data);
status_t get_end_scll(list_scll_t *p_list, data_t *p_data);
status_t pop_begin_scll(list_scll_t *p_list, data_t *p_popped_data);
status_t pop_end_scll(list_scll_t *p_list, data_t *p_popped_data);

/* List Data Removal Rouutines */

status_t remove_begin_scll(list_scll_t *p_list);
status_t remove_end_scll(list_scll_t *p_list);
status_t remove_data_scll(list_scll_t *p_list, data_t remove_data);

/* List Query Routines */

len_t get_list_length_scll(list_scll_t *p_list);
bool is_list_empty_scll(list_scll_t *p_list);
int get_element_count_scll(list_scll_t *p_list, data_t element_data);
bool list_contains_scll(list_scll_t *p_list, data_t element_data);
void show_list_scll(list_scll_t *p_list, const char* msg);

/* List deletion Routines */

status_t destroy_list_scll(list_scll_t **pp_list);

/* List operation Routines */

list_scll_t *concat_list_scll(list_scll_t *p_list1, list_scll_t *p_list2);
list_scll_t *merge_list_scll(list_scll_t *p_list1, list_scll_t *p_list2);
list_scll_t *get_reversed_list_scll(list_scll_t *p_list);
status_t reverse_list_scll(list_scll_t *p_list);
status_t append_list_scll(list_scll_t *p_list1, list_scll_t *p_list2);
status_t list_to_array_scll(list_scll_t *p_list, data_t **pp_data_array, size_t *p_size);
list_scll_t *array_to_list_scll(data_t *p_array, size_t arr_size);

/* List Auxillary Routines */

void generic_insert_scll(node_scll_t *p_beg, node_scll_t *p_mid, node_scll_t *p_end);
void generic_delete_scll(node_scll_t *p_prev_node, node_scll_t *p_delete_node);
node_scll_t *get_list_node_scll(data_t new_data);
node_scll_t *locate_node_scll(list_scll_t *p_list, data_t search_data);

void get_last_node_scll(list_scll_t *p_list, node_scll_t **pp_last_node);
void get_last_node_and_prev_scll(list_scll_t *p_list, node_scll_t **pp_last_node, node_scll_t **pp_prev_node);
void get_node_and_prev_scll(data_t search_data, list_scll_t *p_list, node_scll_t **pp_node, node_scll_t **pp_node_prev);


#endif /* _SCLL_H */
