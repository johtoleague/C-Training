#include <stdio.h>

/* echo; 2nd ver incrementing the pointer instead of indexed 
array*/

main(int argc, char *argv[])
{
    while (--argc > 0)
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    printf("\n");
    return 0;
}