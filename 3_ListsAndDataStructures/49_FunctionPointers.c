#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int(*PFI)(int);

// our example function
int square(int a)
{
  return a*a;
}

int main(int argc, char const *argv[])
{
  // int (*test) (int);
  PFI test;
  char input[50];
  int value;
  int result, result2;

  // set the function pointer 'test' to the address of the function square
  test = square;

  printf("square = %p, &square = %p\n", square, &square);

  // try it out
  printf("enter the number to square: ");
  value = atoi(gets(input));
  result = test(value);
  printf("the result is %d\n", result);
  result2 = (*test)(value);
  printf("the result2 is %d\n", result2);

  return 0;
}
