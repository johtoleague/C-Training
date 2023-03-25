#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100

int getline(char line[], int max);
double atof(char s[]);

int main()
{
    double sum;
    char line[MAXLINE];

    sum = 0;
    while (getline(line, MAXLINE) > 0) {
        printf("\t%g\n", sum += atof(line));
    }
    return 0;
}

double atof(char s[]) {
    double val, power;
    int i, sign, exp_sign, exponent;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    val = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E') {
        i++;

        exp_sign = (s[i] =='-') ? -1.0 : 1.0;
        if(s[i] == '+' || s[i] == '-')
        i++;

        for (exponent = 0; isdigit(s[i]); i++)
            exponent = 10 * exponent + (s[i] - '0');

        val *= pow(10, exp_sign * exponent);
    }

}

int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = '\0';
        return i;
    } else {
        s[i] = '\0';
        return i;
    }
}
