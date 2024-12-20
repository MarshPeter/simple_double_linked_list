
#ifndef DOUBLYL_LINKED_LIST_H
#define DOUBLYL_LINKED_LIST_H

typedef struct Node node;
typedef struct DoubleLinkedList doubleLinkedList;

struct Node {
    char* value;
    node* next;
    node* prev;
};

struct DoubleLinkedList {
    node* head;
    node* tail;
    int count;
};

doubleLinkedList* createList();
node* insert(doubleLinkedList* lst, char* value);
node* find(doubleLinkedList* lst, char* value);
node* deleteNode(doubleLinkedList* lst, char* valueToDelete);

#endif
