#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

/* interface routines */

list_t *create_list(void)
{
	node_t *p_new_node = NULL;
	p_new_node = get_list_node(0);

	p_new_node->prev = p_new_node;
	p_new_node->next = p_new_node;

	return (p_new_node);
}

status_t insert_beg(list_t *p_list, data_t new_data)
{
	generic_insert(p_list, get_list_node(new_data), p_list->next);
	return (SUCCESS);
}

status_t insert_end(list_t *p_list, data_t new_data)
{
	generic_insert(p_list->prev, get_list_node(new_data), p_list);
	return (SUCCESS);
}

status_t insert_before(list_t *p_list, data_t e_data, data_t new_data)
{
	node_t *e_node = NULL;

	e_node = locate_node(p_list, e_data);
	if(e_node == NULL)
	{
		return (LIST_DATA_NOT_FOUND);
	}

	generic_insert(e_node, get_list_node(new_data), e_node->next);

	return (SUCCESS);
}

status_t insert_after(list_t *p_list, data_t e_data, data_t new_data)
{
	node_t *e_node = NULL;

	e_node = locate_node(p_list, e_data);
	if(e_node == NULL)
	{
		return (LIST_DATA_NOT_FOUND);
	}

	generic_insert(e_node->prev, get_list_node(new_data), e_node);

	return (SUCCESS);
}

status_t get_beg(list_t *p_list, data_t *p_data)
{
	if(is_list_empty(p_list) == TRUE)
	{
		return (LIST_EMPTY);
	}

	*p_data = p_list->next->data;

	return (SUCCESS);
}

status_t get_end(list_t *p_list, data_t *p_data)
{
	if(is_list_empty(p_list) == TRUE)
	{
		return (LIST_EMPTY);
	}

	*p_data = p_list->prev->data;

	return (SUCCESS);
}

status_t pop_beg(list_t *p_list, data_t *p_data)
{
	if(is_list_empty(p_list) == TRUE)
	{
		return (LIST_EMPTY);
	}

	*p_data = p_list->next->data;
	generic_delete(p_list->next);
	return(SUCCESS);
}

status_t pop_end(list_t *p_list, data_t *p_data)
{
	if(is_list_empty(p_list) == TRUE)
	{
		return (LIST_EMPTY);
	}

	*p_data = p_list->prev->data;
	generic_delete(p_list->prev);

	return (SUCCESS);
}

status_t remove_beg(list_t *p_list)
{
	if(is_list_empty(p_list) == TRUE)
	{
		return (LIST_EMPTY);
	}

	generic_delete(p_list->next);

	return (SUCCESS);
}

status_t remove_end(list_t *p_list)
{
	if(is_list_empty(p_list) == TRUE)
	{
		return (LIST_EMPTY);
	}

	generic_delete(p_list->prev);

	return (SUCCESS);
}

status_t remove_data(list_t *p_list, data_t r_data)
{
	node_t *r_node = NULL;

	r_node = locate_node(p_list, r_data);
	if(r_node == NULL)
	{
		return (LIST_DATA_NOT_FOUND);
	}

	generic_delete(r_node);
	return (SUCCESS);
}

len_t get_length(list_t *p_list)
{
	node_t *p_run = NULL;
	len_t length = 0;

	for(p_run = p_list->next; 
		p_run != p_list;
		p_run = p_run->next)
	{
		length++;
	}

	return(length);
}

bool contains(list_t *p_list, data_t search_data)
{
	return (locate_node(p_list, search_data) != NULL);
}

bool is_list_empty(list_t *p_list)
{
	return ((p_list->next == p_list) && (p_list->prev == p_list));
}

int get_repeat_count(list_t *p_list, data_t search_data)
{
	int count = 0;
	node_t *p_run = NULL;

	for(p_run = p_list->next;
		p_run != p_list;
		p_run = p_run->next)
	{
		if(search_data == p_run->data)
			count++;
	}

	return (count);
}

void show_list(list_t *p_list, const char* msg)
{
	node_t *p_run = NULL;

	if(msg)
	{
		puts(msg);
	}

	printf("[BEG]<->");
	for(p_run = p_list->next;
		p_run != p_list;
		p_run = p_run->next)
	{
		printf("[%d]<->", p_run->data);
	}

	printf("[END]\n\n");
}

list_t *concat_list(list_t *p_list1, list_t *p_list2)
{
	node_t *p_run = NULL;
	list_t *p_new_list = NULL;

	p_new_list = create_list();

	for(p_run = p_list1->next;
		p_run != p_list1;
		p_run = p_run->next)
	{
		insert_end(p_new_list, p_run->data);
	}

	for(p_run = p_list2->next;
		p_run != p_list2;
		p_run = p_run->next)
	{
		insert_end(p_new_list, p_run->data);
	}

	return (p_new_list);
}

