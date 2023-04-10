#include <stdio.h>

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0; /* lower limit of temp*/
    upper = 300; /* upper limit of temp*/
    step = 20; /*each step of change*/
    
    fahr = lower;
    printf("Fahrenheit\t  Celsius\n");
    while (fahr <= upper)
    {
        celsius = 5 * (fahr-32) / 9;
        printf("%8.0f \t %9.1f\n", fahr, celsius);
        fahr = fahr + step;
    }



}