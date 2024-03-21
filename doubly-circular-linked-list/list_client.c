#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "list.h"

int main(void)
{

    status_t s; 
    data_t data; 
    len_t len; 

    list_t *p_list = NULL;
    list_t *p_list1 = NULL, *p_list2 = NULL;  
    list_t *p_concat_list = NULL; 
    list_t *p_merge_list = NULL; 
    list_t *p_reversed_list = NULL; 
    list_t *array_list = NULL;

    size_t size = 0;
    data_t *new_array = NULL;
    data_t p_array[5] = {10,20,30,40,50};

    p_list = create_list(); 

    assert(get_beg(p_list, &data) == LIST_EMPTY); 
    assert(get_end(p_list, &data) == LIST_EMPTY); 
    assert(pop_beg(p_list, &data) == LIST_EMPTY); 
    assert(pop_end(p_list, &data) == LIST_EMPTY); 
    assert(remove_beg(p_list) == LIST_EMPTY); 
    assert(remove_end(p_list) == LIST_EMPTY); 
    assert(remove_data(p_list, 0) == LIST_DATA_NOT_FOUND); 
    assert(get_length(p_list) == 0); 

    show_list(p_list, "After create_list():"); 
    for(data = 0; data < 5; data++)
    {
        s = insert_beg(p_list, data); 
        assert(s == SUCCESS); 
    }
    show_list(p_list, "After insert_beg())"); 

    for(data = 5; data < 10; data++)
    {
        s = insert_end(p_list, data); 
        assert(s == SUCCESS); 
    }
    show_list(p_list, "After insert_end():"); 

    s = insert_after(p_list, 0, 100); 
    assert(s == SUCCESS); 
    show_list(p_list, "After insert_after():"); 

    s = insert_before(p_list, 0, 200); 
    assert(s == SUCCESS); 
    show_list(p_list, "After insert_before():"); 

    data = 0; 
    s = get_beg(p_list, &data); 
    assert(s == SUCCESS); 
    printf("Beginning data:%d\n", data); 
    data = 0; 
    s = get_end(p_list, &data); 
    assert(s == SUCCESS); 
    printf("End data:%d\n", data); 
    show_list(p_list, "After get_beg() and get_end():"); 

    data = 0; 
    s = pop_beg(p_list, &data); 
    assert(s == SUCCESS); 
    printf("poped beg data:%d\n", data); 
    show_list(p_list, "After pop_beg():"); 
    data = 0; 
    s = pop_end(p_list, &data); 
    assert(s == SUCCESS); 
    printf("poped end data:%d\n", data); 
    show_list(p_list, "After pop_end():"); 

    s = remove_beg(p_list); 
    assert(s == SUCCESS); 
    show_list(p_list, "After remove_beg():"); 
    s = remove_end(p_list); 
    assert(s == SUCCESS); 
    show_list(p_list, "After remove_end():"); 
    s = remove_data(p_list, 0); 
    assert(s == SUCCESS);
    show_list(p_list, "After remove_data():"); 

    printf("get_length(p_list):%d\n", get_length(p_list)); 
    if(contains(p_list, 200) == TRUE)
    {
        puts("200 is in list"); 
    }
    if(contains(p_list, -5) == FALSE)
    {
        puts("-5 is not in list"); 
    }

    printf("get_repeat_count(p_list, 4):%d\n", get_repeat_count(p_list, 4)); 
    printf("get_repeat_count(p_list, 200):%d\n", get_repeat_count(p_list, 200)); 
    assert(insert_end(p_list, 100) == SUCCESS); 
    printf("get_repeat_count(p_list, 100):%d\n", get_repeat_count(p_list, 100)); 
    
    s = destroy_list(&p_list); 
    assert(s == SUCCESS && p_list == NULL); 

    p_list1 = create_list(); 
    p_list2 = create_list(); 

    for(data = 5; data <= 95; data += 10)
    {
        insert_end(p_list1, data); 
        insert_end(p_list2, data+5); 
    }

    show_list(p_list1, "List1:"); 
    show_list(p_list2, "List2:"); 

    p_concat_list = concat_list(p_list1, p_list2); 
    show_list(p_concat_list, "Concatenated version of List1 and List2:"); 
    
    p_merge_list = merge_list(p_list1, p_list2); 
    show_list(p_merge_list, "Merged version of List1 and List2:"); 

    p_reversed_list = get_reversed_list(p_list1); 
    show_list(p_list1, "List1:"); 
    show_list(p_reversed_list, "Reversed version of List1:"); 

    show_list(p_list2, "List2 before undergoing reversal:");
    s = reverse_list(p_list2); 
    assert(s == SUCCESS); 
    show_list(p_list2, "Reversed List2:"); 

    s = append_list(p_list1, p_list2); 
    assert(s == SUCCESS); 
    show_list(p_list1, "List2 is appended behind list1:"); 
    
    s = list_to_array(p_list1, &new_array, &size);
    assert(s == SUCCESS);

    puts("Showing array after list_to_array():");
    show_list(p_list1, "List2 for list_to_array():");

    printf("Showing the array:\n");
    printf("[BEG]-");
    for(size_t i = 0; i < size; i++)    
    {
        printf("[%d]-", new_array[i]);
    }
    printf("[END]\n\n");

    printf("Showing array:\n");
    printf("[BEG]-");
    for(int i = 0;i < 5;i++)
    {
        printf("[%d]-", p_array[i]);
    }
    printf("[END]\n\n");

    array_list = array_to_list(p_array, 5);
    show_list(array_list, "After array_to_list():");

    s = destroy_list(&array_list);
    assert(s == SUCCESS && array_list == NULL);

    s = destroy_list(&p_list1); 
    assert(s == SUCCESS && p_list1 == NULL); 

    s = destroy_list(&p_concat_list); 
    assert(s == SUCCESS && p_concat_list == NULL); 

    s = destroy_list(&p_merge_list); 
    assert(s == SUCCESS && p_merge_list == NULL); 

    s = destroy_list(&p_reversed_list); 
    assert(s == SUCCESS && p_reversed_list == NULL); 


    free(new_array);
    new_array = NULL;
   
    return (EXIT_SUCCESS); 
}
