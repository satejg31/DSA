
/*
   
    @ DATE : 22/10/2023
    @ AUTHOR : SATEJ UPENDRA GANJI
    @ PURPOSE : SERVER IMPLEMENTATION FOR THE SINGLY LINKED LIST 
                
*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/sll.h"

/* List Creation Routine */

list_sll_t *create_list_sll()
{
    node_sll_t *p_head_node = NULL;
    p_head_node = get_list_node_sll(-1);

    return (p_head_node);
}

/* List Data Insertion Routines */

status_t insert_beginning_sll(list_sll_t *p_list, data_t new_data)
{
    generic_insert_sll(p_list, get_list_node_sll(new_data), p_list->next);
    return (SUCCESS);
}

status_t insert_end_sll(list_sll_t *p_list, data_t new_data)
{
    node_sll_t *p_last_node = NULL;
    get_last_node_sll(p_list, &p_last_node);

    generic_insert_sll(p_last_node, get_list_node_sll(new_data), p_last_node->next);
    return (SUCCESS);
}

status_t insert_after_sll(list_sll_t *p_list, data_t new_data, data_t e_data)
{
    node_sll_t *p_existing_node = NULL;
    p_existing_node = locate_node_sll(p_list, e_data);

    if(p_existing_node == NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }

    generic_insert_sll(p_existing_node, get_list_node_sll(new_data), p_existing_node->next);
    return (SUCCESS);
}

status_t insert_before_sll(list_sll_t *p_list, data_t new_data, data_t e_data)
{
    node_sll_t *p_existing_node = NULL;
    node_sll_t *p_prev_node = NULL;

    get_node_and_prev_sll(p_list, e_data, &p_existing_node, &p_prev_node);
    if(p_existing_node == NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }

    generic_insert_sll(p_prev_node, get_list_node_sll(new_data), p_existing_node);
    return (SUCCESS);
}

/* List Data Retreival Routines */

