#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXTOKEN 100

enum TokenType { NAME, PARENS, BRACKETS, QUALIFIER, COMMA };

int gettoken(void);
void dcl(void);
void dirdcl(void);
void process_func_args(void);

int tokentype;
char token[MAXTOKEN];
char out[1000];
char datatype[MAXTOKEN];
char qualifiers[MAXTOKEN];

int main() {
    while (gettoken() != EOF) {
        qualifiers[0] = '\0';
        while (tokentype == QUALIFIER) {
            strcat(qualifiers, token);
            strcat(qualifiers, " ");
            gettoken();
        }
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if (tokentype != '\n') {
            printf("syntax error\n");
            while (gettoken() != '\n' && gettoken() != EOF);  // Skip to the next line or end of input.
        }
        printf("%s: %s%s%s\n", token, qualifiers, out, datatype);
    }
    return 0;
}

void dcl(void) {
    int ns;
    for (ns = 0; gettoken() == '*'; ++ns);
    dirdcl();
    while (ns-- > 0) {
        strcat(out, " pointer to");
    }
}

void dirdcl(void) {
    int type;
    if (tokentype == '(') {
        dcl();
        if (tokentype != ')') {
            printf("error: missing )\n");
        }
    } else if (tokentype == NAME) {
        strcpy(token, token);
    } else {
        printf("error: expected name or (dcl)\n");
    }
    while ((type = gettoken()) == PARENS || type == BRACKETS || type == '(') {
        if (type == PARENS) {
            strcat(out, " function returning");
        } else if (type == BRACKETS) {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        } else {
            strcat(out, " function(");
            process_func_args();
            strcat(out, ") returning");
        }
    }
}

void process_func_args(void) {
    do {
        char temp[MAXTOKEN];
        temp[0] = '\0';

        gettoken();
        if (tokentype == QUALIFIER) {
            strcat(temp, token);
            strcat(temp, " ");
            gettoken();
        }
        strcat(temp, token);
        strcat(temp, " ");
        gettoken();

        if (tokentype == ',') {
            strcat(temp, ",");
            strcat(temp, " ");
        }

        strcat(out, temp);
    } while (tokentype == ',');
}

int getch(void);
void ungetch(int);

int gettoken(void) {
    int c;
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t');

    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
        } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']';);
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()) || c == '_';) {
            *p++ = c;
        }
        *p = '\0';
        ungetch(c);
        if (strcmp(token, "const") == 0 || strcmp(token, "volatile") == 0) {
            return tokentype = QUALIFIER;
        } else {
            return tokentype = NAME;
        }
    } else if (c == ',') {
        return tokentype = COMMA;
    } else {
        return tokentype = c;
    }
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

