#include <stdio.h>
#include <stdlib.h>

int open_w(Windows * windows, int input);
int close_w(Windows * windows, int input);
int switch_w(Windows * windows, int input);
void free_w(Windows * windows);

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

typedef struct Windows {
    LinkedList* list;
} Windows;