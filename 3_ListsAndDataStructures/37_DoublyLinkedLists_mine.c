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
    LISTITEM *listhead, *temp, *listtail;

    listhead = NULL;
    listtail = NULL;

    // populate the list
    for (int i = 0; i < 3; i++)
    {
        temp = malloc(sizeof(LISTITEM));
        temp->data = i;
        temp->next = listhead;
        if (listhead != NULL) 
            listhead->prev = temp;
        else temp->prev = NULL;
        listhead = temp;
    }

    // now let's see what we got
    temp = listhead;
    while (temp != NULL)
    {
        printf("List item: current is %p, next is %p, previous is %p, data is %d\n", temp, temp->next, temp->prev, temp->data);
        temp = temp->next;
    }

    return 0;
}
