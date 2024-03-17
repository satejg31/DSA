/*

    @ DATE : 19/10/2023
    @ AUTHOR : SATEJ UPENDRA GANJI
    @ PURPOSE : SERVER IMPLEMENTATION FOR THE DOUBLY LINKED LIST

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/dll.h"


/* List Creation Routine */

list_dll_t *create_list_dll()
{
    node_dll_t *p_new_node = NULL;

    p_new_node = get_list_node_dll(-1);
    return (p_new_node);
}

/* List data insertion Routines */

status_t insert_beginning_dll(list_dll_t *p_list, data_t new_data)
{
    generic_insert_dll(p_list, get_list_node_dll(new_data), p_list->next);
    return (SUCCESS);
}

status_t insert_end_dll(list_dll_t *p_list, data_t new_data)
{
    node_dll_t *p_last_node = NULL;
    get_last_node_dll(p_list, &p_last_node);

    generic_insert_dll(p_last_node, get_list_node_dll(new_data), NULL);
    return (SUCCESS);
}

status_t insert_after_dll(list_dll_t *p_list, data_t new_data, data_t e_data)
{
    node_dll_t *p_existing_node = NULL;
    p_existing_node = locate_list_node_dll(p_list, e_data);

    if(p_existing_node == NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }

    generic_insert_dll(p_existing_node, get_list_node_dll(new_data), p_existing_node->next);
    return (SUCCESS);
}

status_t insert_before_dll(list_dll_t *p_list, data_t new_data, data_t e_data)
{
    node_dll_t *p_existing_node = NULL;
    p_existing_node = locate_list_node_dll(p_list, e_data);

    if(p_existing_node == NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }

    generic_insert_dll(p_existing_node->prev, get_list_node_dll(new_data), p_existing_node);
    return (SUCCESS);
}

/* List data retireval Routines */

