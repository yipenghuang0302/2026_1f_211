#include <stdio.h>

int main() {

  long int eighth_perf = 2305843008139952128L;
  float  eighth_perf_as_float  = eighth_perf;
  double eighth_perf_as_double = eighth_perf;

  printf( "eighth_perf = %ld\n", eighth_perf );

  printf( "eighth_perf_as_float = %f\n", eighth_perf_as_float );
  printf(
    "eighth_perf_as_float==eighth_perf: %s\n",
    (long) eighth_perf_as_float==eighth_perf ? "TRUE" : "FALSE"
  );

  printf( "eighth_perf_as_double = %f\n", eighth_perf_as_double );
  printf(
    "eighth_perf_as_double==eighth_perf: %s\n",
    (long) eighth_perf_as_double==eighth_perf ? "TRUE" : "FALSE"
  );

  return 0;
}