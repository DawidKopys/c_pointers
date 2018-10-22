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

LISTHDR src;
LISTHDR dst;
LISTHDR src2;
LISTHDR dst2;

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
  if (temp == (LISTITEM*)queue)   // if the head of the queue points to itself ...
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

void queue_copy(LISTHDR* src, LISTHDR* dst)
{
  LISTITEM *temp;
  LISTITEM *temp2;

  temp = src->first;
  while (temp != (LISTITEM*)src)
  {
    temp2 = (LISTITEM*)malloc(sizeof(LISTITEM));
    *temp2 = *temp;
    enqueue(dst, temp2);
    temp = temp->next;
  }
}

int main(int argc, char const *argv[])
{
  LISTITEM *temp;

  // make an empty queues
  src.first = (LISTITEM*)&src;
  src.last = (LISTITEM*)&src;
  dst.first = (LISTITEM*)&dst;
  dst.last = (LISTITEM*)&dst;
  src2.first = (LISTITEM*)&src2;
  src2.last = (LISTITEM*)&src2;
  dst2.first = (LISTITEM*)&dst2;
  dst2.last = (LISTITEM*)&dst2;

  // populate src queue
  for (int i = 0; i < 3; i++)
  {
    temp = (LISTITEM*)malloc(sizeof(LISTITEM));
    temp->data = i;
    enqueue(&src, temp);
  }

  // populate src2 queue
  for (int i = 0; i < 3; i++)
  {
    temp = (LISTITEM*)malloc(sizeof(LISTITEM));
    temp->data = i;
    enqueue(&src2, temp);
  }

  // transfer elements from src to dst
  do {
    temp = dequeue(&src);
    if (temp != NULL)
    {
      printf("data is %d\n", temp->data);
      enqueue(&dst, temp);
    }
  } while(temp != NULL);

  // print dst queue contents
  printf("destination queue:\n");
  do {
    temp = dequeue(&dst);
    if (temp != NULL)
    {
      printf("destination data is %d\n", temp->data);
      free(temp);
    }
  } while (temp != NULL);

  printf("source queue:\n");
  temp = dequeue(&src);
  if (temp == NULL)
  {
    printf("source queue is empty\n");
  }

  printf("\ncopy:\n");
  queue_copy(&src2, &dst2);

  // print dst2 queue contents
  printf("destination2 queue:\n");
  do {
    temp = dequeue(&dst2);
    if (temp != NULL)
    {
      printf("destination2 data is %d\n", temp->data);
      free(temp);
    }
  } while (temp != NULL);

  // print src2 queue contents
  printf("source2 queue:\n");
  do {
    temp = dequeue(&src2);
    if (temp != NULL)
    {
      printf("source2 data is %d\n", temp->data);
      free(temp);
    }
  } while (temp != NULL);

  return 0;
}
