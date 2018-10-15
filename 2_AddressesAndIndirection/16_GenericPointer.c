#include <stdio.h>

#define LENGTH 3

int data[LENGTH];     //some integers
char* words[LENGTH];  //some strings

int main()
{
  void *gp;     //a generic pointer

  printf("Generic poitner example\n");

  // initialize our integer array
  for (int i = 0; i < LENGTH; i++)
  {
    data[i] = i;
  }
  for (int i = 0; i < LENGTH; i++)
  {
    printf("%d\n", data[i]);
  }

  //initialize our string array
  words[0] = "zero";
  words[1] = "one";
  words[2] = "two";
  for (int i = 0; i < LENGTH; i++)
  {
    printf("%s\n", words[i]);
  }

  /*
   * C: example of a generic pointer
   */
   gp = data;         // set the generic poitner to the start of the integer array
   printf("\ndata array address is %p\n", gp);  // and print it out - no cast is needed there
   // now, print out the first item of the array
   // - a cast is now nweeded to let the compiler know what sort of thing is being pointed to by the generic pointer
   printf("item poitned to by gp is %d\n", *(int*)gp);
   // the cast tells the compiler what the address type is and so we can do address arithmetic
   gp = (int*)gp + 1;
   printf("item pointed to by gp is now %d\n", *(int*)gp);

   gp = words;        // set the generic poitner to the start of the string array
   printf("\ndata array address is %p\n", gp);  // and print it out - no cast is needed there
   // now, print out the first item of the array
   // - a cast is now nweeded to let the compiler know what sort of thing is being pointed to by the generic pointer
   printf("item poitned to by gp is %s\n", *(char**)gp);
   // the cast tells the compiler what the address type is and so we can do address arithmetic
   gp = (char**)gp + 1;
   printf("item pointed to by gp is now %s\n", *(char**)gp);



  return 0;
}
