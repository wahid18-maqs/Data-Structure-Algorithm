//infix_to_prefix
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
    if (top == -1) 
    {
        printf("\n STACK UNDERFLOW");
        return -1;
    } 
    else
        return st[top--];
}
int precedence(char op) 
{
    return op == '/' || op == '*' || op == '%' ? 1 : 0;
}

void infixToPrefix(char source[], char target[]) 
{
    int i = 0, j = 0;
    char temp;
    strcpy(target, "");

    int len = strlen(source);
    for (i = len - 1; i >= 0; i--) 
    {
        if (source[i] == '(')
            target[j++] = ')';
        else if (source[i] == ')')
            target[j++] = '(';
        else
            target[j++] = source[i];
    }
    target[j] = '\0';
    j = 0;
    for (i = 0; target[i] != '\0'; i++) {
        if (isdigit(target[i]) || isalpha(target[i]))
            target[j++] = target[i];
        else if (strchr("+-*/%", target[i])) 
        {
            while (top != -1 && st[top] != '(' && precedence(st[top]) > precedence(target[i]))
                target[j++] = pop();
            push(target[i]);
        } 
        else if (target[i] == ')') 
        {
            push(target[i]);
        } else if (target[i] == '(') 
        {
            while (st[top] != ')')
                target[j++] = pop();
            pop();
        }
    }
    while (top != -1)
        target[j++] = pop();
    target[j] = '\0';
    strrev(target);
}
int main() 
{
    char infix[MAX], prefix[MAX];
    printf("Enter any infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("The prefix expression is : %s\n", prefix);
    return 0;
}

//time complexity is O(n)