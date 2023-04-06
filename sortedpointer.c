#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/*sort input lines*/

main()
{
    int nlines; /* number of input lines read*/

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {

    }
}