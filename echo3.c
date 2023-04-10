
#include <stdio.h>

main(int argc, char *argv)
{
    printf((argc > 1) ? " %s " : "%s", *++argv);
}