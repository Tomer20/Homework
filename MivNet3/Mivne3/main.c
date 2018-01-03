//
//  Assigned by:
//  Group number      61104-62
//
//  File Name:        main.c
//  Files in project: main.c, Btree.h, Btree.c
//

#include <stdio.h>
#include "Btree.h"
#define _CRT_SECURE_NO_WARNINGS

int main() {
    btree tree;
    int menue = 1;
    while (menue) {
        printf("Please enter your choice:\n=========================\n");
        printf("0. Leave the program.\n1. Enter values to the tree (and print inorder and by levels).\n\
2. Print tree inorder.\n3. Print tree by its levels.\n\nYour choise: ");
        scanf("%d", &menue);
        printf("\n");
        create_btree(&tree);        // Initialize tree
        switch (menue) {
            case 0:
                printf("Exit program.\n");
                break;
            case 1:
                fill_tree(&tree);
            case 2:
                printf("\nYour binary tree - Inorder print using parent (not recursive):\n");
                inorder_print(tree.root);
                if (menue == 2) {
                    continue;
                }
            case 3:
                printf("\nYour binary tree - Levels print:\n");
                print_tree_by_level(tree.root);
                if (menue == 3) {
                    continue;
                }
        }
        delete_btree(tree.root);       // Delete tree after each iteration
    }
    return 1;
}
