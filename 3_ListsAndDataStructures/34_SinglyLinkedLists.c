#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listitem {
    struct listitem *next;      //pointer to next item
    int data;
} LISTITEM;

int main(int argc, char const *argv[])
{
    LISTITEM *listhead, *temp;

    listhead = NULL;

    // now populate the list
    for (int i = 0; i < 3; i++)
    {
        temp = malloc(sizeof(LISTITEM));
        temp->data = i;
        temp->next = listhead;
        listhead = temp;
    }

    // now let's see what we got
    temp = listhead;
    while (temp != NULL)
    {
        printf("List item: current is %p, next is %p, data is %d\n", temp, temp->next, temp->data);
        temp = temp->next;
    }

    return 0;
}
