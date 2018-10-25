#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// freeing already freed memory
void problem1()
{
  char *b;

  b = (char*)malloc(10);
  free(b);
  free(b);
}

// memory leak
void problem2()
{
  char *b;

  for (int i = 0; i <10; i++)
  {
    b = (char*)malloc(10);
  }

  free(b);
}

// reuse of memory that is freed
void problem3()
{
  char *b, *c;

  b = (char*)malloc(100);
  c = b;
  free(b);
  strcpy(c, "hello");
  printf("c is %s\n", c);
}

// pointer out of scope
char* problem4()
{
  char b[20];

  printf("enter your name...");
  gets(b);
  return b;
}

// trying to use a null pointer
void problem5()
{
  char *b;

  b = NULL;
  b[0] = 1;
}

int main(int argc, char const *argv[])
{
  // problem1();
  // problem2();
  // problem3();
  // printf("you typed %s\n", problem4());
  problem5();
  printf("That;s all, folks!\n");

  return 0;
}
