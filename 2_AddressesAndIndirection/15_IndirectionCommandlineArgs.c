#include <stdio.h>

/* This program displays any
 * arguments that were passed to it
 */

int main(int argc, char **argv)
{
  int i;

  // (1_ iterate over array of args)
  for (int i = 0; i < argc; i++)
  {
    printf("arg %d is %s\n", i, argv[i]); // prints arg at inex i
  }

  printf("\n\n");

  // (2) dereference each string arg (*argv) via pointer to the pointer
  // to the start of the array of args (**argv)
  for (int i = 0; i < argc; i++)
  {
    printf("arg %d is %s\n", i, *argv);
    argv += 1;
  }

  return 0;
}
