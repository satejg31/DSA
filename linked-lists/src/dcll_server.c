/*

    @ DATE : 19/10/2023
    @ AUTHOR : SATEJ UPENDRA GANJI
    @ PURPOSE : SERVER IMPLEMENTATION FOR THE DOUBLY CIRCULAR LINKED LIST
    

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/dcll.h"


/* List Creation Routine */

list_dcll_t *create_list_dcll(void)
{
    node_dcll_t *p_new_node = NULL;

    p_new_node = get_list_node_dcll(-1);

    p_new_node->prev = p_new_node;
    p_new_node->next = p_new_node;

    return (p_new_node);
}

/* List data Insertion Routines */

status_t insert_beginning_dcll(list_dcll_t *p_list, data_t new_data)
{
    generic_insert_dcll(p_list, get_list_node_dcll(new_data), p_list->next);
    return (SUCCESS);
}

status_t insert_end_dcll(list_dcll_t *p_list, data_t new_data)
{
    generic_insert_dcll(p_list->prev, get_list_node_dcll(new_data), p_list);
    return (SUCCESS);
}

status_t insert_after_dcll(list_dcll_t *p_list, data_t new_data, data_t e_data)
{
    node_dcll_t *p_existing_node = NULL;
    p_existing_node = locate_node_dcll(p_list, e_data);

    if(p_existing_node == NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }

    generic_insert_dcll(p_existing_node, get_list_node_dcll(new_data), p_existing_node->next);
    return (SUCCESS);
}

status_t insert_before_dcll(list_dcll_t *p_list, data_t new_data, data_t e_data)
{
    node_dcll_t *p_existing_node = NULL;
    p_existing_node = locate_node_dcll(p_list, e_data);

    if(p_existing_node == NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }

    generic_insert_dcll(p_existing_node->prev, get_list_node_dcll(new_data), p_existing_node);
    return (SUCCESS);
}

/* List data retreival Routines */

