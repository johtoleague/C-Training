#include <stdio.h>
#define MAXLINE 1024
int main()
{

int i,c;
int lim = MAXLINE;
char s[MAXLINE];

    for (i = 0; (c = getchar()) != EOF; ++i){
        if (c != '\n'){
             if ( i<lim-1){
                s[i] = c;
             }
            else{
                break;
            }
        }
        else{
            break;
        }
    }
    s[i] = '\0';  
    printf("%s\n", s);

}