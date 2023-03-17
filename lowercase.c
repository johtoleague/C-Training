#include <stdio.h>

int lower(c)
int c;
{
    if (c >= 'A' && c <= 'Z') {
        return(c + 'a' - 'A');
    }
    else {
        return(c);
    }
    
}