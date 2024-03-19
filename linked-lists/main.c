/*

    @ DATE : 26/10/2023
    @ AUTHOR : SATEJ UPENDRA GANJI
    @ PURPOSE : CLIENT IMPLEMENTATION FOR LINKED LISTS 

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "./include/list.h"
#include "./include/vector.h"

void vector_functionality()
{
    puts("++++++++++++++++++++++++++++++++++INTEGER VECTOR++++++++++++++++++++++++++++++++++");

    vector_t *p_vec_int = NULL;
    status_t status;
    p_vec_int = create_vector();

    for(int i=0;i < 10; i++)
    {
    	push_back(p_vec_int, i+1);
    }    

    show(p_vec_int, "Showing vector after inserting elements:\n");
    status = destroy_vector(p_vec_int);
    assert(status == SUCCESS);
    p_vec_int = NULL;

    puts("\n++++++++++++++++++++++++++++++++++END!!!!++++++++++++++++++++++++++++++++++\n\n\n");

}

int main(void)
{
    linked_lists_functionality();
    vector_functionality();
    exit(EXIT_SUCCESS);
}
