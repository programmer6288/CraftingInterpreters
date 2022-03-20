struct node {
    struct node *prev;
    struct node *next;
    char *data;
};

struct DLL {
    struct node *head;
    struct node *tail;
    int size;
};

void construct(struct DLL *list);
void insert(struct DLL *list, char *data, int index);
int find(struct DLL *list, char *data);
char *get(struct DLL *list, int index);
char *delete(struct DLL *list, int index);
void printList(struct DLL *list);

