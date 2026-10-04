#include <stdio.h>

void inplaceSwap (
    int* x,
    int* y
) {
    *y = *x ^ *y; // y <- x^y
    *x = *x ^ *y; // x <- x^(y) = x^(x^y) = (x^x)^y = 0^y = y
    *y = *x ^ *y; // y <- x^y = (x^(x^y))^(x^y) = x
}

void main () {
    int a = 2025;
    int b = 211;
    printf("BEFORE INPLACE SWAP a = %d\n", a);
    printf("BEFORE INPLACE SWAP b = %d\n", b);
    inplaceSwap ( &a, &b );
    printf("AFTER INPLACE SWAP a = %d\n", a);
    printf("AFTER INPLACE SWAP b = %d\n", b);
}
