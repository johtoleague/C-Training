#include <stdio.h>
#include "calc.h"

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push char back on input*/
{
    if (bufp >= BUFSIZE)
        printf("ungetch: tooo many characters\n");
    else
        buf[bufp++] = c;
}