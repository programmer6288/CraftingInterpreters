#include "DoublyLinkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void construct(struct DLL *list) {
    list->head = 0;
    list->tail = 0;
    list->size = 0;
}

void insert(struct DLL *list, char *data, int index) {
    if (index > list->size) {
        printf("Can't insert data at index %d on list of size %d\n", index, list->size);
        return;
    }
    char *newData = malloc(strlen(data));
    strcpy(newData, data);
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = newData;
    if (list->size == 0) {
        list->head = newNode;
        list->tail = list->head;
        list->size = 1;
        return;
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
}

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

char *get(struct DLL *list, int index) {
    struct node *cursor = list->head;
    if (index >= list->size) {
        return 0;
    }
    for (int i = 0; i < index; i++) {
        cursor = cursor->next;
    }
    return cursor->data;
}

char *delete(struct DLL *list, int index) {
    if (index >= list->size) {
        printf("Cannot remove given index from list (Out of Bounds Error)\n");
        return 0;
    }
    struct node *cursor = list->head;
    for (int i = 0; i < index; i++) {
        cursor = cursor->next;
    }
    char *data = cursor->data;
    if (cursor == list->head) {
        if (list->size == 1) {
            list->head = 0;
            list->tail = 0;
        } else {
            cursor->next->prev = cursor->prev;
            list->head = list->head->next;
            list->head->prev = 0;
        }
    } else {
        cursor->prev->next = cursor->next;
        if (cursor->next) {
            cursor->next->prev = cursor->prev;
        } else {
            list->tail = list->tail->prev;
            list->tail->next = 0;
        }
    }
    list->size--;
    free(cursor);
    return data;
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