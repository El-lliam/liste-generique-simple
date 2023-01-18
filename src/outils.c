#define NB_CHAR 5
#include <stdlib.h> // librairie standard
#include <stdio.h> // librairie input/output
#include <stdbool.h> // librairie du type booléen
#include <assert.h> 
void printInteger(int *i)
{
  printf("La valeur est entiere et  vaut : %d\n", (*i));
}
void rmInteger(int *i)
{
  free(i);
}
bool intcmp(int *i, int *j)
{
  return (*i) < (*j);
}
void printDouble(double *d)
{
  printf("La valeur est reelle et vaut : %lf\n", (*d));
}
void rmDouble(double *d)
{
  free(d);
}
bool reelcmp(double *u, double *v)
{
  return (*u) < (*v);
}