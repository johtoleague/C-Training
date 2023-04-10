#include <ctype.h>
#include <stdio.h>

/* atoi: convert = to integer; version 2*/

int atoi (char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign =(s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') /*skip sign*/
        i ++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + s[i] - '0';
    return sign * n;
}

int main (){
    char s[100]; 
    int i, c;

    // read in user get char and store it in an array
    for (i =0; (c = getchar()) != EOF && c != '\n' && i < sizeof(s) -1; i ++){
       s[i] = c;
    } 
    s[i] = '\0';

    int result = atoi(s);
    printf("the coonveted int i: %d\n", result);
}

