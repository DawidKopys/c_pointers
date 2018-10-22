#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listitem {
    struct listitem *next;      //pointer to next item
    struct listitem *prev;      //pointer to previous item
    int data;
} LISTITEM;

LISTITEM head = {(LISTITEM*)&head, (LISTITEM*)&head, -1};
//head.next = (LISTITEM*)&head  first element
//head.prev = (LISTITEM*)&head  last element

int getLength()
{
    int length = 0;
    LISTITEM *temp = head.next;

    while (temp != &head)
    {
        length++;
        temp = temp->next;
    }

    return length;
}

int main(int argc, char const *argv[])
{
    LISTITEM *temp;



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

    //print the list elements
    temp = head.next;
    while (temp != &head)
    {
        printf("Forward  list item: current is %p; next is %p; prev is %p; data is %d\n", temp, temp->next, temp->prev, temp->data);
        temp = temp->next;
    }
    
    printf("The length of the list: %d", getLength());
    
    return 0;
}
