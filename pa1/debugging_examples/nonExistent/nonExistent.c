#include <stdlib.h>
#include <stdio.h>

int main () {

  int **x = malloc(sizeof(int*));

  printf("x = %p\n", x);
  fflush(stdout);

  *x = malloc(sizeof(int*));

  **x = 8;

  printf("**x = %d\n", **x);
  fflush(stdout);
  
  free(*x);
  free(x);


}
