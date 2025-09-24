#include "window.h"

/*
open_w: Opens a new window at list head with the given input.
Returns the input on success, -1 on failure.
*/
int open_w(Windows * windows, int input){
    // if no windows structure, indicate failure
    if(!windows){
        printf("Windows structure is NULL\n");
        return -1;
    }
    // if no list, create one
    if(!windows->list){
        windows->list = (LinkedList*)malloc(sizeof(LinkedList));
        if(!windows->list){
            printf("Memory allocation failed\n");
            return -1;
        }
        windows->list->head = NULL;
    }
    // create new node and insert at head
    Node * newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation failed\n");
        return -1;
    }
    newNode->data = input;
    newNode->next = windows->list->head;
    windows->list->head = newNode;

    return input;
}
/*
close_w: Closes the window with the given input.
Returns the input on success, -1 on failure.
*/
int close_w(Windows * windows, int input){
    // if no windows structure, indicate failure
    if(!windows){
        printf("Windows structure is NULL\n");
        return -1;
    }
    // if no list or no head, indicate failure
    if(!windows->list || !windows->list->head){
        printf("No windows to close\n");
        return -1;
    }
    
    Node * current = windows->list->head;
    // if head is the one to be closed
    if(current->data == input){
        windows->list->head = current->next;
        free(current);
        return input;
    }
    // search for the node to be closed
    Node * next = current->next;
    while(next && next->data != input){
        current = next;
        next = next->next;
    }
    // if found, remove it
    if(next){
        current->next = next->next;
        free(next);
        return input;
    }
    printf("Window %d not found\n", input);
    return -1;
}

/*
switch_w: Switches the window with the given input to the head of the list.
Returns the input on success, -1 on failure.
*/
int switch_w(Windows * windows, int input){
    // if no windows structure, indicate failure
    if(!windows){
        printf("Windows structure is NULL\n");
        return -1;
    }
    // if no list or no head, indicate failure
    if(!windows->list || !windows->list->head){
        printf("No windows to switch\n");
        return -1;
    }
    // head node
    Node * head = windows->list->head;
    if(head->data == input){
        return input;
    }
    // node to be switched
    Node * current = windows->list->head;
    // find input in list
    while(current && current->data != input){
        current = current->next;
    }
    // if found, swap data with head
    if(current){
        int temp = head->data;
        head->data = current->data;
        current->data = temp;
        return input;
    }
    printf("Window %d not found\n", input);
    return -1;
}

/*
free_w: Frees all memory associated with the Windows structure.
*/
void free_w(Windows * windows){
    if(!windows->list) return;
    Node * current = windows->list->head;
    Node * next;
    while(current){
        next = current->next;
        free(current);
        current = next;
    }
    free(windows->list);
    free(windows);
}
