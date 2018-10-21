// a stack is last-in, first-out (LIFO) data structuture

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int a;
  double b;
} DATA;

DATA *base;
DATA *end;
DATA *top;

#define STACKSIZE 5

// pushes an item onto the top of the stack - returns 1 if the stack size was not exceeded, otherwise 0
int push(DATA* data)
{
  int ok;

  if (top == end)
  {
    ok = 0;
  }
  else
  {
    memcpy(top, data, sizeof(DATA));
    top = top + 1;
    ok = 1;
  }
  return ok;
}

// pop a data item off the top of the stack
DATA* pop()
{
  DATA* data;

  if (top == base)
  {
    data = NULL;
  }
  else
  {
    top = top - 1;
    data = top;
  }
  return data;
}

int main(int argc, char const *argv[])
{
  DATA data, *pdata;

  base = (DATA*)malloc(STACKSIZE + sizeof(DATA));
  end = base + STACKSIZE;
  top = base;

  // add data items to the stack until the stack memory is exhausted
  for (size_t i = 0; ; i++) {
    data.a = i;
    data.b = i * 2;
    if (!push(&data))
    {
      break;
    }
  }

  printf("first item = %d : %f\n", base->a, base->b);
  pdata = base + 4; // count 4 item up from the 1st struct (at base)
  printf("last item %d : %f\n", pdata->a, pdata->b);

  // now pop the data items off the top of teh stack until there are no more
  do {
    pdata = pop();
    if (pdata != NULL) printf("data popped is %d: %f\n", pdata->a, pdata->b);
  } while (pdata != NULL);

  // NOTE: we do not call free for each item 'popped' from the stack
  // because I may want to push onto the stack again.
  // Instead, I call 'free' to release the entire stack when I've finished with it

  free(base);
  return 0;
}
