#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFSIZE 100
#define MAXOP 100 //max size of operand or operator
#define NUMBER '0'  //signal that a number was found
#define MAXVAL 100

int getop(char []);
void push(double);
double pop(void);
int sp =0;
double val[MAXVAL];
void ungetch(int c);

int getch(void);
void swap(void);
void clear(void);
/*reverse polish calculator*/

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

/*push: push f onto value stack*/
void push (double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else printf("error: stack full, can't push %g\n", f);
}

    /*pop: pop and return top value from stack*/
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
        {
            printf("error: stack empty\n");
            return 0.0;
        }
}

/*ge*/
int getop(char s[])
{
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /*not a number*/
    i = 0;
    if (isdigit(c)) /*collect integer*/
        while (isdigit(s[++i] = c = getch()))
            ;
    if ( c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push char back on input*/
{
    if (bufp >= BUFSIZE)
        printf("ungetch: tooo many characters\n");
    else
        buf[bufp++] = c;
}

void swap(void) {
    double top1 = pop();
    double top2 = pop();
    push(top1);
    push(top2);
}

void clear(void) {
    sp = 0;
    bufp = 0;
}

