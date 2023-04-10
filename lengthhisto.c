#include <stdio.h>

/* histogram of word length */

int main()
{
    int c, i, nwhite, nother, count;
    int wlen[28];

    nwhite = nother = count = 0;
    for (i = 0; i < 28; ++i)
    {
        wlen[i] = 0; // make all numbers zero
    }

    while ((c = getchar()) != EOF) /* get all inputs */
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            ++count; // count word length
        }
        else if (c == ' ' || c == '\n' || c == '\t')
        {
            if (count > 0 && count < 28) // check word length
            {
                ++wlen[count-1]; // update word length count
            }
            count = 0; // reset count for next word
            ++nwhite;
        }
        else
        {
            ++nother;
        }
    }

    printf("wlen =");
    for (i = 0; i < 28; ++i)
    {
        printf(" %d", wlen[i]);
    }
    printf("\n");
}
