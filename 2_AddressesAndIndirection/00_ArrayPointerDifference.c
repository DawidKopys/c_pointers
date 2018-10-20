#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  int t[3] = {1, 2, 3};
  int *p = t;

  printf("t=%d \t&t= %d \t*t=%d\n", t, &t, *t);
  printf("p=%d \t&p= %d \t*p=%d\n", p, &p, *p);
}
