
/*

    @ DATE : 19/10/2023
    @ AUTHOR : SATEJ UPENDRA GANJI
    @ PURPOSE : SERVER SIDE IMPLEMENTATION FOR THE SINGLY CIRCULAR LINKED LIST
    
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/scll.h"


/* List Creation Routine */

list_scll_t *create_list_scll(void)
{
    node_scll_t *p_new_node = NULL;
    p_new_node = get_list_node_scll(-1);
    p_new_node->next = p_new_node;

    return (p_new_node);
}

/* List Data Insertion Routines */

status_t insert_beginning_scll(list_scll_t *p_list, data_t new_data)
{
    generic_insert_scll(p_list, get_list_node_scll(new_data), p_list->next);
    return (SUCCESS);
}

status_t insert_end_scll(list_scll_t *p_list, data_t new_data)
{
    node_scll_t *p_last_node = NULL;
    get_last_node_scll(p_list, &p_last_node);
    generic_insert_scll(p_last_node, get_list_node_scll(new_data), p_last_node->next);

    return (SUCCESS);
}

status_t insert_after_scll(list_scll_t *p_list, data_t new_data, data_t e_data)
{
    node_scll_t *p_existing_node = NULL;
    p_existing_node = locate_node_scll(p_list, e_data);
    
    if(p_existing_node == NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }

    generic_insert_scll(p_existing_node, get_list_node_scll(new_data), p_existing_node->next);
    return (SUCCESS);
}

status_t insert_before_scll(list_scll_t *p_list, data_t new_data, data_t e_data)
{
    node_scll_t *p_existing_node = NULL;
    node_scll_t *p_prev_node = NULL;
    get_node_and_prev_scll(e_data, p_list, &p_existing_node, &p_prev_node);

    if(p_existing_node == NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }

    generic_insert_scll(p_prev_node, get_list_node_scll(new_data), p_existing_node);
    return (SUCCESS);
}

/* List data retreival Routines */

