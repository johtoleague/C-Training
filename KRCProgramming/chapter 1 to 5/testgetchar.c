#include <stdio.h>

main()
{
    printf("%d", EOF);
    printf("%d", getchar() != EOF);
}