list_t *merge_list(list_t *p_list1, list_t *p_list2)
{
	node_t *p_run1 = NULL;
	node_t *p_run2 = NULL;
	list_t *p_new_list = NULL;

	p_run1 = p_list1->next;
	p_run2 = p_list2->next;
	p_new_list = create_list();

	while(TRUE)
	{
		if(p_run1 == p_list1)
		{
			while(p_run2 != p_list2)
			{
				insert_end(p_new_list, p_run2->data);
				p_run2 = p_run2->next;
			}

			break;
		}

		if(p_run2 == p_list2)
		{
			while(p_run1 != p_list1)
			{
				insert_end(p_new_list, p_run1->data);
				p_run1 = p_run1->next;
			}

			break;
		}

		if(p_run1->data <= p_run2->data)
		{
			insert_end(p_new_list, p_run1->data);
			p_run1 = p_run1->next;
		}
		else
		{
			insert_end(p_new_list, p_run2->data);
			p_run2 = p_run2->next;
		}
	}

	return (p_new_list);
}

list_t *get_reversed_list(list_t *p_list)
{
	list_t *p_reversed_list = NULL;
	node_t *p_run = NULL;

	p_run = p_list->prev;
	p_reversed_list = create_list();

	while(p_run != p_list)
	{
		insert_end(p_reversed_list, p_run->data);
		p_run = p_run->prev;	
	}

	return (p_reversed_list);
}

status_t list_to_array(list_t *p_list, data_t **pp_array, size_t *p_size)
{
	data_t *p_array = NULL;
	len_t len = 0;
	node_t *p_run = NULL;
	int i = 0;

	len = get_length(p_list);
	p_array = (data_t*) xmalloc(len * sizeof(data_t));

	for(p_run = p_list->next;
		p_run != p_list;
		p_run = p_run->next)
	{
		p_array[i] = p_run->data;
		i++;
	}

	if(len != 0)
	{
		*pp_array = p_array;
		*p_size = len;
	}

	return (SUCCESS);
}

list_t *array_to_list(data_t *p_array, size_t size)
{
	list_t *p_new_list = NULL;
	int i;

	p_new_list = create_list();
	
	for(i = 0;i < size; i++)
	{
		insert_end(p_new_list, p_array[i]);
	}

	return(p_new_list);
}

status_t append_list(list_t *p_list1, list_t *p_list2)
{
	p_list1->prev->next = p_list2->next;
	p_list2->next->prev = p_list1->prev;

	p_list1->prev = p_list2->prev;
	p_list2->prev->next = p_list1;

	free(p_list2);

	return(SUCCESS);
}

status_t reverse_list(list_t *p_list)
{
	node_t *p_run = NULL;
	node_t *p_run_prev = NULL;
	node_t *p_prev_orig = NULL;

	p_prev_orig = p_list->prev;

	for(p_run = p_list->prev->prev;
		p_run != p_list;
		p_run = p_run_prev)
	{
		p_run_prev = p_run->prev;
		generic_insert(p_list->prev, p_run, p_list);
	}

	p_prev_orig->prev = p_list;
	p_list->next = p_prev_orig;

	return(SUCCESS);
}

status_t destroy_list(list_t **pp_list)
{
	list_t *p_list = *pp_list;
	node_t *p_run = NULL;
	node_t *p_run_next = NULL;

	for(p_run = p_list->next;
		p_run != p_list;
		p_run = p_run_next)
	{
		p_run_next = p_run->next;
		free(p_run);
	}

	free(p_list);
	*pp_list = NULL;

	return (SUCCESS);
}


/* list auxillary routines */

static void generic_insert(node_t *p_beg, node_t *p_mid, node_t *p_end)
{
	p_mid->next = p_end;
	p_mid->prev = p_beg;
	p_beg->next = p_mid;
	p_end->prev = p_mid;
}

static void generic_delete(node_t *p_delete_node)
{	
	p_delete_node->next->prev = p_delete_node->prev;
	p_delete_node->prev->next = p_delete_node->next;

	free(p_delete_node);
	p_delete_node = NULL;

}

static node_t *locate_node(list_t *p_list, data_t search_data)
{
	node_t *p_run = NULL;

	for(p_run = p_list->next;
		p_run != p_list;
		p_run = p_run->next)
	{
		if(p_run->data == search_data)
		{
			return (p_run);
		}
	}

	return (NULL);
}

static node_t *get_list_node(data_t new_data)
{
	node_t *p_new_node = NULL;

	p_new_node = (node_t*)xmalloc(sizeof(node_t));

	p_new_node->data = new_data;
	p_new_node->next = NULL;
	p_new_node->prev = NULL;
		
	return (p_new_node);
}

/* memory allocation techniques */
void *xmalloc(size_t size_in_bytes)
{
	void *p = NULL;

	p = malloc(size_in_bytes);

	if(p == NULL)
	{
		fprintf(stderr, "Out of memory");
		exit(FAILURE);
	}

	return (p);
}

