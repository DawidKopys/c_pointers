#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #pragma pack (1)
typedef struct {
  int a;    //4bytes
  double b; //8bytes
  int c;    //4bytes
  long long int d; //8bytes
} MYSTRUCT;

#define COUNT 4

int main(int argc, char const *argv[])
{
  MYSTRUCT *p, *q;
  void *v;

  printf("size of MYSTRUCT = %d\n", sizeof(MYSTRUCT));

  p = (MYSTRUCT*)calloc(COUNT, sizeof(MYSTRUCT));

  for(int i = 0; i < COUNT; i++)
  {
    p[i].a = i;
    p[i].b = 10000000000.0 + i;
    p[i].c = i * 20;
    p[i].d = 4294967286 + i;
  }

  q = p;
  printf("[0] values\na is %d\nb is %f\nc is %d\nd is %lld\n", q->a, q->b, q->c, q->d);
  printf("addresses:\na is %p\nb is %p\nc is %p\nd is %p\n\n", &q->a, &q->b, &q->c, &q->d);

  q = p + 3;
  printf("[3] values\na is %d\nb is %f\nc is %d\nd is %lld\n", q->a, q->b, q->c, q->d);
  printf("addresses:\na is %p\nb is %p\nc is %p\nd is %p\n\n", &q->a, &q->b, &q->c, &q->d);

  v = p + 3;  // look at the third element of the array of MYSTRUCTs

  printf("Struct at index 3\n");
  for(int i = 0; i <sizeof(MYSTRUCT)/sizeof(int); i++)
  {
    printf("v[%d] = %d\n", i, ((int*)v)[i]);
  }

  return 0;
}
