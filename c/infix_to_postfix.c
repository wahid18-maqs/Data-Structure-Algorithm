#include <stdio.h>
#include <ctype.h>
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
    } else
        return st[top--];
}

int precedence(char op) 
{
    return op == '/' || op == '*' || op == '%'  ? 1 : 0;
}

void infixToPostfix(char source[], char target[]) 
{
    int i = 0, j = 0;
    char temp;
    strcpy(target, "");

    while (source[i] != '\0') 
    {
        if (source[i] == '(')
            push(source[i++]);
        else if (source[i] == ')') 
        {
            while (top != -1 && st[top] != '(')
                target[j++] = pop();
            if (top == -1) 
            {
                printf("\n INCORRECT EXPRESSION");
                return;
            }
            temp = pop();
            i++;
        } 
        else if (isdigit(source[i]) || isalpha(source[i]))
            target[j++] = source[i++];
        else if (strchr("+-*/%$", source[i]))
         {
            while (top != -1 && st[top] != '(' && precedence(st[top]) >= precedence(source[i]))
                target[j++] = pop();
            push(source[i++]);
        } 
        else 
        {
            printf(" Incorrect Elements in Expression \n");
            return;
        }
    }

    while (top != -1 && st[top] != '(')
        target[j++] = pop();
    target[j] = '\0';
}

int main() 
{
    char infix[MAX], postfix[MAX];
    printf("Enter any infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("The postfix expression is: %s\n", postfix);
    return 0;
}
