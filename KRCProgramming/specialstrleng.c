#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
int strleng(char *s);


int getlines(char line[], int maxline);


int main()
{
	int len;
	int max;
	char line [MAXLINE];
	char out[MAXLINE];
	
	while((getlines(line, MAXLINE)) > 0)
		{
			len = strlen(line);
			printf("%d", len);
		}
	return 0;
}

int getlines(char s[], int lim)
{
	int c,i;
	
	for(i=0; i<lim-1 &&(c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = '\0';
		return i;
	}
}

int strleng(char *s)
{
    int n;

    for (n = 0; *s != '\0'; s++) {
        n++; }

    return n;
       
}