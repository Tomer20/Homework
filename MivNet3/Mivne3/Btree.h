//
//  Assigned by:
//  Group number      61104-62
//
//  File Name:        Btree.h
//  Files in project: main.c, Btree.h, Btree.c
//

#pragma once
#define _CRT_SECURE_NO_WARNINGS

typedef enum {FALSE, TRUE} boolean;
typedef int tree_type;

typedef struct node {
    tree_type data;
    struct node *left;
    struct node *right;
    struct node *father;
} node;

typedef struct {
    node *root;
} btree;

void create_btree(btree *tree);
void fill_tree(btree *tree);
boolean create_root(btree *tree, int data);
void insert_binary(node **root, node *parent, tree_type val);
void delete_btree(node *root);
void inorder_print(node *root);
void print_tree_by_level(node *root);

/* ==================================================================== */

typedef node queue_type;

typedef struct queue_element {
    queue_type data;
    struct queue_element *ptr_next;
} queue_element;

typedef struct {
    queue_element *front;
    queue_element *rear;
    int items_num;
} queue;

void create_queue (queue *pq);
int enqueue (queue_type x, queue *pq);
int dequeue (queue *pq, queue_type *x_data);
int queue_is_empty (queue *pq);
