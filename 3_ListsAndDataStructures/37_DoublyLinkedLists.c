#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listitem {
    struct listitem *next;      //pointer to next item
    struct listitem *prev;      //pointer to previous item
    int data;
} LISTITEM;

int main(int argc, char const *argv[])
{
    LISTITEM *temp, head;

    head.next = (LISTITEM*)&head;
    head.prev = (LISTITEM*)&head;
    head.data = -1;

    //populate the list
    
    for(int i = 0; i < 3; i++)
    {
        temp = malloc(sizeof(LISTITEM));
        temp->data = i;
        temp->next = head.next;
        head.next = temp;
        temp->prev = &head;
        temp->next->prev = temp;
    }
    
    // now lets see what we got going forward
    temp = head.next;
    while (temp != &head)
    {
        printf("Forward  list item: current is %p; next is %p; prev is %p; data is %d\n", temp, temp->next, temp->prev, temp->data);
        temp = temp->next;
    }

    printf("\n");

    // and going backwards
    temp = head.prev;
    while (temp != &head)
    {
        printf("Backward list item: current is %p; next is %p; prev is %p; data is %d\n", temp, temp->next, temp->prev, temp->data);
        temp = temp->prev;
    }


    return 0;
}
