/*

    @ DATE : 28/10/2023
    @ AUTHOR : SATEJ UPENDRA GANJI 
    @ PURPOSE : CLIENT IMPLEMENTATION FOR BINARY SEARCH TREE

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bst.h"

int main(void)
{
	bst_t *p_bst = NULL;
	static data_t d_array[] = {100, 50, 150, 25, 75, 125, 175, 65, 130};
	status_t ret_val;
	int i;

	p_bst = create_bst();
	for(i = 0; i < sizeof(d_array) / sizeof(d_array[0]); i++)
		assert(insert_bst(p_bst, d_array[i]) == SUCCESS);

	puts("PRE-ORDER RECURSIVE:"); 
	preorder_r(p_bst); 

	puts("\nIN-ORDER RECURSIVE:"); 
	inorder_r(p_bst); 

	puts("\nPOST-ORDER RECURSIVE:"); 
	postorder_r(p_bst); 

	puts("\nPRE-ORDER NON-RECURSIVE:"); 
	preorder_nrc(p_bst); 

	puts("\nIN-ORDER NON-RECURSIVE:");
	inorder_nrc(p_bst); 

	puts("\nPOST-ORDER NON-RECURSIVE:");
	postorder_nrc(p_bst); 

	puts("\nMAXIMUM OF THE BST");
	maximum_bst(p_bst, &i);
	printf("Maximum data in the BST is : %d\n", i);

	puts("\nMINIMUM OF THE BST");
	minimum_bst(p_bst, &i);
	printf("Minimum data in the BST is : %d\n", i);

	puts("\nINORDER-SUCCESSOR");
	inorder_successor(p_bst, 50, &i);
	printf("The inorder successor of 50 is %d\n", i);

	puts("\nINORDER-PREDECCESSOR");
	inorder_predecessor(p_bst, 50, &i);
	printf("The inorder predecessor of 50 is %d\n", i);

    puts("\nBST BEFORE DATA-REMOVAL:");
    inorder_r(p_bst);
    remove_bst(p_bst, 25);
    puts("\nBST AFTER DATA-REMOVAL:");
    inorder_r(p_bst);

	assert(destroy_bst(&p_bst) && !p_bst);
    puts("\nBST DESTROYED");

	return (EXIT_SUCCESS);	
}