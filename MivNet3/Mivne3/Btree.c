//
//  Assigned by:
//  Group number      61104-62
//
//  File Name:        Btree.c
//  Files in project: main.c, Btree.h, Btree.c
//

#include <stdio.h>
#include <stdlib.h>
#include "Btree.h"
#define _CRT_SECURE_NO_WARNINGS

void create_btree(btree *tree) {        // Create an empty tree
    tree->root = NULL;
}

void fill_tree(btree *tree) {           // Fill tree with data
    tree_type temp_data = 0;
    if (!tree) {
        printf("Tree not created, please initialize tree first.\n");
        return;
    }
    printf("Enter numbers to the tree, stop with '-1':\n");
    while (temp_data != -1) {
        scanf("%d", &temp_data);
        if (temp_data == -1)
            continue;
        insert_binary(&tree->root, NULL, temp_data);
    }
}

boolean create_root(btree *tree, int data) {    // Create root node
    if (tree->root) {   // Don't create root node if there's already one
        return FALSE;
    }
    else {
        tree->root = (node *) malloc(sizeof(node)); // Allocate memory to node
        tree->root->data = data;              // Insert data into created node
        tree->root->father = NULL;
        tree->root->left = NULL;
        tree->root->right = NULL;
        return TRUE;
    }
}

void insert_binary(node **root, node *parent, tree_type val)	{ // Insert value to tree according to the correct location
    node *temp = NULL;
    if (!(*root)) {
        temp = (node *) malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->father = parent;
        temp->data = val;
        *root = temp;
        return;
    }
    if (val < (*root)->data) {      // Insert value to left child if value is smaller than father
        insert_binary(&(*root)->left, *root, val);
    }
    else if (val > (*root)->data) {   // Insert value to right child if value is greater than father
        insert_binary(&(*root)->right, *root, val);
    }
}

void delete_btree(node *root) {           // Remove all nodes from tree
    if (root) {
        if (root->left)                  // Delete left if exists
            delete_btree(root->left);
        if (root->right)                  // Delete right if exists
            delete_btree(root->right);
        free(root);
    }
}

void inorder_print(node *root) {          // Inorder print without recursion
    boolean check_left = FALSE;
    if (!root) {
        printf("Tree is empty, cannot print.\n\n");
        return;
    }
    while (root) {
        if (!check_left) {        // Go to leftmost child as start
            while (root->left)
                root = root->left;
        }
        printf("%d ", root->data);     // Print data
        check_left = TRUE;         // Mark left as done
        if (root->right) {          // If right child exists
            check_left = FALSE;
            root = root->right;
        }
        else if (root->father) {      // Move to father if right child doesn't exist
            while (root->father && root == root->father->right) // Need to check father's father first
                root = root->father;
            if (!root->father)
                break;
            root = root->father;
        }
        else
            break;
    }
    printf("\n");
}

void print_tree_by_level(node *root) {
    node *temp = root;
    queue tempQ;
    create_queue(&tempQ);           // Initialize new queue
    if (!root) {
        printf("Tree is empty, cannot print.\n\n");
        return;
    }
    enqueue(*temp, &tempQ);         // Enter first value to queue
    while (!queue_is_empty(&tempQ)) {
        dequeue(&tempQ, temp);
        printf("%d ", temp->data);    // Print queue's first value
        if (temp->left) {             // Enter new value to queue if left child exists
            enqueue(*temp->left, &tempQ);
        }
        if (temp->right) {             // Enter new value to queue if right child exists
            enqueue(*temp->right, &tempQ);
        }
    }
    printf("\n\n");
}

/* ==================================================================== */

void create_queue (queue *pq) {           // Initalize new queue
    pq->items_num = 0;
    pq->front = NULL;
    pq->rear = NULL;
}

int enqueue (queue_type x, queue *pq) {     // Enter value to queue
    queue_element *temp = (queue_element *) malloc(sizeof(queue_element));
    if (!temp)
        return 0;
    temp->data = x;
    temp->ptr_next = NULL;
    if (pq->items_num != 0) {
        pq->rear->ptr_next = temp;
        pq->rear = pq->rear->ptr_next;
    }
    else
        pq->front = pq->rear = temp;
    pq->items_num++;
    return 1;
}

int dequeue (queue *pq, queue_type *x_data) {   // Take value from queue's front
    queue_element *temp;
    if (pq->items_num == 0)
        return 0;
    temp = pq->front;
    pq->front = temp->ptr_next;
    *x_data = temp->data;
    free (temp);
    if (!pq->front)
        pq->rear = NULL;
    pq->items_num--;
    return 1;
}

int queue_is_empty (queue *pq) {
    return pq->items_num == 0;
}
