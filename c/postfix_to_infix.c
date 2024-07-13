//postfix_to_infix
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char st[MAX];
int top = -1;

void push(char val) {
    if (top == MAX - 1) {
        printf("\n STACK OVERFLOW");
        exit(1); 
    } else
        st[++top] = val;
}

char pop() 
{
    if (top == -1) 
    {
        printf("\n STACK UNDERFLOW");
        exit(1); 
    } 
    else
        return st[top--];
}

int isOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void postfixToInfix(char source[], char target[]) {
    int len = strlen(source);
    int i;

    for (i = 0; i < len; i++) {
        if (isalnum(source[i])) 
        {
            push(source[i]);
        } 
        else if (isOperator(source[i])) 
        {
            char op2 = pop();
            char op1 = pop();
            char temp[MAX];
            temp[0] = ' ';
            temp[1] = op1;
            temp[2] = source[i];
            temp[3] = op2;
            temp[4] = ' ';
            temp[5] = '\0';
            strcat(target, temp);
            push(temp[0]);
        } 
        else 
        {
            printf(" Incorrect Elements in Expression \n");
            exit(1); 
        }
    }
}
int main() 
{
    char postfix[MAX], infix[MAX] = "";
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    postfixToInfix(postfix, infix);
    printf("The infix expression is : %s\n", infix);
    return 0;
}

//time complexity is O(n)
