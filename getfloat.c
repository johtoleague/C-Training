#include <stdio.h>

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define BUFSIZE 100
/*need to fix this, maybe not*/
char buf[BUFSIZE];
int bufp = 0;
int getfloat(float *pn);
int getch(void);
void ungetch(int);

/*getint get next integer from input into *pn */
int main()
{
    int *b, n;
    b = &n;
    getfloat(b);
    printf("getint to integer > %d\n", *b);
}
int getfloat(float *pn)
{
    int c, sign;
    float power;

    while (isspace(c = getch())) //skip spaces
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); //not a number go back 1
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');
    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }
    if (c != EOF)
        ungetch(c);
    return c;
}



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