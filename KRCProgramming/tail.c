#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024

int get_line(char **s);
void free_lines(char **lines, int lineno);

int main(int argc, char *argv[]) {
    int lineno = 10;
    int c;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = (*++argv)[0])) {
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
        printf("usage: tail [-n number]\n");
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

int get_line(char **s) {
    int c, i = 0, size = MAXLINE;
    char *buf = malloc(size);

    if (!buf) {
        perror("malloc");
        return EOF;
    }

    while ((c = getchar()) != EOF && c != '\n') {
        buf[i++] = c;
        if (i == size) {
            size *= 2;
            buf = realloc(buf, size);
            if (!buf) {
                perror("realloc");
                return EOF;
            }
        }
    }

    if (c == EOF && i == 0) {
        free(buf);
        return EOF;
    }

    buf[i] = '\0';
    *s = buf;

    return i;
}

void free_lines(char **lines, int lineno) {
    for (int i = 0; i < lineno; i++) {
        if (lines[i]) {
            free(lines[i]);
        }
    }
    free(lines);
}
