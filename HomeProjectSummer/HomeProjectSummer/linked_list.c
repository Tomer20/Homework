//
//  Assigned by:
//  Group number      61108-61
//
//  File Name:        linked_list.c
//  Files in project: main.c, main.h, linked_list.c,
//                    inked_list.h, trio.c, trio.h
//

#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#define _CRT_SECURE_NO_WARNINGS

void createList(LinkedList* list) {                 // Initialize list
    list->head = NULL;
    list->tail = NULL;
}

ListNode* createNode(int node_data) {               // Initialize node
    ListNode* new_node = (ListNode *) malloc(sizeof(ListNode));
    new_node->data = node_data;                    // Populate trio_data with the given data
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void insertLastNode(int value, LinkedList* list) {    // Insert node to list's tail
    ListNode* node = createNode(value);
    if (isListEmpty(list)) {
        list->head = list->tail = node;             // Make head and tail pointing to the node
    }
    else {
        list->tail->next = node;                    // Make old last node point to created node
        node->prev = list->tail;                    // Make old list->tail as previous node
        list->tail = node;                         // Point list->tail to the created node
    }
}

void printList(LinkedList* list) {                   // Print List
    ListNode* tmp = list->head;
    while (tmp) {
        printf("->[%d]", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int isListEmpty(LinkedList* list) {                  // Check if list is empty
    return (int)(list->head == NULL);
}

void fillList(LinkedList* list) {                    // Fill list with input from user untill receive negative number
    int num;
    printf("Enter number to the list: ");
    scanf("%d", &num);
    while (num >= 0) {
        insertLastNode(num, list);
        printf("Enter number to the list: ");
        scanf("%d", &num);
    }
}

int deleteFirst(LinkedList* list) {                  // Delete first node from a list
    ListNode *temp = list->head;                     // Save reference to first node
    if (isListEmpty(list)) {                         // Nothing to delete if list is empty
        return 0;
    }
    if (!temp->next) {                              // If only one node - point head and tail to NULL
        list->head = list->tail = NULL;
    }
    else {
        list->head->next->prev = NULL;                // Point previous of next node to NULL
        list->head = list->head->next;               // Set next node as head
    }
    free(temp);
    return 1;
}

int deleteLast(LinkedList* list) {                   // Delete last node from a list
    ListNode* temp = list->tail;                     // Save reference to first node
    if (isListEmpty(list)) {                         // Nothing to delete if list is empty
        return 0;
    }
    if (!temp->prev) {                              // If only one node - point head and tail to NULL
        list->head = list->tail = NULL;
    }
    else {
        list->tail->prev->next = NULL;                // Point next of previous node to NULL
        list->tail = list->tail->prev;               // Set previous node as tail
    }
    free(temp);
    return 1;
}

ListNode* deleteLink(ListNode* current, LinkedList *list) { // Delete a given node from a given list
    ListNode* temp = current;                       // Create temp as current node
    if (isListEmpty(list) || !current) {             // Nothing to delete if list is empty or if node is NULL
        return NULL;
    }
    current = current->next;                       // Move current to next
    if (temp == list->head) {                       // If first node of the list - deleteFirst
        deleteFirst(list);
        return current;
    }
    if (temp == list->tail) {                       // If last node of the list - deleteLast
        deleteLast(list);
        return current;
    }
    if (temp->prev) {                               // Bypass the temp link
        temp->prev->next = temp->next;
    }
    if (temp->next) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    return current;
}

void freeList(LinkedList* list) {                   // Free List and nodes
    ListNode* head = list->head;
    ListNode* to_delete = NULL;
    while (head) {
        to_delete = head;
        head = head->next;
        free(to_delete);
    }
    createList(list);                              // Call createList to initialize list to point to NULL
}
