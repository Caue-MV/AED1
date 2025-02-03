#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 300

int prec(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

void convert(char *infix, char *postfix)
{
    char stack[MAX_SIZE];
    int top = -1;
    int j = 0;
    for (int i = 0; infix[i]; i++)
    {
        char c = infix[i];

        if (isalnum(c))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            stack[++top] = c;
        }
        else if (c == ')')
        {
            while (top > -1 && stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            if (top > -1 && stack[top] == '(')
            {
                top--;
            }
        }
        else if (strchr("+-*/^", c))
        {
            while (top > -1 && prec(stack[top]) >= prec(c))
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while (top > -1)
    {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}

int main()
{
    int N;
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++)
    {
        fgets(infix, sizeof(infix), stdin);
        infix[strcspn(infix, "\n")] = 0;
        convert(infix, postfix);
        printf("%s\n", postfix);
    }
    return 0;
}