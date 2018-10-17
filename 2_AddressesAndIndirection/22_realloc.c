#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//look at free and realloc
int main(int argc, char const *argv[]) {
  char* s;
  int i;

  i = sizeof "hello";
  s = malloc(i);
  strncpy(s, "hello", i);
  printf("s is %s\n", s);

  realloc(s, 12);
  strncpy(s, "hello", i);
  strcat(s, " world");
  printf("s is now %s\n", s);

  free(s);

  return 0;
}
