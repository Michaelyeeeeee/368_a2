#include <stdio.h>
#include <stdlib.h>
#include "window.h"

int main() {
    // buffer for command
    char command[10];
    // int for window num
    int input;
    Windows *windows = (Windows *)malloc(sizeof(Windows));
    windows->list = NULL;
    
    // gets initial input
    scanf("%s %d", command, &input);
    if(command[0] == 'o'){
        open_w(windows, input);
    }
    else{
        printf("Invalid command\n");
    }
    // get next inputs
    while(windows->list && windows->list->head){
        /*
        Node * current = windows->list->head;
        while(current){
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
        */
        scanf("%s %d", command, &input);
        if(command[0] == 'o'){
            open_w(windows, input);
        }
        else if(command[0] == 'c'){
            close_w(windows, input);
        }
        else if(command[0] == 's'){
            switch_w(windows, input);
        }
        else{
            printf("Invalid command\n");
        }
    }

    free_w(windows);
    return 0;
}