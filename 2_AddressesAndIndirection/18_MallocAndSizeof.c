#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char* s;
  int stringsize;

  stringsize = sizeof("hello");   //first, work out how big "hello" is
  printf("size of 'hello' is %d\n", stringsize);  //note that it is SIX bytes long (not fice) so as to allow for the terminating null character

  s = malloc(stringsize);         //now allocate some memory of sufficient size to hold the strin
  if (s == NULL)                  //malloc returns 0 (NULL) if it fails
  {
    printf("malloc failed!\n");
    exit(0);
  }

  // now copy the string int othe newly allocated memory
  strncpy(s, "hello", stringsize);

  // and change the first character (just to show that we can)
  printf("s is %s\n", s);
  s[0] = 'c';
  printf("s is now %s\n", s);

  return 0;
}
