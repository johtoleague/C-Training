#include <stdio.h>

int strleng(char *s);

int strend(char *s, char *t)
{
    int slen = strleng(s);
    int tlen = strleng(t);
    int diff = slen - tlen;
    if (diff < 0) {
        return 0;
    } 
    while ((*s + diff) == *t) {
        if (*t == '\0') {
            return 1;
        }
        s++;
        t++;
    }
    return 0;
}

/* strlen using a pointer and returns the length of the string */
int strleng(char *s)
{
    char *p = s;
    while (*p != '\0') {
        p++; // push the index of p forward from *s, which will point to zero
    }
    return p - s; /* let's say p will be moved forward 4 times 
                    and it will subtract 0, which is now pointing at the
                    first character aka the address of the string you get
                    the length */
}
