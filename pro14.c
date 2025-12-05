#include <stdio.h>

int main() {
    int a = 5;  // binary: 0101
    int b = 3;  // binary: 0011

    printf("Before swapping: a = %d, b = %d\n", a, b);

    // XOR swap algorithm
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}
