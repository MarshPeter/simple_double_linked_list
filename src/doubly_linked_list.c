#include <stdlib.h>
#include "doubly_linked_list.h"

doubleLinkedList* createList() {

    doubleLinkedList* lst = malloc(sizeof(doubleLinkedList));

    if (lst == NULL) return NULL;

    lst->head = NULL;
    lst->tail = NULL;
    lst->count = 0;

    return lst;
}

node* insert(doubleLinkedList* lst, char* value) {
    
    node* new_node = malloc(sizeof(node));

    if (new_node == NULL) return NULL;

    new_node->value = value;
    lst->count++;

    if (lst->tail != NULL) {
        lst->tail->next = new_node;
        new_node->prev = lst->tail;
        lst->tail = new_node;
        
        return new_node;
    }

    lst->head = lst->tail = new_node;

    return new_node;
}

node* deleteNode(doubleLinkedList* lst, char* valueToDelete) {

    node* nodeToDelete = find(lst, valueToDelete);

    if (nodeToDelete == NULL) return NULL;

    lst->count--;

    if (nodeToDelete == lst->head && nodeToDelete == lst->tail)
    {
        lst->head = lst->tail = NULL;

        return nodeToDelete;
    }

    if (nodeToDelete == lst->head)
    {
        lst->head->next->prev = NULL;
        lst->head = nodeToDelete->next;
        return nodeToDelete;
    }

    if (nodeToDelete == lst->tail) 
    {
        lst->tail->prev->next = NULL;
        lst->tail = nodeToDelete->prev;
        return nodeToDelete;
    }

    nodeToDelete->prev->next = nodeToDelete->next;
    nodeToDelete->next->prev = nodeToDelete->prev;

    nodeToDelete->next = nodeToDelete->prev = NULL;

    return nodeToDelete;

}

node* find(doubleLinkedList* lst, char* value) {
    node* current = lst->head;

    while (current != NULL)
    {
        if (current->value == value) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

