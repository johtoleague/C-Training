#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

int main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
        {
            ++nl;
        }

        // If current character is a whitespace character
        if (c == ' ' || c == '\t' || c == '\n')
        {
            // If we were inside a word previously, we have reached the end of a word
            if (state == IN)
            {
                state = OUT;
                ++nw; // Increment word count
                putchar('\n');
            }
        }
        // If current character is not a whitespace character
        else
        {
            // If we were outside a word previously, we have entered a new word
            if (state == OUT)
            {
                state = IN;
            }
            putchar(c);
        }
    }

    printf("Line Count = %d \nChar Count = %d \nWord Count = %d\n", nl, nc, nw);
}
