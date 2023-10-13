#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "infixtopostfix.h"

// Determine the precedence of oprs
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// Converting infix to postfix
void infixToPostfix(const char* infix, char* postfix) {
    Stack stack;
    init(&stack);
    int len = strlen(infix);
    int j = 0;

    for (int i = 0; i < len; i++) {
        char token = infix[i];

        if (token >= '0' && token <= '9') {
            postfix[j++] = token; 
        } else if (token == '(') {
            push(&stack, token);
        } else if (token == ')') {
            while (!is_empty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); 
        } else {
            while (!is_empty(&stack) && precedence(peek(&stack)) >= precedence(token)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        }
    }

    // Pop any remaining oprs from the stack
    while (!is_empty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';

   
}