#include <stdio.h>
#include "DoublyLinkedList.h"

int main() {
    struct DLL *list;
    construct(list);
    insert(list, "Hello", 0);
    insert(list, "World", 0);
    insert(list, "Dude", 2);
    printList(list);
    printf("%d\n", find(list, "Hello"));
    printf("%s\n", get(list, 0));
    printf("%s\n", get(list, 1));
    printf("%s\n", get(list, 2));
    printf("%s\n", delete(list, 0));
    printList(list);
    printf("%s\n", delete(list, 1));
    printList(list);
    printf("%p\n", list->head);
    printf("%p\n", list->tail);
    printf("%s\n", delete(list, 0));
    printList(list);
    insert(list, "Hello", 0);
    insert(list, "World", 0);
    insert(list, "Dude", 2);
    printList(list);
    return 0;
}