#include <stdio.h>

void squeeze(char s[], char c[])
{
    int i, j, d;
    int found;
    for (i = j = 0; s[i] != '\0'; i++) {
        found = 0;
        for (d = 0; c[d] != '\0'; d++) {
            if (s[i] == c[d]) {
                found = 1;
                break;
            }
        }
        
        if (!found) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}