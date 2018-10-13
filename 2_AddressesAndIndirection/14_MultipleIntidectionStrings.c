#include <stdio.h>

#define LENGTH 3

char* words[LENGTH];  //some strings

int main()
{
  char *pc;   //a pointer to a character
  char **ppc; //a pointer to a pointer to a character

  printf("Multiple indirection example\n");

  //initialize our string array
  words[0] = "zero";
  words[1] = "one";
  words[2] = "two";
  for (int i = 0; i < LENGTH; i++)
  {
    printf("%s\n", words[i]);
  }

  /*
  * B: a poitner to an array of strings
  *   - the same as a poitner to a pointer to a character
  */
  printf("\nNow print the chars in each string...\n");
  ppc = words;
  for (int i = 0; i < LENGTH; i++)
  {
    ppc = words + i;
    pc = *ppc;
    while (*pc != 0)        //process each characther in a string
    {
      printf("%c ",  *pc);     //print out each characther of the string invidually
      pc += 1;
    }
    printf("\n");
  }
  return 0;
}
