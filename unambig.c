#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF) 
    {

        if (c == '\b'){
            putchar('\\');
            putchar('b');
        }
        if (c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        if (c == '\\')
        {
            putchar('\\');
            putchar('\\');
        }
        else {
            putchar(c); 
        }
    }
    return 0;
}        
