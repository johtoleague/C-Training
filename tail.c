#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024
int getline(char s[], int lim);
void free_lines(char **lines, int lineno);

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
    char **lines = malloc(lineno * sizeof(char *));
    if (!lines) {
        perror("malloc");
        return 1;
    }

    int nread = 0;
    int current = 0;
    while (get_line(&lines[current]) != EOF) {
        current = (current + 1) % lineno;
        nread++;
        if (nread > lineno) {
            free(lines[current]);
        }
    }

    int start_line = nread <= lineno ? 0 : current;
    for (int i = start_line; i < start_line + lineno && i < nread; i++) {
        printf("%s\n", lines[i % lineno]);
    }

    free_lines(lines, lineno);

    return 0;



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

void free_lines(char **lines, int lineno) {
    for (int i = 0; i < lineno; i++) {
        free(lines[i]);
    }
    free(lines);
}

