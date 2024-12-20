#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "../src/doubly_linked_list.h"

void testListGetsCreated() {
    doubleLinkedList* lst = createList(); 
    
    assert(lst != NULL);
    assert(lst->count == 0);
    assert(lst->head == NULL);
    assert(lst->tail == NULL);

    printf("List Creation Tests Passed!\n");
}

void testOneListItemInsertedWorks() {
    doubleLinkedList* lst = createList(); 

    insert(lst, "testing");

    assert(lst->count == 1);
    assert(lst->head == lst->tail);
    assert(!strcmp(lst->head->value, "testing"));
    printf("Single insertion Tests Passed!\n");
}

void testMultipleListItemInsertionsWork() {
    doubleLinkedList* lst = createList(); 

    insert(lst, "testing");
    insert(lst, "another test");
    insert(lst, "one last test");

    assert(lst->count == 3);
    assert(lst->head != lst->tail);
    assert(strcmp(lst->head->value, "testing") == 0);
    assert(strcmp(lst->tail->value, "one last test") == 0);
    assert(strcmp(lst->head->next->value, "another test") == 0);

    printf("Multiple insertion tests passed!\n");
}

void testSingleInsertAndFind() {
    doubleLinkedList* lst = createList();

    node* insertedNode = insert(lst, "testing");
    node* foundNode = find(lst, "testing");

    assert(insertedNode == foundNode);
    assert(insertedNode->value == foundNode->value);
    assert(foundNode == lst->head);
    assert(foundNode == lst->tail);

    printf("Single Insert and Find tests passed\n");
}

void testMultipleInsertAndFind() {
    doubleLinkedList* lst = createList();

    insert(lst, "testing");
    insert(lst, "another test");
    node* insertedNode = insert(lst, "again, another test");
    insert(lst, "one last test");

    node* foundNode = find(lst, "again, another test");

    assert(insertedNode == foundNode);
    assert(strcmp(insertedNode->value, foundNode->value) == 0);
    printf("Multiple Insert and Find tests Passed\n");
}

void singleInsertAndDelete() {
    doubleLinkedList* lst = createList();

    node* insertedNode = insert(lst, "testing");
    node* deletedNode = deleteNode(lst, "testing");

    assert(lst->count == 0);
    assert(lst->head == NULL);
    assert(lst->tail == NULL);
    assert(insertedNode == deletedNode);
    assert(strcmp(insertedNode->value, deletedNode->value) == 0);
    printf("Single insert and deleted tests passed!\n");
}

void multipleInsertAndDelete() {
    doubleLinkedList* lst = createList();

    insert(lst, "testing");
    insert(lst, "another test");
    node* insertedNode = insert(lst, "again, another test");
    insert(lst, "one last test");

    node* deletedNode = deleteNode(lst, "again, another test");

    assert(lst->count == 3);
    assert(lst->head != NULL);
    assert(lst->tail != NULL);
    assert(insertedNode == deletedNode);
    assert(strcmp(insertedNode->value, deletedNode->value) == 0);
    printf("Multiple insert and delete tests passed\n");
}

int main() {
    testListGetsCreated();
    testOneListItemInsertedWorks();
    testMultipleListItemInsertionsWork();
    testSingleInsertAndFind();
    testMultipleInsertAndFind();
    singleInsertAndDelete();
    multipleInsertAndDelete();
}
