
#include "stdio.h"

#define MAXINLINE 1000 /* maximum input line size */

int get_lines(char line[], int maxline);
void reverse(char str[]);

/* print longest input line */
main() {

 char line[MAXINLINE]; /* current input line */

 while ((get_lines(line, MAXINLINE)) > 0) {

  reverse(line);
  printf("%s", line);

 }

}

/* getline: read a line into s, return length */
int get_lines(char str[], int line) {
 int c, i, j;

 for (i = 0, j = 0; (c = getchar()) != EOF && c != 'n'; ++i) {
  if (i < line - 1) {
   str[j++] = c;
  }
 }
 if (c == 'n') {
  if (i <= line - 1) {
   str[j++] = c;
  }
  ++i;
 }
 str[j] = '';
 return i;
}

/*reverse the string str*/
void reverse(char str[]) {
 int i, j;
 char temp;
 i = 0;
 while (str[i] !=' ')
  ++i;
 --i;
 if (str[i] != 'n')

  --i;
 j = 0;
 while (j < i) {
  temp = str[j];
  str[j] = str[i];
  str[i] = temp;
  --i;
  ++j;
 }
}