status_t get_begin_scll(list_scll_t *p_list, data_t *p_data)
{
    if(is_list_empty_scll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    *p_data = p_list->next->data;
    return (SUCCESS);
}

status_t get_end_scll(list_scll_t *p_list, data_t *p_data)
{
    node_scll_t *p_last_node = NULL;

    if(is_list_empty_scll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    get_last_node_scll(p_list, &p_last_node);
    *p_data = p_last_node->data;

    return (SUCCESS);
}

status_t pop_begin_scll(list_scll_t *p_list, data_t *p_popped_data)
{
    if(is_list_empty_scll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    *p_popped_data = p_list->next->data;
    generic_delete_scll(p_list, p_list->next);

    return (SUCCESS);
}

status_t pop_end_scll(list_scll_t *p_list, data_t *p_popped_data)
{
    node_scll_t *p_last_node = NULL;
    node_scll_t *p_last_prev_node = NULL;

    if(is_list_empty_scll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    get_last_node_and_prev_scll(p_list, &p_last_node, &p_last_prev_node);
    *p_popped_data = p_last_node->data;
    generic_delete_scll(p_last_prev_node, p_last_node);

    return (SUCCESS);
}

/* List Data Removal Rouutines */

status_t remove_begin_scll(list_scll_t *p_list)
{
    if(is_list_empty_scll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    generic_delete_scll(p_list, p_list->next);
    return (SUCCESS);
}

status_t remove_end_scll(list_scll_t *p_list)
{
    node_scll_t *p_last_node = NULL;
    node_scll_t *p_last_prev_node = NULL;

    if(is_list_empty_scll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    get_last_node_and_prev_scll(p_list, &p_last_node, &p_last_prev_node);
    generic_delete_scll(p_last_prev_node, p_last_node);

    return (SUCCESS);
}

status_t remove_data_scll(list_scll_t *p_list, data_t remove_data)
{
    node_scll_t *p_remove_node = NULL;
    node_scll_t *p_remove_node_prev = NULL;
    
    if(is_list_empty_scll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    get_node_and_prev_scll(remove_data, p_list, &p_remove_node, &p_remove_node_prev);
    if(p_remove_node == NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }

    generic_delete_scll(p_remove_node_prev, p_remove_node);
    return (SUCCESS);
}

/* List Query Routines */

len_t get_list_length_scll(list_scll_t *p_list)
{
    len_t list_length = 0;
    node_scll_t *p_run_node = NULL;

    p_run_node = p_list->next;
    while(p_run_node != p_list)
    {
        ++list_length;
        p_run_node = p_run_node->next;
    }

    return (list_length);
}

bool is_list_empty_scll(list_scll_t *p_list)
{
    return (p_list->next == p_list);
}

int get_element_count_scll(list_scll_t *p_list, data_t element_data)
{
    int count = 0;
    node_scll_t *p_run_node = NULL;
    p_run_node = p_list->next;

    while(p_run_node != p_list)
    {
        if(element_data == p_run_node->data)
        {
            ++count;
        }

        p_run_node = p_run_node->next;
    }

    return (count);
}

bool list_contains_scll(list_scll_t *p_list, data_t element_data)
{
    return (locate_node_scll(p_list, element_data) != NULL);
}

void show_list_scll(list_scll_t *p_list, const char* msg)
{   
    node_scll_t *p_run_node = NULL;
    if(msg)
    {
        puts(msg);
    }

    p_run_node = p_list->next;
    printf("[START]->");
    while(p_run_node != p_list)
    {
        printf("[%d]->", p_run_node->data);
        p_run_node = p_run_node->next;
    }

    printf("[END]\n\n\n");
}

/* List deletion Routines */

status_t destroy_list_scll(list_scll_t **pp_list)
{   
    list_scll_t *p_list = *pp_list;
    node_scll_t *p_run_node = NULL;
    node_scll_t *p_run_next_node = NULL;

    p_run_node = p_list->next;
    while(p_run_node != p_list)
    {
        p_run_next_node = p_run_node->next;
        free(p_run_node);
        p_run_node = p_run_next_node;
    }

    free(p_list);
    *pp_list = NULL;

    return (SUCCESS);
}

/* List operation Routines */

list_scll_t *concat_list_scll(list_scll_t *p_list1, list_scll_t *p_list2)
{
    list_scll_t *p_new_list = NULL;
    node_scll_t *p_run_node = NULL;

    p_new_list = create_list_scll();
    p_run_node = p_list1->next;
    while(p_run_node != p_list1)
    {
        insert_end_scll(p_new_list, p_run_node->data);
        p_run_node = p_run_node->next;
    }

    p_run_node = p_list2->next;
    while(p_run_node != p_list2)
    {
        insert_end_scll(p_new_list, p_run_node->data);
        p_run_node = p_run_node->next;
    }
    
    return (p_new_list);
}

list_scll_t *merge_list_scll(list_scll_t *p_list1, list_scll_t *p_list2)
{
    list_scll_t *p_new_list = NULL;

    node_scll_t *p_run_node1 = NULL;
    node_scll_t *p_run_node2 = NULL;

    p_new_list = create_list_scll();

    p_run_node1 = p_list1->next;
    p_run_node2 = p_list2->next;

    while(1)
    {
        if(p_run_node1 == p_list1)
        {
            while(p_run_node2 != p_list2)
            {
                insert_end_scll(p_new_list, p_run_node2->data);
                p_run_node2 = p_run_node2->next;
            }

            break;
        }

        if(p_run_node2 == p_list2)
        {
            while(p_run_node1 != p_list1)
            {
                insert_end_scll(p_new_list, p_run_node1->data);
                p_run_node1 = p_run_node1->next;
            }

            break;
        }

        if(p_run_node1->data <= p_run_node2->data)
        {
            insert_end_scll(p_new_list, p_run_node1->data);
            p_run_node1 = p_run_node1->next;
        }
        else 
        {
            insert_end_scll(p_new_list, p_run_node2->data);
            p_run_node2 = p_run_node2->next;
        }
    }

    return (p_new_list);
}

list_scll_t *get_reversed_list_scll(list_scll_t *p_list)
{
    list_scll_t *p_new_list = NULL;
    node_scll_t *p_run_node = NULL;

    p_new_list = create_list_scll();
    p_run_node = p_list->next;
    while(p_run_node != p_list)
    {
        insert_beginning_scll(p_new_list, p_run_node->data);
        p_run_node = p_run_node->next;
    }

    return (p_new_list);
}   

status_t reverse_list_scll(list_scll_t *p_list)
{
    node_scll_t *p_run_node = NULL;
    node_scll_t *p_run_next_node = NULL;

    if(p_list->next == p_list && p_list->next->next == p_list)
    {
        return (SUCCESS);
    }

    p_run_node = p_list->next->next;
    p_list->next->next = p_list;

    while(p_run_node != p_list)
    {
        p_run_next_node = p_run_node->next;
        generic_insert_scll(p_list, p_run_node, p_list->next);
        p_run_node = p_run_next_node;
    }

    return (SUCCESS);
}

status_t append_list_scll(list_scll_t *p_list1, list_scll_t *p_list2)
{
    node_scll_t *last_node_of_p_list1 = NULL;
    node_scll_t *last_node_of_p_list2 = NULL;
    
    get_last_node_scll(p_list1, &last_node_of_p_list1);
    get_last_node_scll(p_list2, &last_node_of_p_list2);

    last_node_of_p_list1->next = p_list2->next;
    last_node_of_p_list2->next = p_list1;

    free(p_list2);
    return (SUCCESS);
    
}

status_t list_to_array_scll(list_scll_t *p_list, data_t **pp_data_array, size_t *p_size)
{
    len_t list_length = 0;
    node_scll_t *p_run_node = NULL;
    data_t *p_array = NULL;
    int i = 0;

    list_length = get_list_length_scll(p_list);
    if(list_length <= 0)
    {
        return (LIST_EMPTY);
    }

    p_array = (data_t *)xmalloc(list_length * sizeof(data_t));

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
}

list_scll_t *array_to_list_scll(data_t *p_array, size_t arr_size)
{
    list_scll_t *p_new_list = NULL;
    p_new_list = create_list_scll();

    int i = 0;
    while(i < arr_size)
    {
        insert_end_scll(p_new_list, *(p_array + i));
        ++i;
    }

    return (p_new_list);
}

/* List Auxillary Routines */

void generic_insert_scll(node_scll_t *p_beg, node_scll_t *p_mid, node_scll_t *p_end)
{
    p_beg->next = p_mid;
    p_mid->next = p_end;

}

void generic_delete_scll(node_scll_t *p_prev_node ,node_scll_t *p_delete_node)
{
    p_prev_node->next = p_delete_node->next;
    free(p_delete_node);
}

node_scll_t *get_list_node_scll(data_t new_data)
{
    node_scll_t *p_new_node = NULL;
    p_new_node = (node_scll_t *)xmalloc(sizeof(node_scll_t));

    p_new_node->data = new_data;
    p_new_node->next = NULL;

    return (p_new_node);
}

node_scll_t *locate_node_scll(list_scll_t *p_list, data_t search_data)
{
    node_scll_t *p_run_node = NULL;
    p_run_node = p_list->next;

    while(p_run_node != p_list)
    {
        if(p_run_node->data == search_data)
        {
            return (p_run_node);
        }

        p_run_node = p_run_node->next;
    }

    return (NULL);
}

void get_last_node_scll(list_scll_t *p_list, node_scll_t **pp_last_node)
{
    node_scll_t *p_run_node = NULL;
    p_run_node = p_list->next;

    while(p_run_node->next != p_list)
    {
        p_run_node = p_run_node->next;
    }

    *pp_last_node = p_run_node;

}

void get_last_node_and_prev_scll(list_scll_t *p_list, node_scll_t **pp_last_node, node_scll_t **pp_prev_node)
{
    node_scll_t *p_run_node = NULL;
    node_scll_t *p_last_prev_node = NULL;

    p_run_node = p_list->next;
    while(p_run_node->next != p_list)
    {
        p_last_prev_node = p_run_node;
        p_run_node = p_run_node->next;
    }

    *pp_prev_node = p_last_prev_node;
    *pp_last_node = p_run_node; 
}

void get_node_and_prev_scll(data_t search_data, list_scll_t *p_list, node_scll_t **pp_node, node_scll_t **pp_node_prev)
{
    node_scll_t *p_run_node = NULL;
    node_scll_t *p_run_prev_node = NULL;

    p_run_node = p_list->next;
    p_run_prev_node = p_list;
    while(p_run_node != p_list)
    {
        if(p_run_node->data == search_data)
        {
            *pp_node = p_run_node;
            *pp_node_prev = p_run_prev_node;

            break;
        }

        p_run_prev_node = p_run_node;
        p_run_node = p_run_node->next;
    }

    *pp_node = p_run_node;
    *pp_node_prev = p_run_prev_node;
}

