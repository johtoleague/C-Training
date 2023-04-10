#include <stdio.h>
#include "calc.h"

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];
extern int bufp;

void push (double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else printf("error: stack full, can't push %g\n", f);
}

    /*pop: pop and return top value from stack*/
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
        {
            printf("error: stack empty\n");
            return 0.0;
        }
}

void swap(void) {
    double top1 = pop();
    double top2 = pop();
    push(top1);
    push(top2);
}

void clear(void) {
    sp = 0;
    bufp = 0;
}

