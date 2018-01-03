//
//  Assigned by:
//  Group number      61108-61
//
//  File Name:        inked_list.h
//  Files in project: main.c, main.h, linked_list.c,
//                    inked_list.h, trio.c, trio.h
//

#pragma once
#define _CRT_SECURE_NO_WARNINGS

typedef struct ListNode {       // Node type that stores int as its data
    int data;
    struct ListNode *next;
    struct ListNode *prev;
} ListNode;

typedef struct {                // List type that points on ListNode head and tail
    ListNode* head;
    ListNode* tail;
} LinkedList;

void createList(LinkedList* list);
ListNode* createNode(int node_data);
void insertLastNode(int value, LinkedList* list);
void printList(LinkedList* list);
int isListEmpty(LinkedList* list);
void fillList(LinkedList* list);
int deleteFirst(LinkedList* list);
int deleteLast(LinkedList* list);
ListNode* deleteLink(ListNode* current, LinkedList* list);
void freeList(LinkedList* list);
