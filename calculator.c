#include <stdlib.h>
#include <stdio.h>

int main()
{
    char operator;
    double num1;
    double num2;
    double result;

    printf("\nEnter an operator (+ - * /): ");
    fflush(stdin);
    scanf("%c", &operator);

    printf("\nEnter number 1: ");
    fflush(stdin);
    scanf("%lf", &num1);
    printf("\nEnter number 2: ");
    fflush(stdin);
    scanf("%lf", &num2);
    switch (operator)
    {
        case '+':
            result = num1 + num2;
            printf("\nResult: %lf\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("\nResult: %lf\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("\nResult: %lf\n", result);
            break;
        case '/':
            result = num1 / num2;
            printf("\nResult: %lf\n", result);
            break;
        default:
            printf("\nOperator %c is not valid\n", operator);
    }
}