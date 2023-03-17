#include <stdio.h>
#include <math.h>
#define MAXLINE 1024

int getlines(char line[], int maxline);
void htoi(int to[], char from[], int len);

int i, c;
char s[1024];
char d[1024];

int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char out[MAXLINE];
	
	while((len = getlines(line, MAXLINE)) > 0)
		{
			htoi(out, line, len);
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

void htoi(int* dec, char from[], int len)
{
    int i;
    int value = 0;

    for (i = len - 1; i >= 0 && from[i] != '\0'; --i)
    {
        if (from[i] >= '0' && from[i] <= '9') {
            value += (from[i] - '0') * pow(16, len - i - 1);
        }
        else if (from[i] >= 'a' && from[i] <= 'f') {
            value += (from[i] - 'a' + 10) * pow(16, len - i - 1);
        }
        else if (from[i] >= 'A' && from[i] <= 'F') {
            value += (from[i] - 'A' + 10) * pow(16, len - i - 1);
        }
        else {
            value = 0;
            break;
        }
    }

    *dec = value;
}