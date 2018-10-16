#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAXSTRLEN 100

char * string_function(char *astring)
{
  char* s;

  s = (char*)malloc(MAXSTRLEN);
  s[0] = 0; // need this to initialize the buffer created  by malloc - make s an empty string
  strcat(s, "Hello ");
  /* zamiast linii 12 oraz 13 możemy napisać:  strncpy(s, "Hello ", sizeof "Hello ");
   * koniecczność linii 12 lub używania strncpy przed strcat wynika z tego,
   * że wartość zmiennych jest zainicjalozowana jakimiś wartościami (śmieci), musimy się ich najpierw pozbyc lub nadpisać nowymi a nie dołączać
   * nowe stringi do tych śmieci
   */
  strcat(s, astring);
  strcat(s, "\n");
  return s;
}

int main(int argc, char const *argv[]) {
  printf(string_function("Fred"));
  printf(string_function("Gussie Fink-Nottle"));
  return 0;
}
