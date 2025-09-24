#include <stdio.h>
#include <stdlib.h>

void open(int input);
void close(int input);
void switch(int input);

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

typedef struct Window {
    LinkedList* list;
} Window;