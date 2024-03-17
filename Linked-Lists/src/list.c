/*
    
    @ DATE : 25/10/2023
    @ AUTHOR : SATEJ UPENDRA GANJI
    @ PURPOSE : CLIENT IMPLEMENTATION OF ALL THE LINKED LISTS

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/list.h"


status_t doubly_circular_linked_list(void)
{
    puts("++++++++++++++++++++++++++++++++++DOUBLY CIRCULAR LINKED LIST++++++++++++++++++++++++++++++++++");
    status_t ret_val;
    data_t data;
    len_t list_length;

    list_dcll_t *p_list = NULL;
    list_dcll_t *p_list1 = NULL;
    list_dcll_t *p_list2 = NULL;
    list_dcll_t *p_concat_list = NULL;
    list_dcll_t *p_merged_list = NULL;
    list_dcll_t *p_reversed_list = NULL;
    list_dcll_t *p_array_list = NULL;

    size_t size = 0;
    data_t *p_new_array = NULL;
    data_t *p_array = NULL;
    int i = 0;

    p_array = (data_t *)xmalloc(sizeof(data_t) * 5);
    for(i = 0;i < 5; i++)
        *(p_array + i) = i+10;

    p_list = create_list_dcll();

    assert(get_begin_dcll(p_list, &data) == LIST_EMPTY);    
    assert(get_end_dcll(p_list, &data) == LIST_EMPTY);
    assert(pop_begin_dcll(p_list, &data) == LIST_EMPTY);
    assert(pop_end_dcll(p_list, &data) == LIST_EMPTY);

    assert(remove_begin_dcll(p_list) == LIST_EMPTY);
    assert(remove_end_dcll(p_list) == LIST_EMPTY);
    assert(remove_data_dcll(p_list, 12) == LIST_EMPTY);
    assert(get_list_length_dcll(p_list) == 0);

    show_list_dcll(p_list, "After List Creation:");
    for(data = 0; data < 5; data++)
    {
        ret_val = insert_beginning_dcll(p_list, data);
        assert(ret_val == SUCCESS);
    }
    show_list_dcll(p_list, "Showing List After insertion at the beginning of the list:");

    for(data = 5; data < 10; data++)
    {
        ret_val = insert_end_dcll(p_list, data);
        assert(ret_val == SUCCESS);
    }
    show_list_dcll(p_list, "Showing List After insertion at the end of the list:");

    ret_val = insert_after_dcll(p_list, 100, 0);
    assert(ret_val == SUCCESS);
    show_list_dcll(p_list, "Showing List After inserting data after data element 0:");

    ret_val = insert_before_dcll(p_list, 200, 0);
    assert(ret_val == SUCCESS);
    show_list_dcll(p_list, "Showing List After inserting data before data element 0:");

    data = 0;
    ret_val = get_begin_dcll(p_list, &data);
    assert(ret_val == SUCCESS);
    printf("Beginning data of the list is : %d\n", data);

    data = 0;
    ret_val = get_end_dcll(p_list, &data);
    assert(ret_val == SUCCESS);
    printf("End data of the list is : %d\n\n", data);

    data = 0;
    ret_val = pop_begin_dcll(p_list, &data);
    assert(ret_val == SUCCESS);
    printf("Popped beginning data of the list is : %d\n", data);
    show_list_dcll(p_list, "Showing List After popping the begnning element:");

    data = 0;
    ret_val = pop_end_dcll(p_list, &data);
    assert(ret_val == SUCCESS);
    printf("Popped end data of the list is : %d\n", data);
    show_list_dcll(p_list, "Showing List After popping the end element:");

    ret_val = remove_begin_dcll(p_list);
    assert(ret_val == SUCCESS);
    show_list_dcll(p_list, "Showing List After removing the beginning of the list:");
    
    ret_val = remove_end_dcll(p_list);
    assert(ret_val == SUCCESS);
    show_list_dcll(p_list, "Showing List After removing the end of the list:");

    ret_val = remove_data_dcll(p_list, 0);
    assert(ret_val == SUCCESS);
    show_list_dcll(p_list, "Showing List After removing the data element 0 from the list:");

    printf("List length is : %d\n", get_list_length_dcll(p_list));

    puts("Checking for presence of the data in the element:");
    if(list_contains_dcll(p_list, 200) == TRUE)
    {
        puts("200 is present in the list");
    }

    if(list_contains_dcll(p_list, -845748) == FALSE)
    {
        puts("-845748 is not present in the list");
    }

    printf("Repetation count of the element 4 is : %d\n", get_element_count_dcll(p_list, 4));
    printf("Repetation count of the element 200 is : %d\n", get_element_count_dcll(p_list, 200));
    assert(insert_end_dcll(p_list, 100) == SUCCESS);
    printf("Repetation count of the element 100 is : %d\n\n", get_element_count_dcll(p_list, 100));

    ret_val = destroy_list_dcll(&p_list);
    assert(ret_val == SUCCESS && p_list == NULL);

    p_list1 = create_list_dcll();
    p_list2 = create_list_dcll();

    for(data = 5; data <= 95; data += 10)
    {
        insert_end_dcll(p_list1, data);
        insert_end_dcll(p_list2, data+5);
    }

    show_list_dcll(p_list1, "Showing List1 After creating it and insertion of data elements:");
    show_list_dcll(p_list2, "Showing List2 After creating it and insertion of data elements:");

    p_concat_list = concat_list_dcll(p_list1, p_list2);
    show_list_dcll(p_concat_list, "Showing Concatenation of both the Lists:");

    p_merged_list = merge_list_dcll(p_list1, p_list2);
    show_list_dcll(p_merged_list, "Showing merged list of both the lists:");

    p_reversed_list = get_reversed_list_dcll(p_list1);
    show_list_dcll(p_list1, "Showing List1:");
    show_list_dcll(p_reversed_list, "Showing Reversed version of List1:");

    show_list_dcll(p_list2, "Showing List2 Before Undergoing Reversal:");
    ret_val = reverse_list_dcll(p_list2);
    assert(ret_val == SUCCESS);
    show_list_dcll(p_list2, "Showing List2 After Undergoing Reversal:");

    ret_val = append_list_dcll(p_list1, p_list2);
    assert(ret_val == SUCCESS);
    show_list_dcll(p_list1, "Showing List1 After Appending List2:");

    ret_val = list_to_array_dcll(p_list1, &p_new_array, &size);
    puts("Showing Array which is made from the list:");
    i = 0;
    for(i = 0;i < size; ++i)
    {
        printf("p_array_list[%d] = %d\n", i, *(p_new_array + i));
    }

    p_array_list = array_to_list_dcll(p_array, 5);
    puts("\nShowing array which is being converted to list:");
    for(i = 0; i < 5; ++i)
    {
        printf("p_array[%d] = %d\n", i, *(p_array+i));
    }
    show_list_dcll(p_array_list, "\nShowing the list created from the list:");

    ret_val = destroy_list_dcll(&p_array_list);
    assert(ret_val == SUCCESS && p_array_list == NULL);

    ret_val = destroy_list_dcll(&p_list1);
    assert(ret_val == SUCCESS && p_list1 == NULL);

    ret_val = destroy_list_dcll(&p_concat_list);
    assert(ret_val == SUCCESS && p_concat_list == NULL);

    ret_val = destroy_list_dcll(&p_merged_list);
    assert(ret_val == SUCCESS && p_merged_list == NULL);

    ret_val = destroy_list_dcll(&p_reversed_list);
    assert(ret_val == SUCCESS && p_reversed_list == NULL);

    
    free(p_new_array);
    p_new_array = NULL;

    puts("++++++++++++++++++++++++++++++++++END!!!!++++++++++++++++++++++++++++++++++\n\n\n");
    return (SUCCESS);

}


status_t doubly_linked_list(void)
{
    puts("++++++++++++++++++++++++++++++++++[DOUBLY LINKED LIST]++++++++++++++++++++++++++++++++++");
    status_t ret_val;
    data_t data;
    len_t list_length;

    list_dll_t *p_list = NULL;
    list_dll_t *p_list1 = NULL;
    list_dll_t *p_list2 = NULL;
    list_dll_t *p_concat_list = NULL;
    list_dll_t *p_merged_list = NULL;
    list_dll_t *p_reversed_list = NULL;
    list_dll_t *p_array_list = NULL;

    size_t size = 0;
    data_t *p_new_array = NULL;
    data_t *p_array = NULL;
    int i = 0;

    p_array = (data_t *)xmalloc(sizeof(data_t) * 5);
    for(i = 0;i < 5; i++)
        *(p_array + i) = i+10;

    p_list = create_list_dll();

    assert(get_begin_dll(p_list, &data) == LIST_EMPTY);    
    assert(get_end_dll(p_list, &data) == LIST_EMPTY);
    assert(pop_begin_dll(p_list, &data) == LIST_EMPTY);
    assert(pop_end_dll(p_list, &data) == LIST_EMPTY);

    assert(remove_begin_dll(p_list) == LIST_EMPTY);
    assert(remove_end_dll(p_list) == LIST_EMPTY);
    assert(remove_data_dll(p_list, 12) == LIST_EMPTY);
    assert(get_list_length_dll(p_list) == 0);
    
    show_list_dll(p_list, "After List Creation:");
    for(data = 0; data < 5; data++)
    {
        ret_val = insert_beginning_dll(p_list, data);
        assert(ret_val == SUCCESS);
    }
    show_list_dll(p_list, "Showing List After insertion at the beginning of the list:");
    
    for(data = 5; data < 10; data++)
    {
        ret_val = insert_end_dll(p_list, data);
        assert(ret_val == SUCCESS);
    }
    show_list_dll(p_list, "Showing List After insertion at the end of the list:");

    ret_val = insert_after_dll(p_list, 100, 0);
    assert(ret_val == SUCCESS);
    show_list_dll(p_list, "Showing List After inserting data after data element 0:");

    ret_val = insert_before_dll(p_list, 200, 0);
    assert(ret_val == SUCCESS);
    show_list_dll(p_list, "Showing List After inserting data before data element 0:");

    data = 0;
    ret_val = get_begin_dll(p_list, &data);
    assert(ret_val == SUCCESS);
    printf("Beginning data of the list is : %d\n", data);

    data = 0;
    ret_val = get_end_dll(p_list, &data);
    assert(ret_val == SUCCESS);
    printf("End data of the list is : %d\n\n", data);

    data = 0;
    ret_val = pop_begin_dll(p_list, &data);
    assert(ret_val == SUCCESS);
    printf("Popped beginning data of the list is : %d\n", data);
    show_list_dll(p_list, "Showing List After popping the begnning element:");

    data = 0;
    ret_val = pop_end_dll(p_list, &data);
    assert(ret_val == SUCCESS);
    printf("Popped end data of the list is : %d\n", data);
    show_list_dll(p_list, "Showing List After popping the end element:");

    ret_val = remove_begin_dll(p_list);
    assert(ret_val == SUCCESS);
    show_list_dll(p_list, "Showing List After removing the beginning of the list:");
    
    ret_val = remove_end_dll(p_list);
    assert(ret_val == SUCCESS);
    show_list_dll(p_list, "Showing List After removing the end of the list:");

    ret_val = remove_data_dll(p_list, 0);
    assert(ret_val == SUCCESS);
    show_list_dll(p_list, "Showing List After removing the data element 0 from the list:");

    printf("List length is : %d\n", get_list_length_dll(p_list));

    puts("Checking for presence of the data in the element:");
    if(list_contains_dll(p_list, 200) == TRUE)
    {
        puts("200 is present in the list");
    }

    if(list_contains_dll(p_list, -845748) == FALSE)
    {
        puts("-845748 is not present in the list");
    }

    printf("Repetation count of the element 4 is : %d\n", get_element_count_dll(p_list, 4));
    printf("Repetation count of the element 200 is : %d\n", get_element_count_dll(p_list, 200));
    assert(insert_end_dll(p_list, 100) == SUCCESS);
    printf("Repetation count of the element 100 is : %d\n\n", get_element_count_dll(p_list, 100));

    ret_val = destroy_list_dll(&p_list);
    assert(ret_val == SUCCESS && p_list == NULL);

    p_list1 = create_list_dll();
    p_list2 = create_list_dll();

    for(data = 5; data <= 95; data += 10)
    {   
        insert_end_dll(p_list1, data);
        insert_end_dll(p_list2, data+5);
    }

    show_list_dll(p_list1, "Showing List1 After creating it and insertion of data elements:");
    show_list_dll(p_list2, "Showing List2 After creating it and insertion of data elements:");

    p_concat_list = concat_list_dll(p_list1, p_list2);
    show_list_dll(p_concat_list, "Showing Concatenation of both the Lists:");

    p_merged_list = merge_list_dll(p_list1, p_list2);
    show_list_dll(p_merged_list, "Showing merged list of both the lists:");

    p_reversed_list = get_reversed_list_dll(p_list1);
    show_list_dll(p_list1, "Showing List1:");
    show_list_dll(p_reversed_list, "Showing Reversed version of List1:");

    show_list_dll(p_list2, "Showing List2 Before Undergoing Reversal:");
    ret_val = reverse_list_dll(p_list2);
    assert(ret_val == SUCCESS);
    show_list_dll(p_list2, "Showing List2 After Undergoing Reversal:");

    ret_val = append_list_dll(p_list1, p_list2);
    assert(ret_val == SUCCESS);
    show_list_dll(p_list1, "Showing List1 After Appending List2:");

    ret_val = list_to_array_dll(p_list1, &p_new_array, &size);
    puts("Showing Array which is made from the list:");

    for(i = 0;i < size; ++i)
    {
        printf("p_array_list[%d] = %d\n", i, *(p_new_array + i));
    }

    p_array_list = array_to_list_dll(p_array, 5);
    puts("Showing array which is being converted to list:");
    for(i = 0; i < 5; ++i)
    {
        printf("p_array[%d] = %d\n", i, *(p_array+i));
    }
    show_list_dll(p_array_list, "\nShowing the list created from the list:");

    ret_val = destroy_list_dll(&p_array_list);
    assert(ret_val == SUCCESS && p_array_list == NULL);

    ret_val = destroy_list_dll(&p_list1);
    assert(ret_val == SUCCESS && p_list1 == NULL);

    ret_val = destroy_list_dll(&p_concat_list);
    assert(ret_val == SUCCESS && p_concat_list == NULL);

    ret_val = destroy_list_dll(&p_merged_list);
    assert(ret_val == SUCCESS && p_merged_list == NULL);

    ret_val = destroy_list_dll(&p_reversed_list);
    assert(ret_val == SUCCESS && p_reversed_list == NULL);

    free(p_new_array);
    p_new_array = NULL;

    puts("++++++++++++++++++++++++++++++++++[END]++++++++++++++++++++++++++++++++++\n\n\n");
    return (SUCCESS);

}


status_t singly_circular_linked_list(void)
{
    puts("++++++++++++++++++++++++++++++++++[SINGLY CIRCULAR LINKED LIST]++++++++++++++++++++++++++++++++++");
    status_t ret_val;
    data_t data;
    len_t list_length;

    list_scll_t *p_list = NULL;
    list_scll_t *p_list1 = NULL;
    list_scll_t *p_list2 = NULL;
    list_scll_t *p_concat_list = NULL;
    list_scll_t *p_merged_list = NULL;
    list_scll_t *p_reversed_list = NULL;
    list_scll_t *p_array_list = NULL;

    size_t size = 0;
    data_t *p_new_array = NULL;
    data_t *p_array = NULL;
    int i = 0;

    p_array = (data_t *)xmalloc(sizeof(data_t) * 5);
    for(i = 0;i < 5; i++)
        *(p_array + 1) = i+10;

    p_list = create_list_scll();

    assert(get_begin_scll(p_list, &data) == LIST_EMPTY);    
    assert(get_end_scll(p_list, &data) == LIST_EMPTY);
    assert(pop_begin_scll(p_list, &data) == LIST_EMPTY);
    assert(pop_end_scll(p_list, &data) == LIST_EMPTY);

    assert(remove_begin_scll(p_list) == LIST_EMPTY);
    assert(remove_end_scll(p_list) == LIST_EMPTY);
    assert(remove_data_scll(p_list, 12) == LIST_EMPTY);
    assert(get_list_length_scll(p_list) == 0);

    show_list_scll(p_list, "After List Creation:");
    for(data = 0; data < 5; data++)
    {
        ret_val = insert_beginning_scll(p_list, data);
        assert(ret_val == SUCCESS);
    }
    show_list_scll(p_list, "Showing List After insertion at the beginning of the list:");

    for(data = 5; data < 10; data++)
    {
        ret_val = insert_end_scll(p_list, data);
        assert(ret_val == SUCCESS);
    }
    show_list_scll(p_list, "Showing List After insertion at the end of the list:");

    ret_val = insert_after_scll(p_list, 100, 0);
    assert(ret_val == SUCCESS);
    show_list_scll(p_list, "Showing List After inserting data after data element 0:");

    ret_val = insert_before_scll(p_list, 200, 0);
    assert(ret_val == SUCCESS);
    show_list_scll(p_list, "Showing List After inserting data before data element 0:");

    data = 0;
    ret_val = get_begin_scll(p_list, &data);
    assert(ret_val == SUCCESS);
    printf("Beginning data of the list is : %d\n", data);

    data = 0;
    ret_val = get_end_scll(p_list, &data);
    assert(ret_val == SUCCESS);
    printf("End data of the list is : %d\n\n", data);

    data = 0;
    ret_val = pop_begin_scll(p_list, &data);
    assert(ret_val == SUCCESS);
    printf("Popped beginning data of the list is : %d\n", data);
    show_list_scll(p_list, "Showing List After popping the begnning element:");

    data = 0;
    ret_val = pop_end_scll(p_list, &data);
    assert(ret_val == SUCCESS);
    printf("Popped end data of the list is : %d\n", data);
    show_list_scll(p_list, "Showing List After popping the end element:");

    ret_val = remove_begin_scll(p_list);
    assert(ret_val == SUCCESS);
    show_list_scll(p_list, "Showing List After removing the beginning of the list:");
    
    ret_val = remove_end_scll(p_list);
    assert(ret_val == SUCCESS);
    show_list_scll(p_list, "Showing List After removing the end of the list:");

    ret_val = remove_data_scll(p_list, 0);
    assert(ret_val == SUCCESS);
    show_list_scll(p_list, "Showing List After removing the data element 0 from the list:");

    printf("List length is : %d\n", get_list_length_scll(p_list));

    puts("Checking for presence of the data in the element:");
    if(list_contains_scll(p_list, 200) == TRUE)
    {
        puts("200 is present in the list");
    }

    if(list_contains_scll(p_list, -845748) == FALSE)
    {
        puts("-845748 is not present in the list");
    }

    printf("Repetation count of the element 4 is : %d\n", get_element_count_scll(p_list, 4));
    printf("Repetation count of the element 200 is : %d\n", get_element_count_scll(p_list, 200));
    assert(insert_end_scll(p_list, 100) == SUCCESS);
    printf("Repetation count of the element 100 is : %d\n\n", get_element_count_scll(p_list, 100));

    ret_val = destroy_list_scll(&p_list);
    assert(ret_val == SUCCESS && p_list == NULL);

    p_list1 = create_list_scll();
    p_list2 = create_list_scll();

    for(data = 5; data <= 95; data += 10)
    {
        insert_end_scll(p_list1, data);
        insert_end_scll(p_list2, data+5);
    }

    show_list_scll(p_list1, "Showing List1 After creating it and insertion of data elements:");
    show_list_scll(p_list2, "Showing List2 After creating it and insertion of data elements:");

    p_concat_list = concat_list_scll(p_list1, p_list2);
    show_list_scll(p_concat_list, "Showing Concatenation of both the Lists:");

    p_merged_list = merge_list_scll(p_list1, p_list2);
    show_list_scll(p_merged_list, "Showing merged list of both the lists:");

    p_reversed_list = get_reversed_list_scll(p_list1);
    show_list_scll(p_list1, "Showing List1:");
    show_list_scll(p_reversed_list, "Showing Reversed version of List1:");

    show_list_scll(p_list2, "Showing List2 Before Undergoing Reversal:");
    ret_val = reverse_list_scll(p_list2);
    assert(ret_val == SUCCESS);
    show_list_scll(p_list2, "Showing List2 After Undergoing Reversal:");

    ret_val = append_list_scll(p_list1, p_list2);
    assert(ret_val == SUCCESS);
    show_list_scll(p_list1, "Showing List1 After Appending List2:");

    ret_val = list_to_array_scll(p_list1, &p_new_array, &size);
    puts("Showing Array which is made from the list:");
    i = 0;
    for(i = 0;i < size; ++i)
    {
        printf("p_array_list[%d] = %d\n", i, *(p_new_array + i));
    }

    p_array_list = array_to_list_scll(p_array, 5);
    puts("Showing array which is being converted to list:");
    for(i = 0; i < 5; ++i)
    {
        printf("p_array[%d] = %d\n", i, *(p_array+i));
    }
    show_list_scll(p_array_list, "\nShowing the list created from the list:");

    ret_val = destroy_list_scll(&p_array_list);
    assert(ret_val == SUCCESS && p_array_list == NULL);

    ret_val = destroy_list_scll(&p_list1);
    assert(ret_val == SUCCESS && p_list1 == NULL);

    ret_val = destroy_list_scll(&p_concat_list);
    assert(ret_val == SUCCESS && p_concat_list == NULL);

    ret_val = destroy_list_scll(&p_merged_list);
    assert(ret_val == SUCCESS && p_merged_list == NULL);

    ret_val = destroy_list_scll(&p_reversed_list);
    assert(ret_val == SUCCESS && p_reversed_list == NULL);

    free(p_new_array);
    p_new_array = NULL;

    puts("++++++++++++++++++++++++++++++++++[END]++++++++++++++++++++++++++++++++++\n\n\n");
    return (SUCCESS);
   
}


status_t singly_linked_list(void)
{
    puts("++++++++++++++++++++++++++++++++++[SINGLY LINKED LIST]++++++++++++++++++++++++++++++++++");
    status_t ret_val;
    data_t data;
    len_t list_length;

    list_sll_t *p_list = NULL;
    list_sll_t *p_list1 = NULL;
    list_sll_t *p_list2 = NULL;
    list_sll_t *p_concat_list = NULL;
    list_sll_t *p_merged_list = NULL;
    list_sll_t *p_reversed_list = NULL;
    list_sll_t *p_array_list = NULL;

    size_t size = 0;
    data_t *p_new_array = NULL;
    data_t *p_array = NULL;
    int i = 0;

    p_array = (data_t *)xmalloc(sizeof(data_t) * 5);
    for(i = 0;i < 5; i++)
        *(p_array + i) = i+10;

    p_list = create_list_sll();

    assert(get_begin_sll(p_list, &data) == LIST_EMPTY);    
    assert(get_end_sll(p_list, &data) == LIST_EMPTY);
    assert(pop_begin_sll(p_list, &data) == LIST_EMPTY);
    assert(pop_end_sll(p_list, &data) == LIST_EMPTY);

    assert(remove_begin_sll(p_list) == LIST_EMPTY);
    assert(remove_end_sll(p_list) == LIST_EMPTY);
    assert(remove_data_sll(p_list, 12) == LIST_DATA_NOT_FOUND);
    assert(get_list_length_sll(p_list) == 0);

    show_list_sll(p_list, "After List Creation:");
    for(data = 0; data < 5; data++)
    {
        ret_val = insert_beginning_sll(p_list, data);
        assert(ret_val == SUCCESS);
    }
    show_list_sll(p_list, "Showing List After insertion at the beginning of the list:");

    for(data = 5; data < 10; data++)
    {
        ret_val = insert_end_sll(p_list, data);
        assert(ret_val == SUCCESS);
    }
    show_list_sll(p_list, "Showing List After insertion at the end of the list:");

    ret_val = insert_after_sll(p_list, 100, 0);
    assert(ret_val == SUCCESS);
    show_list_sll(p_list, "Showing List After inserting data after data element 0:");

    ret_val = insert_before_sll(p_list, 200, 0);
    assert(ret_val == SUCCESS);
    show_list_sll(p_list, "Showing List After inserting data before data element 0:");

    data = 0;
    ret_val = get_begin_sll(p_list, &data);
    assert(ret_val == SUCCESS);
    printf("Beginning data of the list is : %d\n", data);

    data = 0;
    ret_val = get_end_sll(p_list, &data);
    assert(ret_val == SUCCESS);
    printf("End data of the list is : %d\n\n", data);

    data = 0;
    ret_val = pop_begin_sll(p_list, &data);
    assert(ret_val == SUCCESS);
    printf("Popped beginning data of the list is : %d\n", data);
    show_list_sll(p_list, "Showing List After popping the begnning element:");

    data = 0;
    ret_val = pop_end_sll(p_list, &data);
    assert(ret_val == SUCCESS);
    printf("Popped end data of the list is : %d\n", data);
    show_list_sll(p_list, "Showing List After popping the end element:");

    ret_val = remove_begin_sll(p_list);
    assert(ret_val == SUCCESS);
    show_list_sll(p_list, "Showing List After removing the beginning of the list:");
    
    ret_val = remove_end_sll(p_list);
    assert(ret_val == SUCCESS);
    show_list_sll(p_list, "Showing List After removing the end of the list:");

    ret_val = remove_data_sll(p_list, 5);
    assert(ret_val == SUCCESS);
    show_list_sll(p_list, "Showing List After removing the data element 5 from the list:");

    printf("List length is : %d\n", get_list_length_sll(p_list));

    puts("Checking for presence of the data in the element:");
    if(list_contains_sll(p_list, 200) == TRUE)
    {
        puts("200 is present in the list");
    }

    if(list_contains_sll(p_list, -845748) == FALSE)
    {
        puts("-845748 is not present in the list");
    }

    printf("Repetation count of the element 4 is : %d\n", get_element_count_sll(p_list, 4));
    printf("Repetation count of the element 200 is : %d\n", get_element_count_sll(p_list, 200));
    assert(insert_end_sll(p_list, 100) == SUCCESS);
    printf("Repetation count of the element 100 is : %d\n\n", get_element_count_sll(p_list, 100));

    ret_val = destroy_list_sll(&p_list);
    assert(ret_val == SUCCESS && p_list == NULL);

    p_list1 = create_list_sll();
    p_list2 = create_list_sll();

    for(data = 5; data <= 95; data += 10)
    {   
        insert_end_sll(p_list1, data);
        insert_end_sll(p_list2, data+5);
    }

    show_list_sll(p_list1, "Showing List1 After creating it and insertion of data elements:");
    show_list_sll(p_list2, "Showing List2 After creating it and insertion of data elements:");

    p_concat_list = concat_list_sll(p_list1, p_list2);
    show_list_sll(p_concat_list, "Showing Concatenation of both the Lists:");

    p_merged_list = merge_list_sll(p_list1, p_list2);
    show_list_sll(p_merged_list, "Showing merged list of both the lists:");

    p_reversed_list = get_reversed_list_sll(p_list1);
    show_list_sll(p_list1, "Showing List1:");
    show_list_sll(p_reversed_list, "Showing Reversed version of List1:");

    show_list_sll(p_list2, "Showing List2 Before Undergoing Reversal:");
    ret_val = reverse_list_sll(p_list2);
    assert(ret_val == SUCCESS);
    show_list_sll(p_list2, "Showing List2 After Undergoing Reversal:");

    ret_val = append_list_sll(p_list1, p_list2);
    assert(ret_val == SUCCESS);
    show_list_sll(p_list1, "Showing List1 After Appending List2:");

    ret_val = list_to_array_sll(p_list1, &p_new_array, &size);
    puts("Showing Array which is made from the list:");
    i = 0;
    for(i = 0;i < size; ++i)
    {
        printf("p_array_list[%d] = %d\n", i, *(p_new_array + i));
    }

    p_array_list = array_to_list_sll(p_array, 5);
    puts("Showing array which is being converted to list:");
    for(i = 0; i < 5; ++i)
    {
        printf("p_array[%d] = %d\n", i, *(p_array+i));
    }
    show_list_sll(p_array_list, "\nShowing the list created from the list:");

    ret_val = destroy_list_sll(&p_array_list);
    assert(ret_val == SUCCESS && p_array_list == NULL);

    ret_val = destroy_list_sll(&p_list1);
    assert(ret_val == SUCCESS && p_list1 == NULL);

    ret_val = destroy_list_sll(&p_concat_list);
    assert(ret_val == SUCCESS && p_concat_list == NULL);

    ret_val = destroy_list_sll(&p_merged_list);
    assert(ret_val == SUCCESS && p_merged_list == NULL);

    ret_val = destroy_list_sll(&p_reversed_list);
    assert(ret_val == SUCCESS && p_reversed_list == NULL);

    free(p_new_array);
    p_new_array = NULL;

    puts("++++++++++++++++++++++++++++++++++[END]++++++++++++++++++++++++++++++++++\n\n\n");
    return (SUCCESS);

}

status_t linked_lists_functionality(void)
{
    doubly_circular_linked_list();
    doubly_linked_list();
    singly_circular_linked_list();
    singly_linked_list();

    return (SUCCESS);
}

