//
//  Assigned by:
//  Group number      61108-61
//
//  File Name:        trio.h
//  Files in project: main.c, main.h, linked_list.c,
//                    inked_list.h, trio.c, trio.h
//

#pragma once
#define _CRT_SECURE_NO_WARNINGS

typedef struct TrioType {           // Three-values type
    int sum;
    int index_row;
    int index_col;
} TrioType;

typedef struct TrioListNode {       // Node type that stores TrioType as its data
    TrioType trio_data;
    struct TrioListNode* next;
    struct TrioListNode* prev;
} TrioListNode;

typedef struct {                    // List type that points on TrioListNode head and tail
    TrioListNode* head;
    TrioListNode* tail;
} LinkedTrioList;

void createTrioList(LinkedTrioList* list);
TrioListNode* createTrioNode(TrioType node_data);
void insertLastTrioNode(TrioType value, LinkedTrioList* list);
void printTrioList(LinkedTrioList* list);
int isTrioListEmpty(LinkedTrioList* list);
void freeTrioList(LinkedTrioList* list);
