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
int insert(struct DLL *list, char *data, int index);
int find(struct DLL *list, char *data);
int get(struct DLL *list, int index);
int delete(char *data);
void printList(struct DLL *list);

