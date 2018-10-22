#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listitem {
    struct listitem *next;      //pointer to next item
    struct listitem *prev;      //pointer to previous item
    int data;
} LISTITEM;

// the queue 'header'
typedef struct {
    struct listitem *first;     // pointer to next item
    struct listitem *last;      // pointer to last item
} LISTHDR;

LISTHDR head;

void enqueue(LISTHDR *queue, LISTITEM *item)
{
    LISTITEM *temp;

    temp = queue->last;     // get the last item in the queue and keep hold of it
    queue->last = item;     // put the item in the queue at the end
    item->prev = temp;      // link back to old 'last' item
    item->next = (LISTITEM*)queue;  // set the forward link of the new item
    temp->next = item;      // set the forward link of the old 'last' item to the new one    
}

// remove item from the list, return pointer to it or to NULL if the list is empty
LISTITEM* dequeue(LISTHDR* queue)
{
    LISTITEM* temp;

    temp = queue->first;    // get the first item
    if (temp == (LISTITEM*)queue)   // if the head of teh queue points to itself ...
    {                               // ... then the queue is empty
        temp = NULL;
    }
    else
    {
        queue->first = temp->next;  // set the queue header to point to the 'second' item
        queue->first->prev = (LISTITEM*)queue;  // make the 'new first' item point to the queue header
    }

    return temp;
}

int queue_length(LISTHDR* queue)
{
    int length = 0;
    LISTITEM* temp;

    temp = queue->first;
    do {
        if (temp == (LISTITEM*)queue)
        {
            temp = NULL;
            break;
        }
        temp = temp->next;
        length++;
    } while (temp != NULL);

    return length;
}

int queue_length2(LISTHDR* queue)
{
    int length = 0;
    LISTITEM* temp;

    temp = queue->first;
    while (temp != (LISTITEM*)queue)
    {
        length++;
        temp = temp->next;
    }

    return length;
}

int main(int argc, char const *argv[])
{
    LISTITEM *temp;

    // make an empty queue 
    head.first = (LISTITEM*)&head;
    head.last = (LISTITEM*)&head;

    printf("At start, the length of the queue is %d\n", queue_length2(&head));
	for (int i = 0; i < 3; i++) {	// as before, populate the queue
		temp = malloc(sizeof(LISTITEM));    // allocate some memory for the new queue item
		temp->data = i;				        // set the item's data to the loop count so that we can see where it is in the queue
		enqueue(&head, temp);	            // and put it in the queue
	}
    printf("After initialization, the length of the queue is %d\n\n", queue_length2(&head));

    // see what we've got left
	do {							// keep going until the queue is empty
		printf("The length of the queue is now %d\n", queue_length2(&head));
		temp = dequeue(&head);		// if the queue is empty we will get NULL returned
		if (temp != NULL) {
			printf("Dequeued item. Data is %d\n", temp->data);
			free(temp);				// call 'free' to tidy up 
		}
	} while (temp != NULL);

    return 0;
}
