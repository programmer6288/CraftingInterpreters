#include <stdio.h>
#include "DoublyLinkedList.h"

int main() {
    struct DLL *list;
    construct(list);
    insert(list, "Hello", 0);
    insert(list, "World", 0);
    insert(list, "Bitch", 2);
    printList(list);
    printf("%d", find(list, "Hello"));
    return 0;
}