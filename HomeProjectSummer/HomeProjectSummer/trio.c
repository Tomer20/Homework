//
//  Assigned by:
//  Group number      61108-61
//
//  File Name:        trio.c
//  Files in project: main.c, main.h, linked_list.c,
//                    inked_list.h, trio.c, trio.h
//

#include <stdlib.h>
#include <stdio.h>
#include "trio.h"
#define _CRT_SECURE_NO_WARNINGS

void createTrioList(LinkedTrioList* list) {             // Initialize list
    list->head = NULL;
    list->tail = NULL;
}

TrioListNode* createTrioNode(TrioType node_data) {      // Initialize node
    TrioListNode* new_node = (TrioListNode *) malloc(sizeof(TrioListNode));
    new_node->trio_data = node_data;                  // Populate trio_data with the given data
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void insertLastTrioNode(TrioType value, LinkedTrioList* list) {     // Insert node to list's tail
    TrioListNode* trio_node = createTrioNode(value);
    if (isTrioListEmpty(list)) {
        list->head = list->tail = trio_node;          // Make head and tail pointing to the node
    }
    else {
        list->tail->next = trio_node;                 // Make old last node point to created node
        trio_node->prev = list->tail;                 // Make old list->tail as previous node
        list->tail = trio_node;                      // Point list->tail to the created node
    }
}

void printTrioList(LinkedTrioList* list) {              // Print List
    TrioListNode* tmp = list->head;
    while (tmp) {
        printf("->[%d]", tmp->trio_data.sum);
        tmp = tmp->next;
    }
    printf("\n");
}

int isTrioListEmpty(LinkedTrioList* list) {             // Check if list is empty
    return list->head == NULL;
}

void freeTrioList(LinkedTrioList* list) {               // Free List and nodes
    TrioListNode* to_delete = NULL;
    while (list->head) {
        to_delete = list->head;
        list->head = list->head->next;
        free(to_delete);
    }
    createTrioList(list);                              // Call createTrioList to initialize list to point to NULL
}
