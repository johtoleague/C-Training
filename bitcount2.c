#include <stdio.h>

int bitcount(unsigned x) {
    int count = 0;

    while (x != 0) {
        x &= (x - 1);
        count++;
    }

    return count;

    /*this only works to count because how binary representation
    of code complement teach other, and it's a very fast way to count how many bits exist in the*/