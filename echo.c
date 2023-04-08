#include <stdio.h>

/* echo command -line aruguemtnsl 1st ver*/
main(int argc, char *argv);
{
    int i;

    for (i = 1; i < argc; i++) {
        printf("%s%s", argv[i], (i < argc-1) ? " " : "");
    }/* print argv[i], which will be the string the pointer points to
    and then print the space if the argc is less than the 
    last count of the string, 
    the reason why we don't need to dereference the pointer argv[i]
    is because printf() expects an address pointer, not the value*/
    printf("\n");
    return 0;
} 