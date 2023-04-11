#include <stdio.h>
#include <stdbool.h>

void function(int x)
{
    printf("x: %d\n", x);
}

double add(double x, double y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}

int (*select_operation())(int, int)
{
    int option = 0;
    printf("Select An Operation\n");
    printf("1) Subtract\n");
    printf("2) Multiply\n");
    printf("3) Divide\n");
    printf("Enter: ");
    scanf("%d", &option);

    if (option ==1) return subtract;
    else if (option ==2) return multiply;
    else if (option ==3) return divide;
    else return NULL;



}
bool freeze_c(int temp)
{
    if (temp <= 0) return true;
    else return false;
}

bool freeze_f(int temp)
{
    if (temp <= 32) return true;
    else return false;
}
void is_freezing( bool (*freeze_check)(int))/*considred by a call back fnc*/
{
    int temp = 0;
    printf("Enter Temperature: ");
    scanf("%d", &temp);
    
    if(freeze_check(temp)){
            printf("It's freezing!\n");
    } else
        printf("It's not a freeze!\n");
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
    printf("%f\n",((add_pointer)(8.0, 8.0))); 


    int (*array_pointer[])(int, int) = {subtract, multiply, divide};

    int product = (*array_pointer[1])(16,15);

    printf("product: %d\n", product);

    int (*operation)(int, int) = select_operation(); /*this declares
    the operation pointer to the select operator function that 
    connects us to multiple arrays, but it's true that it will return a 
    integer and all the functions all take in int for both arguments
    this is just another way we return a pointer to a function*/
    printf("answer %d\n", operation(20,5));

    printf("\nCelcius...\n");
    printf("\n then Fahrenheit...\n");
    is_freezing(freeze_c);
    is_freezing(freeze_f);

    return 0;

}