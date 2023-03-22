#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]) 
{
   
    int i, j;
    char c;
    i = j = 0;
    while ((c = s1[i++]) != '\0'){
        printf("%c", c);
        if (s1[i] == '-' && s1[i + 1] >= c)
        {
            printf("%c", s1[i]);
            printf(" this is > %c < inside if statment" , c);
            printf("%i inside if", i);
            i++;
            while (c <= s1[i]) {
                s2[j++] = c++;
            }
        }
        else
        {
            s2[j++] = c;
        }

    }
    s2[j] = '\0';
}

int main()
{
    char b[] = "a-h";
    char r[100];

    expand(b, r);

   // printf("%s",r);





}