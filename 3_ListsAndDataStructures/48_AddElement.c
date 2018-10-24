#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listitem
{
  struct listitem *next; //pointer to next item
  struct listitem *prev; //pointer to previous item
  int data;
} LISTITEM;

// the queue 'header'
typedef struct
{
  struct listitem *first; // pointer to next item
  struct listitem *last;  // pointer to last item
} LISTHDR;

LISTHDR head;

void enqueue(LISTHDR *queue, LISTITEM *item)
{
  LISTITEM *temp;

  temp = queue->last;             // get the last item in the queue and keep hold of it
  queue->last = item;             // put the item in the queue at the end
  item->prev = temp;              // link back to old 'last' item
  item->next = (LISTITEM *)queue; // set the forward link of the new item
  temp->next = item;              // set the forward link of the old 'last' item to the new one
}

// remove item from the list, return pointer to it or to NULL if the list is empty
LISTITEM *dequeue(LISTHDR *queue)
{
  LISTITEM *temp;

  temp = queue->first;           // get the first item
  if (temp == (LISTITEM *)queue) // if the head of teh queue points to itself ...
  {                              // ... then the queue is empty
    temp = NULL;
  }
  else
  {
    queue->first = temp->next;              // set the queue header to point to the 'second' item
    queue->first->prev = (LISTITEM *)queue; // make the 'new first' item point to the queue header
  }

  return temp;
}

int queue_length(LISTHDR *queue)
{
  int length = 0;
  LISTITEM *temp;

  temp = queue->first;
  do
  {
    if (temp == (LISTITEM *)queue)
    {
      temp = NULL;
      break;
    }
    temp = temp->next;
    length++;
  } while (temp != NULL);

  return length;
}

// this adds an item after 'position' in a queue - returns the item or NULL if the position does not exist
LISTITEM* add_after(LISTHDR* queue, int position, LISTITEM* item)
{
  LISTITEM* temp;
  int i;

  // NOTE: we dnot deal with negative positions in this example, but we could use 
  // a negative position to indicate that we want to use the backward pointers as the postiion
  if (position < 0)
  {
    return NULL;
  }

  temp = queue->first;
  i = 0;
  do {
    // check for an empty queue or if we've gone through the whole queue
    if (temp == (LISTITEM*)queue)
    {
      temp = NULL;
      break;
    }
    if (i == position) {
      // this is where we link the new iem into the queue
      item->next = temp->next;
      temp->next = item;
      item->prev = temp;
      item->next->prev = item;
      break;
    }
    temp = temp->next;
    i++;
  } while (temp != NULL);

  return temp;
}

int main(int argc, char const *argv[])
{
  LISTITEM *temp, *new_item, *data;
  int requested_index;
  char input[50];
  int i = 0;

  // make an empty queue
  head.first = (LISTITEM*)&head;
  head.last  = (LISTITEM*)&head;

  // populate the queue
  for(int i = 0; i < 5; i++)
  {
    temp = (LISTITEM*)malloc(sizeof(LISTITEM));
    temp->data = i;
    enqueue(&head, temp);
  }

  printf("the length of the queue is %d\n", queue_length(&head));
  // print all queue elements
  temp = head.first;
  for(int i = 0; i < 5; i++)
  {
    printf("element with index %d, its data: %d\n", i, temp->data);
    temp = temp->next;
  }

  // add at a used entered index
  printf("enter the index of the queue entry...");
  requested_index = atoi(gets(input));
  temp = (LISTITEM*)malloc(sizeof(LISTITEM));
  temp->data = 9;

  if (add_after(&head, requested_index, temp) != NULL)
  {
    printf("OK: data added at %d\n", requested_index);
  }
  else
  {
    printf("ERROR: cannot add at %d\n", requested_index);
    free(temp);
  }

  // see what we've got
  printf("the length of the queue is now %d\n", queue_length(&head));
  do {
    temp = dequeue(&head);
    if (temp != NULL)
    {
      printf("data: %d\n", temp->data);
      free(temp);
    }
  } while (temp != NULL);

  printf("im out\n");


  return 0;
}
