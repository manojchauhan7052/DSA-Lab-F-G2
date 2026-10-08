#include <stdio.h>
#include <string.h>
#include<ctype.h>


char stack[100];
int top = -1;

void push(char x)
{
    top++;
    stack[top] = x;
}

char pop()
{
    return stack[top--];
}

int priority(char x)
{
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    return 0;
}

void main()
{
    char infix[100], prefix[100], temp[100];
    int i, j = 0, len;
    char x;

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    len = strlen(infix);

    /* Reverse infix */
    for (i = 0; i < len; i++)
        temp[i] = infix[len - i - 1];

    temp[len] = '\0';

    /* Change brackets */
    for (i = 0; i < len; i++)
    {
        if (temp[i] == '(')
            temp[i] = ')';
        else if (temp[i] == ')')
            temp[i] = '(';
    }

    /* Convert to postfix */
    for (i = 0; i < len; i++)
    {
        /* Check for operand (A-Z, a-z, 0-9) */
        if ((temp[i] >= 'A' && temp[i] <= 'Z') ||
            (temp[i] >= 'a' && temp[i] <= 'z') ||
            (temp[i] >= '0' && temp[i] <= '9'))
        {
            prefix[j] = temp[i];
            j++;
        }
        else if (temp[i] == '(')
        {
            push(temp[i]);
        }
        else if (temp[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                prefix[j] = pop();
                j++;
            }
            pop();
        }
        else
        {
            while (top != -1 &&
                   priority(stack[top]) > priority(temp[i]))
            {
                prefix[j] = pop();
                j++;
            }

            push(temp[i]);
        }
    }

    while (top != -1)
    {
        prefix[j] = pop();
        j++;
    }

    prefix[j] = '\0';

    /* Reverse to get prefix */
    for (i = 0; i < j / 2; i++)
    {
        x = prefix[i];
        prefix[i] = prefix[j - i - 1];
        prefix[j - i - 1] = x;
    }

    printf("Prefix expression: %s", prefix);
}
