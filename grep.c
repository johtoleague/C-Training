#include <stdio.h>
#define MAXLINE 1000

int getlines(char line[], int max);
int strindex(char source[], char searchfor[]);
int strinrdex(char test[], char p[], int len);

char pattern[] = "ould";

main()
{
    char line[MAXLINE];
    int found = 0;
    int len, h;


    while ((len =getlines(line, MAXLINE)) > 0)
    {
        if ((h = strinrdex(line, pattern, len)) >= 0)
        {
            printf("%d in main \n",h);
            found++;
        }
    
    }
    return found;
}

int getlines(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar())!= EOF && c!= '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++)
    {
        for ( j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] =='\0')
            return i;

    }
    return -1;
}

int strinrdex(char s[], char p[], int len)
{
    int i, j, k, l;

    for (l = 0; p[l] != '\0'; l++)
        ;

    for (i = len - 1; i >= 0 && i != '\0'; i--)
    {
        for (j = i, k = l - 1; j >= 0 && s[j] == p[k] && p[k] != '\0'; j--, k--){
            //printf("%c %d\n", p[k], k );
            if (k == 0 && s[j] == p[0])
        {
            printf("%c %d\n", s[j], k );
            return (i - l + 1);
        }
        }
        
        /*//printf("%d\n", i);
        if (k == 0 && s[j] == p[0])
        {
            printf("%c %d\n", s[j], k );
            return (i - l + 1);
        }
        */
    }
    return -1;
}