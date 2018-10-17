#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct kakao{
  int a;            // 4bytes
  int b;            // 4bytes
  double c;         // 8bytes
  long long int d;  // 8bytes
} MYSTRUCT;

#define COUNT 4

int main(int argc, char const *argv[]) {
  MYSTRUCT *p, *q;
  MYSTRUCT a;

  struct kakao e;

  a.a = 0;
  a.b = 1;
  a.c = (double)2;
  a.d = 3;
  printf("%d %d %f %d\n", a.a, a.b, a.c, a.d);

  e.a = 3;
  printf("%d\n", e.a);

  return 0;
}
