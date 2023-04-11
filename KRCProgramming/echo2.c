#include <stdio.h>

/* echo; 2nd ver incrementing the pointer instead of indexed 
array*/

main(int argc, char *argv[])
{
    while (--argc > 0)
        printf("%s%s", *++argv, (argc > 1) ? " " : ""); 
        /* increase the derefenced  argv pointer to the 
        next argv array, so every time we increase we move the 
        to next array the pointer points to, which will be incremeanting
        to the next word, this make sense because we're moving whole argv 
        pointers not indexed locations*/
    printf("\n");
    return 0;
}