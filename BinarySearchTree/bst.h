/*

    @ DATE : 28/10/2023
    @ AUTHOR : SATEJ UPENDRA GANJI 
    @ PURPOSE : HEADER FILE FOR BINARY SEARCH TREE

*/

#ifndef _BST_H
#define _BST_H

#define SUCCESS         1
#define FAILURE         0
#define TRUE            1
#define FALSE           0

#define BST_DATA_NOT_FOUND  2
#define BST_NO_SUCCESSOR    3
#define BST_NO_PREDECESSOR  4
#define BST_EMPTY           5

#define LIST_EMPTY      6
#define STACK_EMPTY     LIST_EMPTY

struct bst_node;
struct bst;
struct bstptr_node;
enum color;

typedef struct bst_node bst_node_t;
typedef struct bst bst_t;

typedef struct bstptr_node bstptr_node_t;
typedef bstptr_node_t list_t;
typedef list_t stack_t;

typedef int data_t;
typedef int status_t;
typedef int bool;
typedef unsigned long size_t;

typedef enum color color_t;

struct bst_node
{
    data_t data;
    struct bst_node *left;
    struct bst_node *right;
    struct bst_node *parent;
};

struct bst 
{
    bst_node_t *p_root_node;
    int nr_elements;
};

enum color
{
    WHITE,
    GREY,
    BLACK
};

struct bstptr_node
{
    struct bst_node *p_bst_node;
    color_t color;
    struct bstptr_node *prev;
    struct bstptr_node *next;
};


/* INTERFACE ROUTINES */

bst_t *create_bst(void);
status_t insert_bst(bst_t *p_bst, data_t new_data);
bool search_bst(bst_t *p_bst, data_t search_data);

void inorder_r(bst_t *p_bst);
void preorder_r(bst_t *p_bst);
void postorder_r(bst_t *p_bst);

void inorder_nrc(bst_t *p_bst);
void preorder_nrc(bst_t *p_bst);
void postorder_nrc(bst_t *p_bst);

status_t maximum_bst(bst_t *p_bst, data_t *p_max_data);
status_t minimum_bst(bst_t *p_bst, data_t *p_min_data);
status_t inorder_successor(bst_t* p_bst, data_t existing_data, data_t *p_successor_data);
status_t inorder_predecessor(bst_t *p_bst, data_t existing_data, data_t *p_predecessot_data);

status_t remove_bst(bst_t *p_bst, data_t remove_data);
status_t destroy_bst(bst_t **pp_bst);
status_t remove_bst_extended(bst_t *p_bst, data_t remove_data);

/* BST - AUXILLARY ROUTINES */

bst_node_t *search_bst_node(bst_node_t *p_root_node, data_t search_data);
bst_node_t *get_bst_node(data_t new_data);
bst_node_t *inorder_successor_node(bst_node_t *p_bst_node);
bst_node_t *inorder_predecessor_node(bst_node_t *p_bst_node);

void __inorder_r(bst_node_t *p_root_node);
void __preorder_r(bst_node_t *p_root_node);
void __postorder_r(bst_node_t *p_root_node);
void __destroy_bst_r(bst_node_t *p_root_node);

void transplant_bst(bst_t *p_bst, bst_node_t *u, bst_node_t *v);

/* BST AUXILLARY - STACK INTERFACE ROUTINES */

stack_t *create_bstptr_stack(void);
status_t push_bstptr(stack_t *p_stack, bst_node_t *p_bst_node);
status_t top_bstptr(stack_t *p_stack, bst_node_t **pp_bst_node);
status_t pop_bstptr(stack_t *p_stack, bst_node_t **pp_bst_node);
status_t set_bstptr_top_color(stack_t *p_stack, color_t new_color);
status_t get_bstptr_top_color(stack_t *p_stack, color_t *p_top_color);
bool is_bstptr_stack_empty(stack_t *p_stack);
status_t destroy_bstptr_stack(stack_t **pp_stack);

/* BST AUXILLARY - LIST INTERFACE FOR STACK ROUTINES */

list_t *create_bstptr_list(void);
status_t insert_bstptr_end(list_t *p_list, bst_node_t *p_bst_node);
status_t examine_bstptr_end(list_t *p_list, bst_node_t **pp_bst_node);
status_t examine_and_delete_bstptr_end(list_t *p_list, bst_node_t **pp_bst_node);
bool is_bstptr_list_empty(list_t *p_list);
status_t destroy_bstptr_list(list_t **pp_list);

/* BST AUXILLARY - LIST ROUTINES */
void generic_bstptr_insert(bstptr_node_t *p_beg, bstptr_node_t *p_mid, bstptr_node_t *p_end);
void generic_bstptr_delete(bstptr_node_t *p_delete_bstptr_node);
bstptr_node_t *search_bstptr_node(list_t *p_list, bst_node_t *p_bst_node);
bstptr_node_t *get_bstptr_node(bst_node_t *p_bst_node);

/*  General Auxillary Routines - Memory Management */
void *xcalloc(size_t n, size_t s);

#endif /* _BST_H */
