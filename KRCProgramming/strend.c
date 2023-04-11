#include <stdio.h>

int strleng(char *string);
int strend( char *s, char *t)
{   
    

   while (*(t + (strleng(*t)-1)) == *(s + (strleng(*s)-1))){
        if (t != 0)
            --t;
            --s;
       
        
   }
    
    
}


int strleng(char *s)
{
    char *p = s;

    while (*p != '\0')
        p++; // pushing the index of p forward froim *s, which will point to zero
    return p - s; /* lets say p will be moved forward 4 times 
    and it will subtract 0, which is now pointing at the
     first character aka the address of the string you get
      the length */
}