#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 4

int a[COUNT];
float b[COUNT];
double c[COUNT];
long long int d[COUNT];
short int e[COUNT];
long int f[COUNT];

int main(int argc, char const *argv[]) {
  int* pa;
  float* pb;
  double* pc;
  long long int* pd;
  short int* pe;
  long int* pf;

  //print the sizes of our array types
  printf("sizes are: int %d; float %d; double %d; long long int %d; short int %d; long int %d\n",
              sizeof(int), sizeof(float), sizeof(double), sizeof(long long int), sizeof(short int), sizeof(long int));

  pa = a;
  pb = b;
  pc = c;
  pd = d;
  pe = e;
  pf = f;
  for(int i = 0; i < COUNT;  i++)
  {
    a[i] = i;
    b[i] = (float)i;
    c[i] = (double)i;
    d[i] = i;
    e[i] = i;
    f[i] = i;
  }

  pa += 1;
  pb += 1;
  pc += 1;
  pd += 1;
  pe += 1;
  pf += 1;
  printf("address of a is %p [%d]; value of pa is %p [%d]; value pointed to by pa is %d\n", a, a, pa, pa, *pa);
  printf("address of b is %p [%d]; value of pb is %p [%d]; value pointed to by pb is %f\n", b, b, pb, pb, *pb);
  printf("address of c is %p [%d]; value of pc is %p [%d]; value pointed to by pc is %f\n", c, c, pc, pc, *pc);
  printf("address of d is %p [%d]; value of pd is %p [%d]; value pointed to by pd is %lld\n", d, d, pd, pd, *pd);
  printf("address of e is %p [%d]; value of pe is %p [%d]; value pointed to by pe is %hd\n", e, e, pe, pe, *pe);
  printf("address of f is %p [%d]; value of pf is %p [%d]; value pointed to by pf is %ld\n", f, f, pf, pf, *pf);
  return 0;
}
