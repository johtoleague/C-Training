#include <stdio.h>
#define MAXLINE 1000

int getlines(char line[], int maxline);
void reverse(char to[], char from[], int len);

int main()
{
	int len;
	int max;
	char line [MAXLINE];
	char out[MAXLINE];
	
	while((len = getlines(line, MAXLINE)) > 0)
		{
			reverse(out, line, len);
			printf("%s", out);
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

void reverse(char to[], char from[], int len)
{
	int i;
	int j;
	
	for(i = len -1, j=0; i< len && i>=0 && from[i] !='\0'; --i, ++j)
	{
		to[j] = from[i];
	}
	to[len] = '\0'
}