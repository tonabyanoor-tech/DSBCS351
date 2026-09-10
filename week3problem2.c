#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int priority(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

int main() {
    char infix[50], prefix[50], temp[50];
    int i, j = 0, n;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    n = strlen(infix);

    /* Reverse expression */
    for (i = 0; i < n; i++)
        temp[i] = infix[n - i - 1];
    temp[n] = '\0';

    /* Swap brackets */
    for (i = 0; i < n; i++) {
        if (temp[i] == '(') temp[i] = ')';
        else if (temp[i] == ')') temp[i] = '(';
    }

    for (i = 0; i < n; i++) {
        char x = temp[i];

        if (isalnum(x))
            prefix[j++] = x;

        else if (x == '(')
            push(x);

        else if (x == ')') {
            while (stack[top] != '(')
                prefix[j++] = pop();
            pop();
        }

        else {
            while (top != -1 && priority(stack[top]) > priority(x))
                prefix[j++] = pop();
            push(x);
        }
    }

    while (top != -1)
        prefix[j++] = pop();

    prefix[j] = '\0';

    /* Reverse postfix to get prefix */
    for (i = 0; i < j / 2; i++) {
        char t = prefix[i];
        prefix[i] = prefix[j-i-1];
        prefix[j-i-1] = t;
    }

    printf("Prefix: %s", prefix);

    return 0;
}