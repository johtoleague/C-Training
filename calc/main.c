#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100
extern int sp;
extern double val[];

main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) 
    {
        switch (type) 
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) 
                    push(pop() / op2);
                else 
                    printf("Invalid division by zerio \n");
                break;
            case 's':
                swap();
                break;
            case 'p':
                if (sp > 0){
                    printf("Top element of stack is %.8g\n", val[sp-1]);
                }
            case 'c':
                clear();
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    double op1 = pop();
                    if (op1 < 0) {
                        op1 = -op1;
                        op2 = -op2;
                    }
                    int iop1 = (int) op1;
                    int iop2 = (int) op2;
                    push((double) (iop1 % iop2));
                }
                else 
                    printf("Invalid mod by zerio \n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Invalid command \n");
                break;
        }
    }
    return 0;

}

