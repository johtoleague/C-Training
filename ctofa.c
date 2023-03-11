#include <stdio.h>

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; /* lower limit of temp*/
    upper = 150; /* upper limit of temp*/
    step = 25; /*each step of change*/

    celsius = 0;
    printf("Celcius\t  Fahrenheit\n");
     while (celsius <= upper)
     {
        fahr = (celsius * 1.8) + 32;

        printf("%8.0f \t %9.1f\n", celsius , fahr);
        celsius = celsius + step;
    }
}