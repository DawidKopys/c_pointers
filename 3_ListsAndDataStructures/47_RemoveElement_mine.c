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

LISTITEM* get_el_at(LISTHDR* queue, int index)
{
  int i;
  LISTITEM *temp, *retVal;


  i = 0;
  temp = queue->first;
  while (i < index)
  {
    if (temp == (LISTITEM*)&head)
    {
      retVal = NULL;
      break;
    }
    temp = temp->next;
    i++;
  }

  return retVal;
}

int main(int argc, char const *argv[])
{
  LISTITEM *temp;
  int requested_index;
  char input[50];

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
  // for(int i = 0; i < 5; i++)
  // {
  //   printf("element with index %d, its data: %d\n", i, temp->data);
  //   temp = temp->next;
  // }
  
  // remove at a used entered index
  // printf("enter the index of the queue entry...");
  // requested_index = atoi(gets(input));

  // temp = get_el_at(&head, 2);
  // printf("You requested item with index %d, its value: %d", requested_index, )
  

  return 0;
}
