#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;
int getint(int *pn);
int getch(void);
void ungetch(int);

/*getint get next integer from input into *pn */
int main()
{
    int *b, n;
    b = &n;
    getint(b);
    printf("getint to integer > %d\n", *b);
}
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch())) //skip spaces
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); //not a number go back 1
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c =='+' || c == '-')
        c = getch();//get next character if + or - encountered
        if (!isdigit(c)){
            ungetch(c); //not a number go back
            return 0;
        } 
    for (*pn = 0; isdigit(c); c = getch()) //get next character as long as it's a digit 0-9, read from left to right until it's no longer a digit
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
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