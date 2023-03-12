#include <stdio.h>

/* count digits, white space, others */
int main() 
{
    int c, i , nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i <10; ++i)
    {
        ndigit[i] = 0; //make all numbers are zero
    }
    while ((c = getchar()) != EOF) /*get all inputs*/
    {
        if ( c >= '0' && c <= '9' ) //if digits are betwen 0-9
        {
            
            ++ndigit[c -'0']; /*increase number of occurences of the index, and -0 is sort of a conversion*/
            printf(" c is %d\n", c);
            printf(" c - 1 = %d \n", c-'1');

        }
        else if (c == ' ' || c == '\n' || c == '\t')
        {
            ++nwhite;
        }
        else
        {
            ++nother;
        }
    }
    printf("digits =");
    for (i = 0; i < 10; ++i)
    {
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n", nwhite, nother);
}