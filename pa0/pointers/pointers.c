#include <stdio.h>
#include <stdlib.h>

void swap_pass_by_values ( int a, int b );
void swap_pass_by_references ( int* a_pointer, int* b_pointer );
int * modify_array (int size, int param[]);
int factorial(int n);

int global_variable = 0;

int main() {

  printf ("\n\nLESSON 1: WHAT ARE POINTERS?\n");
  unsigned long int number = 500;
  unsigned long int *pointer = &number;
  printf ("number          = %ld\n", number);
  printf ("pointer         = %p\n", pointer);
  printf ("sizeof(pointer) = %ld\n", sizeof(pointer));
  printf ("pointer         = %ld\n", (long int) pointer);
    
  printf ("\n\nLESSON 2: DEREFERENCING POINTERS WITH *\n");
  unsigned long int* second_pointer = &number;
  printf ("dereference pointer   = %ld\n", *pointer);
  *second_pointer = 7000;
  printf ("dereference second_pointer = %ld\n", *second_pointer);
  printf ("number   = %ld\n", number);
  printf ("number   = %lx\n", number);

  printf ("\n\nLESSON 3: THE INTEGER DATATYPE USES FOUR BYTES\n");
  printf ("sizeof(int)     = %ld bytes\n", sizeof(int));
  printf ("sizeof(pointer) = %ld\n", sizeof(pointer));
  printf ("pointer         = %ld\n", (long int) pointer);
  // notice how the + operator has an overloaded functionality for pointers
  printf ("pointer+2       = %ld\n", (long int) (pointer+2));
  
  printf ("\n\nLESSON 4: PRINTING EACH BYTE OF AN INTEGER\n");
  unsigned char* char_pointer = (unsigned char*) pointer;
  printf ("byte at %ld = %d\n", (long int) (char_pointer+0), *(char_pointer+0));
  printf ("byte at %ld = %d\n", (long int) (char_pointer+1), *(char_pointer+1));
  printf ("byte at %ld = %d\n", (long int) (char_pointer+2), *(char_pointer+2));
  printf ("byte at %ld = %d\n", (long int) (char_pointer+3), *(char_pointer+3));
  
  printf ("\n\nLESSON 5: POINTERS ARE JUST VARIABLES THAT LIVE IN MEMORY TOO\n");
  unsigned long int** pointer_to_pointer = &pointer;
  printf ("  pointer_to_pointer = %ld\n", (long int) pointer_to_pointer);
  printf (" *pointer_to_pointer = %ld\n", (long int) *pointer_to_pointer);
  printf ("**pointer_to_pointer = %ld\n", *(*(pointer_to_pointer)));

//   printf ("**pointer = %d\n", * ((unsigned char*) *pointer) );

  printf ("\n\nLESSON 6: ARRAYS\n");
  int array_demo[] = {111,222,333};
  int (*pointer_to_array_demo)[3] = &array_demo;
  printf("%d\n", array_demo[1]);
  printf("array_demo %p\n", array_demo);
  printf("&array_demo %p\n", &array_demo);
  printf("&pointer_to_array_demo %p\n", pointer_to_array_demo);
  printf("sizeof(array_demo) %ld\n", sizeof(array_demo));
  printf("%p\n", array_demo+1);
  printf("%d\n", *(array_demo+1));
  printf("%d\n", (*array_demo)+1);

  exit(0);

  int array_size = 3;

  // void* return_of_malloc = malloc();
  int* array = (int*) malloc(array_size*sizeof(int));
  printf("%p\n", array);

  for (int i=0; i<array_size; i++) {
    printf("array+%d = %p\n", i, (array+i));
  }

  for (int i=0; i<array_size; i++) {
    array[i] = 211 * i;
    printf("array[%d] = %d\n", i, array[i]);
  }

  for (int i=0; i<array_size; i++) {
    printf("*(array+%d) = %d\n", i, *(array+i));
  }

  printf ("\n\nLESSON 6.1: 2D ARRAYS\n");

  int array_demo_2d[2][3] = {{1,2,3},{4,5,6}};

  printf("&array_demo_2d=%p\n",&array_demo_2d);
  printf("sizeof(&array_demo_2d)=%ld\n",sizeof(&array_demo_2d));

  printf("array_demo_2d=%p\n",array_demo_2d);
  printf("sizeof(array_demo_2d)=%ld\n",sizeof(array_demo_2d));

  printf("*array_demo_2d=%p\n",*array_demo_2d);
  printf("sizeof(*array_demo_2d)=%ld\n",sizeof(*array_demo_2d));

  printf("sizeof(*array_demo_2d)=%ld\n",sizeof(*array_demo_2d));
  printf("sizeof(array_demo_2d[0])=%ld\n",sizeof(array_demo_2d[0]));
  printf("**array_demo_2d=%d\n",**array_demo_2d);

  printf("*array_demo_2d=%p\n",*array_demo_2d);
  printf("array_demo_2d[0]=%p\n",array_demo_2d[0]);

  printf("*(array_demo_2d+1)=%p\n",*(array_demo_2d+1));
  printf("array_demo_2d[1]=%p\n",array_demo_2d[1]);

  printf("**array_demo_2d=%d\n",**array_demo_2d);
  printf("array_demo_2d[0][0]=%d\n",array_demo_2d[0][0]);
  
  printf("array_demo_2d[1]=%p\n",array_demo_2d[1]);
  printf("array_demo_2d[1]+1=%p\n",array_demo_2d[1]+1);
  printf("*(array_demo_2d[1]+1)=%d\n",*(array_demo_2d[1]+1));


  array_size = 3;
  int** array_2d = calloc( array_size, sizeof(int*) );
  printf("array_2d=%p\n", array_2d);

  for ( int i=0; i<array_size; i++ ) {
    array_2d[i] = calloc( array_size, sizeof(int) );
    printf("array_2d[%d]=%p\n", i, array_2d[i]);
  }

  for (int i=0; i<array_size; i++) { // iterate over rows
    for (int j=0; j<array_size; j++) { // iterate over columns

      (array_2d[i])[j] = i*1000+j*10;
      // printf("%d ",  array_2d[i][j] ); // valid array notation
      // printf("%d ",  *(array_2d[i]+j) ); // valid pointer arithmetic on the columns followed by dereferencing
      // printf("%d ",  (*(array_2d+i))[j] ); // valid pointer arithmetic on the rows followed by array access
      int i = 1;
      int j = 1;

      printf("%d ",  *(*(array_2d+i)+j) ); // valid pointer arithmetic on both rows and columns followed by dereferencing
    }
    printf("\n");
  }


  for ( int i=0; i<array_size; i++ ) {
    free(array_2d[i]);
  }
  free(array_2d);


  printf ("\n\nLESSON 7: PASSING-BY-VALUE\n");
  int a = 211;
  int b = 422;
  printf ("before swap_pass_by_values:   a = %d\n", a);
  printf ("before swap_pass_by_values:   b = %d\n", b);
  printf ("outside swap_pass_by_values: &a = %p\n", &a);
  printf ("outside swap_pass_by_values: &b = %p\n", &b);
  swap_pass_by_values (a,b);
  printf ("after swap_pass_by_values:    a = %d\n", a);
  printf ("after swap_pass_by_values:    b = %d\n", b);


  printf ("\n\nLESSON 8: PASSING-BY-REFERENCE\n");
  printf ("before swap_pass_by_references:   a = %d\n", a);
  printf ("before swap_pass_by_references:   b = %d\n", b);
  printf ("outside swap_pass_by_references: &a = %ld\n", (long int) &a);
  printf ("outside swap_pass_by_references: &b = %ld\n", (long int) &b);
  swap_pass_by_references ( &a, &b );
  printf ("after swap_pass_by_references:    a = %d\n", a);
  printf ("after swap_pass_by_references:    b = %d\n", b);


  printf ("\n\nLESSON 9: PASSING AN ARRAY LEADS TO PASSING-BY-REFERENCE\n");
  for (int i=0; i<array_size; i++) {
    printf("array[%d]    = %d\n", i, array[i]);
  }
  int* returned_array = modify_array(array_size, array);
  printf("array=%p\n",array);
  printf("returned_array=%p\n",returned_array);
  for (int i=0; i<array_size; i++) {
    printf("returned_array[%d] = %d\n", i, returned_array[i]);
  }
  for (int i=0; i<array_size; i++) {
    printf("array[%d]    = %d\n", i, array[i]);
  }

  free(array);
  return EXIT_SUCCESS;

  printf ("\n\nLESSON 10: C MEMORY MODEL; STACK AND HEAP; RECURSION EXAMPLE\n");
  printf ("global_variable = %d\n", global_variable);
  printf ("Address of global_variable = %p\n", &global_variable);
  int n = 0;
  printf ("%d! = %d\n", n, factorial(n));

  return 0;
}

void swap_pass_by_values ( int a, int b ) {
  printf ("inside swap_pass_by_values:  &a = %p\n", &a);
  printf ("inside swap_pass_by_values:  &b = %p\n", &b);
  int temp = b;
  b = a;
  a = temp;
}

void swap_pass_by_references ( int* a_pointer, int* b_pointer ) {
  printf ("inside swap_pass_by_references:  &a = %ld\n", (long int) a_pointer);
  printf ("inside swap_pass_by_references:  &b = %ld\n", (long int) b_pointer);
  int temp = *b_pointer;
  *b_pointer = *a_pointer;
  *a_pointer = temp;
}

int* modify_array (int size, int param[]) {
  printf("param=%p\n",param);
  for (int i=0; i<size; i++) {
    param[i] = 211 + i;
  }
  return param;
}

int factorial(int n) {
  printf ("In factorial(%d), the parameter was stored at: %p\n", n, &n);
  if (n==1) return 1;
  else {
    int recurse = factorial(n-1);
    printf ("In factorial(%d), the returned value from call to factorial(%d) was stored at: %p\n", n, n-1, &recurse);
    return n*recurse;
  }
}
