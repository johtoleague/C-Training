#include <ctype.h>
#include <stdio.h>
#include <string.h>

int getch(void);
void ungetch(int);

/*getint get next integer from input into *pn */

int getint(int *pn)
{
    int c, sign;

    while (issspace(c = getch())) //skip spaces
        ;
    if (!digit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); //not a number go back 1
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c =='+' || c == '-')
        c == getch(); //get next character
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}