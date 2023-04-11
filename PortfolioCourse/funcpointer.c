#include <stdio.h>

void function(int x)
{
    printf("x: %d\n", x);
}

double add(double x, double y)
{
    return x + y;
}

int main()
{
    void (*function_pointer)(int); /*this declares the pointer*/
    function_pointer = &function; /*this associates the pointer to the 
    memory address of function aka &function*/

    (*function_pointer)(4); /*this lets us use this function
    by only referencing the function, we can notice the * to 
    derefrence the pointer to get the instuctions from it*/

    double (*add_pointer)(double, double); /*this is use declaring
    the pointer, with output of double and both arguments expectaion
    of double*/
    add_pointer = add;
    printf("%f",((add_pointer)(8.0, 8.0))); 

    return 0;
}