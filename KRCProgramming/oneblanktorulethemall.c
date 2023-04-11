#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF) 
    {
        if (c != ' ')
            putchar(c);
        if (c == ' ')
            putchar(' ');
            while((c = getchar()) == ' ') /* look for following blanks */
            ; /* do nothing*/


    }
}        
