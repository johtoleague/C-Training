#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned y_mask = ~(~0 << n);     // Create a mask of  00000111
    unsigned y_bits = y & y_mask;      // Get the rightmost 'n' bits of 'y'.
    unsigned x_mask = ~(y_mask << (p + 1 - n));       // Adding one for 0 index postion and machine countingCreate a mask to clear 'n' bits of 'x' at position 'p'.
    unsigned x_cleared = x & x_mask;                  // Clear 'n' bits of 'x' at position 'p'.
    return x_cleared | (y_bits << (p + 1 - n));       // Set the rightmost 'n' bits of 'y' at position 'p' in 'x'.
}

int main() {
    unsigned x = 0b10101010;
    int p = 5;
    int n = 3;
    unsigned y = 0b11001100;

    unsigned result = setbits(x, p, n, y);

    printf("x = %u\n", x);
    printf("y = %u\n", y);
    printf("position of the rightmost bit to be set = %d\n", p);
    printf("number of bits to be set = %d\n", n);
    printf("result = %u\n", result);

    return 0;
}
