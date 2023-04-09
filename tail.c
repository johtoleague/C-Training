#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024
int getline(char s[], int lim);

/*  build tail, supposed to print that last 10 line by default
unless -n is specified, then we'll need to read in the number,
and print out those many lines*/
int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int lineno = 10;
    int c;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = (*++argv)[0])) {
             /*this portion will be the second character*/
            switch(c) {
            case 'n':
                lineno = atoi(*++argv);
                break;
            default:
                printf(" using default 10");
                break;
                }
        }
    }
    if (argc != 0) {
        printf("usage: find -x -n pattern\n"); 
        return 0;
    }
    while (getline(line, MAXLINE) > 0) {
        char *liner[MAXLINE];



}

int getline(char s[], int lim)
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
