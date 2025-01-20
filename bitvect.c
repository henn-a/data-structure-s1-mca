#include <stdio.h>

int main() {
    // Assuming a simple set of characters: A, B, C, D
    int char_set = 0;

    // Set the bits for A and C
    char_set |= (1 << 0); // Set bit for A
    char_set |= (1 << 2); // Set bit for C

    // Check if B is in the set
    if (char_set & (1 << 1)) {
        printf("0\n");
    } else {
        printf("1\n");
    }

    return 0;
}