status_t get_begin_dcll(list_dcll_t *p_list, data_t *p_data)
{
    if(is_list_empty_dcll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    *p_data = p_list->next->data;
    return (SUCCESS);
}

status_t get_end_dcll(list_dcll_t *p_list, data_t *p_data)
{
    if(is_list_empty_dcll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    *p_data = p_list->prev->data;
    return (SUCCESS);
}

status_t pop_begin_dcll(list_dcll_t *p_list, data_t *p_popped_data)
{
    if(is_list_empty_dcll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    *p_popped_data = p_list->next->data;
    generic_delete_dcll(p_list->next);
    return (SUCCESS);
}

status_t pop_end_dcll(list_dcll_t *p_list, data_t *p_popped_data)
{
    if(is_list_empty_dcll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    *p_popped_data = p_list->prev->data;
    generic_delete_dcll(p_list->prev);
    return (SUCCESS);
}

/* List Data Removal Routines */

status_t remove_begin_dcll(list_dcll_t *p_list)
{
    if(is_list_empty_dcll(p_list) == TRUE)
    {
        return(LIST_EMPTY);
    }
    
    generic_delete_dcll(p_list->next);
    return (SUCCESS);
}

status_t remove_end_dcll(list_dcll_t *p_list)
{
    if(is_list_empty_dcll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    generic_delete_dcll(p_list->prev);
    return (SUCCESS);
}

status_t remove_data_dcll(list_dcll_t *p_list, data_t remove_data)
{
    node_dcll_t *p_existing_node = NULL;
    if(is_list_empty_dcll(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }

    p_existing_node = locate_node_dcll(p_list, remove_data);
    
    if(p_existing_node == NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }
    else
    {
        generic_delete_dcll(p_existing_node);
        return (SUCCESS);
    }
}

/* List Query Routines */

len_t get_list_length_dcll(list_dcll_t *p_list)
{
    len_t list_length = 0;

    node_dcll_t *p_node = NULL;
    p_node = p_list->next;

    while(p_node != p_list)
    {
        ++list_length;
        p_node = p_node->next; 
    }

    return (list_length);
}

bool is_list_empty_dcll(list_dcll_t *p_list)
{
    return (p_list->next == p_list && p_list->prev == p_list);
}

int get_element_count_dcll(list_dcll_t *p_list, data_t element_data)
{
    node_dcll_t *p_node = NULL;
    int count = 0;

    p_node = p_list->next;
    while(p_node != p_list)
    {
        if(p_node->data == element_data)
            ++count;

        p_node = p_node->next;
    }

    return (count);
}

bool list_contains_dcll(list_dcll_t *p_list, data_t element_data)
{
    return (locate_node_dcll(p_list, element_data) != NULL);
}

void show_list_dcll(list_dcll_t *p_list, const char* msg)
{
    node_dcll_t *p_node = NULL;
    if(msg)
    {
        puts(msg);
    }

    printf("[START]<->");
    p_node = p_list->next;
    while(p_node != p_list)
    {
        printf("[%d]<->", p_node->data);
        p_node = p_node->next;    
    }

    printf("[END]\n\n\n");
}

/* List deletion Routine */

status_t destroy_list_dcll(list_dcll_t **pp_list)
{
    list_dcll_t *p_list = *pp_list;
    node_dcll_t *p_node = NULL;
    node_dcll_t *p_node_next = NULL;

    p_node = p_list->next;
    while(p_node != p_list)
    {
        p_node_next = p_node->next;
        free(p_node);
        p_node = p_node_next;
    }

    free(p_list);
    *pp_list = NULL;

    return (SUCCESS);

}

/* List operation Routines */

list_dcll_t *concat_list_dcll(list_dcll_t *p_list1, list_dcll_t *p_list2)
{
    list_dcll_t *p_new_list = NULL;
    
    node_dcll_t *p_run_node1 = NULL;
    node_dcll_t *p_run_node2 = NULL;

    p_new_list = create_list_dcll();
    
    p_run_node1 = p_list1->next;
    while(p_run_node1 != p_list1)
    {
        insert_end_dcll(p_new_list, p_run_node1->data);
        p_run_node1 = p_run_node1->next;
    }

    p_run_node2 = p_list2->next;
    while(p_run_node2 != p_list2)
    {
        insert_end_dcll(p_new_list, p_run_node2->data);
        p_run_node2 = p_run_node2->next;
    }

    return (p_new_list);

}

list_dcll_t *merge_list_dcll(list_dcll_t *p_list1, list_dcll_t *p_list2)
{
    list_dcll_t *p_new_list = NULL;
    node_dcll_t *p_run_node1 = NULL;
    node_dcll_t *p_run_node2 = NULL;

    p_new_list = create_list_dcll();

    p_run_node1 = p_list1->next;
    p_run_node2 = p_list2->next;

    while(1)
    {
        if(p_run_node1 == p_list1)
        {
            while(p_run_node2 != p_list2)
            {
                insert_end_dcll(p_new_list, p_run_node2->data);
                p_run_node2 = p_run_node2->next;
            }

            break;
        }
        if(p_run_node2 == p_list2)
        {
            while(p_run_node1 != p_list1)
            {
                insert_end_dcll(p_new_list, p_run_node1->data);
                p_run_node1 = p_run_node1->next;
            }

            break;
        }

        if(p_run_node1->data <= p_run_node2->data)
        {
            insert_end_dcll(p_new_list, p_run_node1->data);
            p_run_node1 = p_run_node1->next;
        }
        else
        {
            insert_end_dcll(p_new_list, p_run_node2->data);
            p_run_node2 = p_run_node2->next;
        }
    }

    return (p_new_list);
}

list_dcll_t *get_reversed_list_dcll(list_dcll_t *p_list)
{
    list_dcll_t *p_new_list = NULL;
    node_dcll_t *p_run_node = NULL;

    p_new_list = create_list_dcll();
    p_run_node = p_list->prev;
    while(p_run_node != p_list)
    {
        insert_end_dcll(p_new_list, p_run_node->data);
        p_run_node = p_run_node->prev;
    }

    return (p_new_list);
}

status_t reverse_list_dcll(list_dcll_t *p_list)
{
    node_dcll_t *p_run_node = NULL;
    node_dcll_t *p_run_prev_node = NULL;
    node_dcll_t *p_run_prev_original_node = NULL;

    p_run_prev_original_node = p_list->prev;
    p_run_node = p_list->prev->prev;
    while(p_run_node != p_list)
    {
        p_run_prev_node = p_run_node->prev;
        generic_insert_dcll(p_list->prev, p_run_node, p_list);
        p_run_node = p_run_prev_node;
    }

    p_run_prev_original_node->prev = p_list;
    p_list->next = p_run_prev_original_node;

    return (SUCCESS);
    
}

status_t append_list_dcll(list_dcll_t *p_list1, list_dcll_t *p_list2)
{
    if(is_list_empty_dcll(p_list2) == TRUE)
    {
        return (SUCCESS);
    }

    p_list1->prev->next = p_list2->next;
    p_list2->next->prev = p_list1->prev;
    p_list1->prev = p_list2->prev;
    p_list2->prev->next = p_list1;

    return (SUCCESS);
    
}

status_t list_to_array_dcll(list_dcll_t *p_list, data_t **pp_data_array, size_t *p_size)
{
    node_dcll_t *p_node = NULL;
    len_t list_length = 0;
    data_t *p_array = NULL;

    list_length = get_list_length_dcll(p_list);
    if(list_length <= 0)
    {
        fprintf(stderr, "List is empty");
        return (FAILURE);
    }

    p_array = (data_t *)xmalloc(list_length * sizeof(data_t));
    p_node = p_list->next;
    int i = 0;

    while(p_node != p_list)
    {
        *(p_array + i) = p_node->data;
        p_node = p_node->next;
        ++i;
    }

    *pp_data_array = p_array;
    *p_size = list_length;

    return (SUCCESS);

}

list_dcll_t *array_to_list_dcll(data_t *p_array, size_t arr_size)
{
    list_dcll_t *p_new_list = NULL;
    int i = 0;

    p_new_list = create_list_dcll();
    while(i < arr_size)
    {
        insert_end_dcll(p_new_list, *(p_array + i));
        i++;
    }
    
    return (p_new_list);
}

/* List Auxillary Routines */

void generic_insert_dcll(node_dcll_t *p_beg, node_dcll_t *p_mid, node_dcll_t *p_end)
{
    p_mid->next = p_end;
    p_mid->prev = p_beg;
    p_beg->next = p_mid;
    p_end->prev = p_mid;
}

void generic_delete_dcll(node_dcll_t *p_delete_node)
{
    p_delete_node->prev->next = p_delete_node->next;
    p_delete_node->next->prev = p_delete_node->prev;

    free(p_delete_node);
    p_delete_node = NULL;
}

node_dcll_t *get_list_node_dcll(data_t new_data)
{
    node_dcll_t *p_new_node = NULL;

    p_new_node = (node_dcll_t *)xmalloc(sizeof(node_dcll_t));

    p_new_node->data = new_data;
    p_new_node->next = NULL;
    p_new_node->prev = NULL;

    return (p_new_node);
}

node_dcll_t *locate_node_dcll(list_dcll_t *p_list, data_t search_data)
{
    node_dcll_t *p_node = NULL;

    p_node = p_list->next;
    while(p_node != p_list)
    {
        if(p_node->data == search_data)
        {
            return (p_node);
        }

        p_node = p_node->next;
    }

    return (NULL);
}

