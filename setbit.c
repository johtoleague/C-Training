#include <stdio.h>

unsigned setbits(unsigned x, int p, int n){
    return ( x >> (p-n)) & ~(~0 << n); 
}


int main() {
    unsigned x = 0b10101010;
    int p = 5;
    int n = 3;
    unsigned y = 0b10101111;

    unsigned extracted = setbits(x, p, n);
    unsigned y_cleared = y & (~0 << n);
    unsigned result = y_cleared | extracted;


    printf("input = %u\n", x);
    printf("position of the rightmost bit to be extracted = %d\n", p);
    printf("number of bits to be extracted = %d\n", n);
    printf("result = %u\n", result);

    return 0;
}