#include "DoublyLinkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void construct(struct DLL *list) {
    list->head = 0;
    list->tail = 0;
    list->size = 0;
}
// Insert node with data at index, -1 if index not in list
int insert(struct DLL *list, char *data, int index) {
    if (index > list->size) {
        printf("Can't insert data at index %d on list of size %d", index, list->size);
        return -1;
    }
    char *newData = malloc(strlen(data));
    strcpy(newData, data);
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = newData;
    if (list->size == 0) {
        list->head = newNode;
        list->tail = list->head;
        list->size = 1;
        return 0;
    }
    struct node *cursor = list->head;
    for (int i = 0; i < index; i++) {
        cursor = cursor->next;
    }
    if (!cursor) {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        newNode->next = 0;
        list->tail = newNode;
    } else {
        if (cursor != list->head) {
            cursor->prev->next = newNode;
        } else {
            list->head = newNode;
        }
        newNode->prev = cursor->prev;
        newNode->next = cursor;
        cursor->prev = newNode;
    }
    list->size++;
    return 0;
}

// Returns index of data, -1 if not in list
int find(struct DLL *list, char *data) {
    struct node *cursor = list->head;
    int index = 0;
    while (cursor) {
        if (!strcmp(cursor->data, data)) {
            return index;
        }
        cursor = cursor->next;
        index++;
    }
    return -1;
}

int get(struct DLL *list, int index) {
    struct node *cursor = list->head;
    if (index >= list->size) {
        return 0;
    }
    for (int i = 0; i < index; i++) {
        cursor = cursor->next;
    }
    return cursor->data;
}

int delete(char *data) {
    return -1;
}

void printList(struct DLL *list) {
    struct node *cursor = list->head;
    int index = 0;
    while (cursor) {
        printf("index: %d, data: %s\n", index, cursor->data);
        cursor = cursor->next;
        index++;
    }
}