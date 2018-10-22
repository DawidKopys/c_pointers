#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//this is what is going to be in the queue
typedef struct listitem {
    struct listitem *next;
    struct listitem *prev;
    int data;
} ListItem_T;

// this is the queue 'header'
typedef struct {
    struct listitem *first; //pointer to the first item
    struct listitem *last;  //pointer to the last item
} ListHeader_T;

ListHeader_T head;          //declare this statically so that 'enqueue' and 'dequeue' can use it

//put an item in the queue, at the end
void enqueue(ListItem_T *item)
{
    ListItem_T *temp;

    temp = head.last;       // get the 'last' item in the queue and keep hold of it
    head.last = item;       // put the item in the queue at the end
    item->prev = temp;      // link back to old 'last' item
    item->next = (ListItem_T*)&head;    // set the forward link of the new item
    temp->next = item;      // and finally, set the forward link of the old 'last' item to the new one
}

//remove an item from the front of the queue - return the item or NULL if there are no more items
ListItem_T* dequeue() {
    ListItem_T *temp;

    temp = head.first;      // get the first item
    if (temp == (ListItem_T*)&head)     // if the head of teh queue points to itself ...
    {                                   // ... then the queue is empty
        temp = NULL;
    }
    else
    {
        head.first = temp->next;        // set the queue header to point to the 'second' item
        head.first->prev = (ListItem_T*)&head;  // make the 'new first' item point to the queue header
    }

    return temp;
}

int main(int argc, char const *argv[])
{
    ListItem_T *temp;

    // first, make an empty queue
    // ... which is a queue where the header points to itself and there are no items in it
    head.first = (ListItem_T*)&head;
    head.last = (ListItem_T*)&head;

    // populate the queue

    for(int i = 0; i < 3; i++)
    {
        temp = (ListItem_T*)malloc(sizeof(ListItem_T));
        temp->data = i;
        enqueue(temp);      // put the item in the queue
    }

    printf("first item = %d\n", head.first->data);
    printf("last item = %d\n\n", head.last->data);

    // dequeue from the end of the queue
    do {
        temp = dequeue();   // if the queue is empty we will get NULL returned
        if (temp != NULL) {
            printf("data is %d\n", temp->data);
            free(temp);     // free the memory
        }
    } while (temp != NULL); // keep going until the queue is empty

    return 0;
}