status_t get_begin_sll(list_sll_t *p_list, data_t *p_beg_data)
{
    if(is_list_empty_sll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    *p_beg_data = p_list->next->data;
    return (SUCCESS);
}

status_t get_end_sll(list_sll_t *p_list, data_t *p_end_data)
{
    node_sll_t *p_last_node = NULL;

    if(is_list_empty_sll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    get_last_node_sll(p_list, &p_last_node);
    *p_end_data = p_last_node->data;

    return (SUCCESS);
    
}

status_t pop_begin_sll(list_sll_t *p_list, data_t *p_popped_data)
{
    if(is_list_empty_sll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    *p_popped_data = p_list->next->data;
    generic_delete_sll(p_list, p_list->next);

    return (SUCCESS);
}

status_t pop_end_sll(list_sll_t *p_list, data_t *p_popped_data)
{
    node_sll_t *p_last_node = NULL;
    node_sll_t *p_last_prev_node = NULL;

    if(is_list_empty_sll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    get_last_node_and_prev_sll(p_list, &p_last_node, &p_last_prev_node);
    *p_popped_data = p_last_node->data;
    generic_delete_sll(p_last_prev_node, p_last_node);
    return (SUCCESS);
}

/* List Data Removal Routines */

status_t remove_begin_sll(list_sll_t *p_list)
{
    if(is_list_empty_sll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    generic_delete_sll(p_list, p_list->next);
    return (SUCCESS);
}

status_t remove_end_sll(list_sll_t *p_list)
{
    node_sll_t *p_last_node = NULL;
    node_sll_t *p_last_prev_node = NULL;

    if(is_list_empty_sll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    get_last_node_and_prev_sll(p_list, &p_last_node, &p_last_prev_node);
    generic_delete_sll(p_last_prev_node, p_last_node);

    return (SUCCESS);
}

status_t remove_data_sll(list_sll_t *p_list, data_t r_data)
{
    node_sll_t *p_existing_node = NULL;
    node_sll_t *p_existing_prev_node = NULL;

    get_node_and_prev_sll(p_list, r_data, &p_existing_node, &p_existing_prev_node);
    if(p_existing_node == NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }

    generic_delete_sll(p_existing_prev_node, p_existing_node);
    return (SUCCESS);
}

/* List Query Routines */

len_t get_list_length_sll(list_sll_t *p_list)
{
    len_t list_length = 0;
    node_sll_t *p_run_node = NULL;

    p_run_node = p_list->next;
    while(p_run_node != NULL)
    {
        ++list_length;
        p_run_node = p_run_node->next;
    }

    return (list_length);
}

bool is_list_empty_sll(list_sll_t *p_list)
{
    return (p_list->next == NULL);
}

int get_element_count_sll(list_sll_t *p_list, data_t element_data)
{
    int count = 0;
    node_sll_t *p_run_node = NULL;

    p_run_node = p_list->next;
    while(p_run_node != NULL)
    {
        if(p_run_node->data == element_data)
        {
            ++count;
        }

        p_run_node = p_run_node->next;
    }

    return (count);
}

bool list_contains_sll(list_sll_t *p_list, data_t element_data)
{
    return (locate_node_sll(p_list, element_data) != NULL);
}

void show_list_sll(list_sll_t *p_list, const char *msg)
{
    node_sll_t *p_run_node = NULL;
    if(msg)
    {
        puts(msg);
    }

    printf("[START]->");
    p_run_node = p_list->next;
    while(p_run_node != NULL)
    {
        printf("[%d]->", p_run_node->data);
        p_run_node = p_run_node->next;
    }

    printf("[END]\n\n\n");
}

/* List Deletion Routine */

status_t destroy_list_sll(list_sll_t **pp_list)
{
    list_sll_t *p_list = *pp_list;
    node_sll_t *p_run_node = NULL;
    node_sll_t *p_run_next_node = NULL;

    p_run_node = p_list->next;
    while(p_run_node != NULL)
    {
        p_run_next_node = p_run_node->next;
        free(p_run_node);
        p_run_node = p_run_next_node;
    }

    free(p_list);
    *pp_list = NULL;
    return (SUCCESS);
}

/* List Operation Routines */

list_sll_t *concat_list_sll(list_sll_t *p_list1, list_sll_t *p_list2)
{
    list_sll_t *p_new_list = NULL;
    node_sll_t *p_run_node = NULL;

    p_new_list = create_list_sll();
    
    p_run_node = p_list1->next;
    while(p_run_node != NULL)
    {
        insert_end_sll(p_new_list, p_run_node->data);
        p_run_node = p_run_node->next;
    }

    p_run_node = p_list2->next;
    while(p_run_node != NULL)
    {
        insert_end_sll(p_new_list, p_run_node->data);
        p_run_node = p_run_node->next;
    }

    return (p_new_list);
}

list_sll_t *merge_list_sll(list_sll_t *p_list1, list_sll_t *p_list2)
{
    node_sll_t *p_run_node1 = NULL;
    node_sll_t *p_run_node2 = NULL;

    list_sll_t *p_new_list = NULL;
    
    p_new_list = create_list_sll();
    p_run_node1 = p_list1->next;
    p_run_node2 = p_list2->next;

    while(1)
    {
        if(p_run_node1 == NULL)
        {
            while(p_run_node2 != NULL)
            {
                insert_end_sll(p_new_list, p_run_node2->data);
                p_run_node2 = p_run_node2->next;
            }
            break;
        }

        if(p_run_node2 == NULL)
        {
            while(p_run_node1 != NULL)
            {
                insert_end_sll(p_new_list, p_run_node1->data);
                p_run_node1 = p_run_node1->next;
            }
            break;
        }

        if(p_run_node1->data <= p_run_node2->data)
        {
            insert_end_sll(p_new_list, p_run_node1->data);
            p_run_node1 = p_run_node1->next;
        }
        else
        {
            insert_end_sll(p_new_list, p_run_node2->data);
            p_run_node2 = p_run_node2->next;
        }
    }

    return (p_new_list);
}

list_sll_t *get_reversed_list_sll(list_sll_t *p_list)
{
    node_sll_t *p_run_node = NULL;
    list_sll_t *p_new_list = NULL;

    p_new_list = create_list_sll();
    p_run_node = p_list->next;

    while(p_run_node != NULL)
    {
        insert_beginning_sll(p_new_list, p_run_node->data);
        p_run_node = p_run_node->next;
    }

    return (p_new_list);
}

status_t append_list_sll(list_sll_t *p_list1, list_sll_t *p_list2)
{
    node_sll_t *p_last_node_of_p_list1 = NULL;
    
    get_last_node_sll(p_list1, &p_last_node_of_p_list1);

    p_last_node_of_p_list1->next = p_list2->next;
    free(p_list2);
    return (SUCCESS);
}

status_t reverse_list_sll(list_sll_t *p_list)
{
    node_sll_t *p_run_node = NULL;
    node_sll_t *p_run_node_next = NULL;

    if(p_list->next == NULL && p_list->next->next == NULL)
    {
        return (SUCCESS);
    }

    p_run_node = p_list->next->next;
    p_list->next->next = NULL;

    while(p_run_node != NULL)
    {
        p_run_node_next = p_run_node->next;
        generic_insert_sll(p_list, p_run_node, p_list->next);
        p_run_node = p_run_node_next;
    }

    return (SUCCESS);
}

status_t list_to_array_sll(list_sll_t *p_list, data_t **pp_data_array, size_t *p_size)
{
    len_t list_length = 0;
    node_sll_t *p_run_node = NULL;
    data_t *p_array = NULL;
    int i = 0;

    list_length = get_list_length_sll(p_list);
    if(list_length <= 0)
    {
        return (LIST_EMPTY);
    }

    p_array = (data_t *)xmalloc(sizeof(data_t) * list_length);
    
    p_run_node = p_list->next;
    i = 0;
    while(i < list_length)
    {
        *(p_array + i) = p_run_node->data;
        ++i;
        p_run_node = p_run_node->next;
    }
    
    *pp_data_array = p_array;
    *p_size = list_length;

    return (SUCCESS);
}

list_sll_t *array_to_list_sll(data_t *p_array, size_t arr_size)
{
    list_sll_t *p_new_list = NULL;
    p_new_list = create_list_sll();

    int i = 0;
    while(i < arr_size)
    {
        insert_end_sll(p_new_list, *(p_array + i));
        ++i;
    }

    return (p_new_list);
}


/* List Auxillary routines */

void generic_insert_sll(node_sll_t *p_beg, node_sll_t *p_mid, node_sll_t *p_end)
{
    p_beg->next = p_mid;
    p_mid->next = p_end;
}

void generic_delete_sll(node_sll_t *p_prev_node, node_sll_t *p_delete_node)
{   
    p_prev_node->next = p_delete_node->next;
    free(p_delete_node);
}

void get_last_node_sll(list_sll_t *p_list, node_sll_t **pp_last_node)
{
    node_sll_t *p_run_node = NULL;

    p_run_node = p_list;
    while(p_run_node->next != NULL)
    {
        p_run_node = p_run_node->next;
    }

    *pp_last_node = p_run_node;
}

void get_node_and_prev_sll(list_sll_t *p_list, data_t s_data, node_sll_t **pp_node, node_sll_t **pp_prev_node)
{
    node_sll_t *p_run_node = NULL;
    node_sll_t *p_run_node_prev = NULL;

    p_run_node = p_list->next;
    p_run_node_prev = p_list;
    while(p_run_node != NULL)
    {
        if(p_run_node->data == s_data)
        {
            *pp_node = p_run_node;
            *pp_prev_node = p_run_node_prev;
            break;
        }


        p_run_node_prev = p_run_node;
        p_run_node = p_run_node->next;
    }

    *pp_node = p_run_node;
    *pp_prev_node = p_run_node_prev;
}

void get_last_node_and_prev_sll(list_sll_t *p_list, node_sll_t **pp_last_node, node_sll_t **pp_prev_node)
{
    node_sll_t *p_run_node = NULL;
    node_sll_t *p_run_node_prev = NULL;

    p_run_node = p_list;
    p_run_node_prev = NULL;

    while(p_run_node->next != NULL)
    {
        p_run_node_prev = p_run_node;
        p_run_node = p_run_node->next;
    }

    *pp_last_node = p_run_node;
    *pp_prev_node = p_run_node_prev;
}

node_sll_t *locate_node_sll(list_sll_t *p_list, data_t search_data)
{
    node_sll_t *p_run_node = NULL;

    p_run_node = p_list->next;
    while(p_run_node != NULL)
    {
        if(p_run_node->data == search_data)
        {
            return (p_run_node);
        }

        p_run_node = p_run_node->next;
    }

    return (p_run_node);
}

node_sll_t *get_list_node_sll(data_t new_data)
{
    node_sll_t *p_new_node = NULL;
    p_new_node = (node_sll_t *)xmalloc(sizeof(node_sll_t));

    p_new_node->data = new_data;
    p_new_node->next = NULL;

    return (p_new_node);
}

