#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';
}

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}


void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char c;

    while ((c = infix[i]) != '\0') {
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();
            pop(); // Remove '('
        } else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
        i++;
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int main() {
    char infix[MAX];
    char postfix[MAX];
    printf("Enter an Expression: ");
    scanf("%s",infix);

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    return 0;
}