status_t get_begin_dll(list_dll_t* p_list, data_t *p_data)
{
    if(is_list_empty_dll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    *p_data = p_list->next->data;
    return (SUCCESS);
}

status_t get_end_dll(list_dll_t *p_list, data_t *p_data)
{
    node_dll_t *p_node = NULL;

    if(is_list_empty_dll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    get_last_node_dll(p_list, &p_node);
    *p_data = p_node->data;

    return (SUCCESS);
    
}

status_t pop_begin_dll(list_dll_t *p_list, data_t *p_popped_data)
{   
    if(is_list_empty_dll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    *p_popped_data = p_list->next->data;
    generic_delete_dll(p_list->next);

    return (SUCCESS);
}

status_t pop_end_dll(list_dll_t *p_list, data_t *p_popped_data)
{
    node_dll_t *p_last_node = NULL;

    if(is_list_empty_dll(p_list) == TRUE)
    {
        return(LIST_EMPTY);
    }

    get_last_node_dll(p_list, &p_last_node);
    *p_popped_data = p_last_node->data;
    generic_delete_dll(p_last_node);

    return (SUCCESS);
}

/* List Data Removal Routines */

status_t remove_begin_dll(list_dll_t *p_list)
{
    if(is_list_empty_dll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    generic_delete_dll(p_list->next);
    return (SUCCESS);
}

status_t remove_end_dll(list_dll_t *p_list)
{
    node_dll_t *p_last_node = NULL;
    if(is_list_empty_dll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    get_last_node_dll(p_list, &p_last_node);
    generic_delete_dll(p_last_node);

    return (SUCCESS);
    
}

status_t remove_data_dll(list_dll_t *p_list, data_t remove_data)
{
    node_dll_t *p_existing_node = NULL;
    if(is_list_empty_dll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    p_existing_node = locate_list_node_dll(p_list, remove_data);
    if(p_existing_node == NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }

    generic_delete_dll(p_existing_node);
    return (SUCCESS);
}

/* List Query Routines */

bool is_list_empty_dll(list_dll_t *p_list)
{
    return (p_list->next == NULL && p_list->prev == NULL);
}

len_t get_list_length_dll(list_dll_t *p_list)
{
    node_dll_t *p_run_node = NULL;
    len_t list_length = 0;
    
    p_run_node = p_list->next;
    while(p_run_node != NULL)
    {
        ++list_length;
        p_run_node = p_run_node->next;
    }

    return (list_length);
}

int get_element_count_dll(list_dll_t *p_list, data_t element_data)
{
    node_dll_t *p_run_node = NULL;
    int count = 0;

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

bool list_contains_dll(list_dll_t *p_list, data_t element_data)
{
    node_dll_t *p_node = NULL;
    p_node = locate_list_node_dll(p_list, element_data);

    if(p_node == NULL)
    {
        return (FALSE);
    }
    else
    {
        return (TRUE);
    }
}   

void show_list_dll(list_dll_t *p_list, const char *msg)
{
    if(msg)
    {
        puts(msg);
    }

    printf("[START]<->");
    node_dll_t *p_run_node = NULL;
    p_run_node = p_list->next;

    while(p_run_node != NULL)
    {
        printf("[%d]<->", p_run_node->data);
        p_run_node = p_run_node->next;
    }

    printf("[END]\n\n\n");
}

/* List Deletion Routines */

status_t destroy_list_dll(list_dll_t **pp_list)
{
    list_dll_t *p_list = *pp_list;
    node_dll_t *p_run_node = NULL;
    node_dll_t *p_run_next_node = NULL;

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

list_dll_t *concat_list_dll(list_dll_t *p_list1, list_dll_t *p_list2)
{
    list_dll_t *p_new_list = NULL;
    node_dll_t *p_run_node = NULL;

    p_new_list = create_list_dll();
    p_run_node = p_list1->next;

    while(p_run_node != NULL)
    {
        insert_end_dll(p_new_list, p_run_node->data);
        p_run_node = p_run_node->next;
    }

    p_run_node = p_list2->next;

    while(p_run_node != NULL)
    {
        insert_end_dll(p_new_list, p_run_node->data);
        p_run_node = p_run_node->next;
    }

    return (p_new_list);
}

list_dll_t *merge_list_dll(list_dll_t *p_list1, list_dll_t *p_list2)
{
    list_dll_t *p_new_list = NULL;
    node_dll_t *p_run_node1 = NULL;
    node_dll_t *p_run_node2 = NULL;

    p_run_node1 = p_list1->next;
    p_run_node2 = p_list2->next;
    p_new_list = create_list_dll();

    while(1)
    {
        if(p_run_node1 == NULL)
        {
            while(p_run_node2 != NULL)
            {
                insert_end_dll(p_new_list, p_run_node2->data);
                p_run_node2 = p_run_node2->next;
            }

            break;
        }

        if(p_run_node2 == NULL)
        {
            while(p_run_node1 != NULL)
            {
                insert_end_dll(p_new_list, p_run_node1->data);
                p_run_node1 = p_run_node1->next;
            }

            break;
        }

        if(p_run_node1->data < p_run_node2->data)
        {
            insert_end_dll(p_new_list, p_run_node1->data);
            p_run_node1 = p_run_node1->next;
        }
        else
        {
            insert_end_dll(p_new_list, p_run_node2->data);
            p_run_node2 = p_run_node2->next;
        }
    }

    return (p_new_list);
}

list_dll_t *get_reversed_list_dll(list_dll_t *p_list)
{
    list_dll_t *p_new_list = NULL;
    node_dll_t *p_run_node = NULL;

    p_new_list = create_list_dll();
    p_run_node = p_list->next;

    while(p_run_node != NULL)
    {
        insert_beginning_dll(p_new_list, p_run_node->data);
        p_run_node = p_run_node->next;
    }

    return (p_new_list);
}

status_t reverse_list_dll(list_dll_t *p_list)
{
    node_dll_t *p_run_node = NULL;
    node_dll_t *p_run_next_node = NULL;

    if(p_list->next == NULL || p_list->next->next == NULL)
        return (SUCCESS);

    p_run_node = p_list->next->next;
    p_list->next->next = NULL;

    while(p_run_node != NULL)
    {
        p_run_next_node = p_run_node->next;
        generic_insert_dll(p_list, p_run_node, p_list->next);
        p_run_node = p_run_next_node;
    }

    return (SUCCESS);
}

status_t append_list_dll(list_dll_t *p_list1, list_dll_t *p_list2)
{
    node_dll_t *p_last_node_p_list1 = NULL;
    
    get_last_node_dll(p_list1, &p_last_node_p_list1);

    p_last_node_p_list1->next = p_list2->next;

    free(p_list2);
    return (SUCCESS);

}

status_t list_to_array_dll(list_dll_t *p_list, data_t **pp_data_array, size_t *p_size)
{
    node_dll_t *p_run_node = NULL;
    len_t list_length = 0;
    data_t *p_data_array = NULL;
    list_length = get_list_length_dll(p_list);
    if(list_length <= 0)
    {
        return (LIST_EMPTY);
    }

    int i = 0;

    p_data_array = (data_t *)xmalloc(list_length * sizeof(data_t));
    p_run_node = p_list->next;
    while(p_run_node != NULL)
    {
        *(p_data_array + i) = p_run_node->data;
        p_run_node = p_run_node->next;
        ++i;
    }

    *pp_data_array = p_data_array;
    *p_size = list_length;

    return (SUCCESS);
}

list_dll_t *array_to_list_dll(data_t *p_array, size_t arr_size)
{
    list_dll_t *p_new_list = NULL;
    int i = 0;

    p_new_list = create_list_dll();
    while(i < arr_size)
    {
        insert_end_dll(p_new_list, *(p_array + i));
        ++i;
    }

    return (p_new_list);
}

/* List Auxillary Routines */

void generic_insert_dll(node_dll_t *p_beg, node_dll_t *p_mid, node_dll_t *p_end)
{
    p_mid->next = p_end;
    p_mid->prev = p_beg;

    if(p_beg != NULL)
    {
        p_beg->next = p_mid;
    }
    if(p_end != NULL)
    {
        p_end->prev = p_mid;
    }
}

void generic_delete_dll(node_dll_t *p_delete_node)
{
    if(p_delete_node->next != NULL)
    {
        p_delete_node->next->prev = p_delete_node->prev;
    }

    if(p_delete_node->prev != NULL)
    {
        p_delete_node->prev->next = p_delete_node->next;
    }

    free(p_delete_node);
}

node_dll_t *get_list_node_dll(data_t new_data)
{
    node_dll_t *p_new_node = NULL;

    p_new_node = (node_dll_t *)xmalloc(sizeof(node_dll_t));
    
    p_new_node->data = new_data;
    p_new_node->next = NULL;
    p_new_node->prev = NULL;

    return (p_new_node);
}

node_dll_t *locate_list_node_dll(list_dll_t *p_list, data_t search_data)
{
    node_dll_t *p_node = NULL;

    p_node = p_list->next;
    while(p_node != NULL)
    {
        if(p_node->data == search_data)
            return (p_node);

        p_node = p_node->next;
    }

    return (NULL);
}

void get_last_node_dll(list_dll_t *p_list, node_dll_t **pp_last_node)
{
    node_dll_t *p_run_node = NULL;
    p_run_node = p_list;

    while(p_run_node->next != NULL)
    {
        p_run_node = p_run_node->next;
    }

    *pp_last_node = p_run_node;
}

