#include <stdio.h>

int main() {
    // Create a pointer that points to nothing (address 0)
    int *ptr = NULL;

    printf("Going to crash now...\n");

    // Try to write the number 42 into the address 0.
    // The OS forbids this and kills the program.
    *ptr = 42;

    return 0;
}
