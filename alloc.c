#include <stdio.h>

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) /* size of available space*/
{
    if (allocbuf + ALLOCSIZE - allocp >= n ){
        //itfits
        allocp += n;
        return allocp - n; /* old p*/
    } else /* not enough room*/
        return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
    if (p>= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}