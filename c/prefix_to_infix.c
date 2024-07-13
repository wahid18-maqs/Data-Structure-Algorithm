//prefix_to_infix
#include <stdio.h>
#include <string.h>

#define MAX 100

char st[MAX];
int top = -1;

void push(char val) 
{
    if (top == MAX - 1)
        printf("\n STACK OVERFLOW");
    else
        st[++top] = val;
}

char pop() 
{
    if (top == -1) {
        printf("\n STACK UNDERFLOW");
        return -1;
    } 
    else
        return st[top--];
}

void reverseString(char* str) 
{
    int length = strlen(str);
    int i;
    for (i = 0; i < length / 2; i++) 
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int isOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

void prefixToInfix(char source[], char target[]) 
{
    reverseString(source);
    int i = 0, j = 0;
    strcpy(target, "");

    while (source[i] != '\0') {
        if (isdigit(source[i]) || isalpha(source[i])) 
        {
            push(source[i]);
            i++;
        } 
        else if (isOperator(source[i])) 
        {
            char op1 = pop();
            char op2 = pop();
            if (op1 == -1 || op2 == -1) 
            {
                printf(" Incorrect Elements in Expression \n");
                return;
            }
            if (isOperator(op2)) 
            {
                target[j++] = op1;
                target[j++] = source[i];
                target[j++] = op2;
            } 
            else 
            {
                target[j++] = ' ';
                target[j++] = op1;
                target[j++] = source[i];
                target[j++] = op2;
                target[j++] = ' ';
            }
            push(target[j - 1]);
            i++;
        } 
        else 
        {
            printf(" Incorrect Elements in Expression \n");
            return;
        }
    }
    while (top != -1) 
    {
        char op = pop();
        if (isOperator(op)) 
        {
            char op1 = pop();
            if (op1 == -1) 
            {
                printf(" Incorrect Elements in Expression \n");
                return;
            }
            if (isOperator(op1)) {
                target[j++] = op1;
                target[j++] = op;
            } 
            else 
            {
                target[j++] = '(';
                target[j++] = op1;
                target[j++] = op;
                target[j++] = ')';
            }
        } 
        else 
        {
            printf(" Incorrect Elements in Expression \n");
            return;
        }
    }

    target[j] = '\0';
}
int main() 
{
    char prefix[MAX], infix[MAX];
    printf("Enter any prefix expression: ");
    scanf("%s", prefix);
    prefixToInfix(prefix, infix);
    printf("The infix expression is: %s\n", infix);
    return 0;
}
// time complexity is O(n)