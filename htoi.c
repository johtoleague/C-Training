#include <stdio.h>
#include <math.h>
#define MAXLINE 1024

int getlines(char line[], int maxline);
int htoi(char from[], int len);

int main()
{
    int len;
    int out;
    char line[MAXLINE];

    while ((len = getlines(line, MAXLINE)) > 0)
    {
        out = htoi(line, len);
        printf("%d\n", out); // Changed to %d and added newline
    }
    return 0;
}

int getlines(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    s[i] = '\0'; // Moved this line outside of the if statement
    if (c == '\n')
    {
        return i;
    }
    return i; // Added return statement for the case when the loop ends without reaching a newline
}

int htoi(char from[], int len)
{
    int i;
    int value = 0;

    for (i = len - 1; i >= 0 && from[i] != '\0'; --i)
    {
        if (from[i] >= '0' && from[i] <= '9')
        {
            value += (from[i] - '0') * pow(16, len - i - 1);
        }
        else if (from[i] >= 'a' && from[i] <= 'f')
        {
            value += (from[i] - 'a' + 10) * pow(16, len - i - 1);
        }
        else if (from[i] >= 'A' && from[i] <= 'F')
        {
            value += (from[i] - 'A' + 10) * pow(16, len - i - 1);
        }
        else
        {
            value = 0;
            break;
        }
    }

   return value;
}