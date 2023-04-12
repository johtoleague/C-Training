#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000
char* itoas(int n);
int atoi();
int main()
{
    int n;
    char h[MAX] = {0}; /* initialize h to all zeroes */
    n = atoi(gets(h)); /* read input from standard input and convert to integer */
    printf("%s\n", itoas(n));
    return 0;
}
char* itoas(int n)
{
    static char s[MAX];
    static int i = 0;
    if (n < 0){
        s[i++] = '-';
        n = -n; /* make it positive */
    }   
    if (n / 10)
        itoas(n / 10);
    s[i++] = (n % 10 + '0');
    if (i == 1 || n == 0)
        s[i] = '\0'; /* add null terminator at the end */
    return s;
}