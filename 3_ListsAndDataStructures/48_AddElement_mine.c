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

  if (index < 0)
  {
    retVal = NULL;
  }
  else
  {
    i = 0;
    temp = queue->first;
    while (i < index)
    {
      temp = temp->next;
      i++;
      if (temp == (LISTITEM*)queue)
      {
        temp = NULL;
        break;
      }
    }

    retVal = temp;
  }

  return retVal;
}

int add_at_element(LISTHDR* queue, LISTITEM*  temp, int index)
{
  LISTITEM *prev_item, *next_item;
  int retVal = 1;

  prev_item = get_el_at(queue, index-1);
  next_item = get_el_at(queue, index);

  if ((prev_item == NULL) && (next_item == NULL))
  {
    // incorrect element index, return 0
    retVal = 0;
  }
  else
  {    
    if (prev_item != NULL) 
    {
      prev_item->next = temp;
      temp->prev = prev_item;
    }
    else
    {
      // we are inserting at first item, update queue->first as well
      temp->prev = (LISTITEM*)queue;
      queue->first =  temp;
    }

    if (next_item != NULL)
    {
      next_item->prev = temp;
      temp->next = next_item;
    }
    else
    {
      // we are inserting at last item, update queue->last as well
      temp->next = (LISTITEM*)queue;
      queue->last = temp;
    }
  }

  return retVal;
}

int add_at_data(LISTHDR* queue, int data, int index)
{
  LISTITEM  *temp, *prev_item, *next_item;
  int retVal = 1;

  prev_item = get_el_at(queue, index-1);
  next_item = get_el_at(queue, index);

  if ((prev_item == NULL) && (next_item == NULL))
  {
    // incorrect element index, return 0
    retVal = 0;
  }
  else
  {
    temp = (LISTITEM*)malloc(sizeof(LISTITEM));
    temp->data = data;
    
    if (prev_item != NULL) 
    {
      prev_item->next = temp;
      temp->prev = prev_item;
    }
    else
    {
      // we are inserting at first item, update queue->first as well
      temp->prev = (LISTITEM*)queue;
      queue->first =  temp;
    }

    if (next_item != NULL)
    {
      next_item->prev = temp;
      temp->next = next_item;
    }
    else
    {
      // we are inserting at last item, update queue->last as well
      temp->next = (LISTITEM*)queue;
      queue->last = temp;
    }
  }

  return retVal;
}

int main(int argc, char const *argv[])
{
  LISTITEM *temp, *data;
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

  if (add_at_data(&head, 9, requested_index))
  {
    printf("OK: data added at %d\n", requested_index);
  }
  else
  {
    printf("ERROR: cannot add at %d\n", requested_index);
  }

  // add another item at a used entered index
  printf("enter the index of the queue entry...");
  requested_index = atoi(gets(input));
  temp = (LISTITEM *)malloc(sizeof(LISTITEM));
  temp->data = 18;

  if (add_at_element(&head, temp, requested_index))
  {
    printf("OK: data added at %d\n", requested_index);
  }
  else
  {
    printf("ERROR: cannot add at %d\n", requested_index);
    free(temp);
  }

  // print the list contents
  do {
    temp = dequeue(&head);
    if (temp != NULL)
    {
      printf("element dequeued: %d\n", temp->data);
      free(temp);
    }
  } while (temp != NULL);

  printf("im out\n");

  return 0;
}
