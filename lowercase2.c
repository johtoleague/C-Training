#include <stdio.h>
#define MAXLINE 1000

int getlines(char line[], int maxline);
void to_lower(const char from[], char to[], int len);

int main() {
    int len;
    char line[MAXLINE];
    char out[MAXLINE];

    while ((len = getlines(line, MAXLINE)) > 0) {
        to_lower(line, out, len);
        printf("%s", out);
    }
    return 0;
}

int getlines(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void to_lower(const char from[], char to[], int len) {
    for (int i = 0; i < len; ++i) {
        char c = from[i];
        to[i] = ((c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c);
    }
}
