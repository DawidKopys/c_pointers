#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 4

int main(int argc, char const *argv[]) {
  int* p;
  int a[COUNT];

  printf("size of an 'int' is %d\n", sizeof(int));
  //initialize our array
  for(int i = 0; i < COUNT; i++) a[i] = i;
  //let's do some pointer arithmetic
  p = a;  //set the pointer to the start of the array
  printf("address of a is %p; value of p is %p [%d]; value pointed to by p is %d\n", a, p, p, *p);

  p = p + 1;
  printf("address of a is %p; value of p is %p [%d]; value pointed to by p is %d\n", a, p, p, *p);

  //increment p by another 2, the value pointed to by 'p' is now a[3]
  p = p + 2;
  printf("address of a is %p; value of p is %p [%d]; value pointed to by p is %d\n", a, p, p, *p);

  //what happens if we go beyoun the array end? there's nothing to stop you or warn you
  p = p + 1;
  printf("address of a is %p; value of p is %p [%d]; value pointed to by p is %d\n", a, p, p, *p);

  return 0;
}
