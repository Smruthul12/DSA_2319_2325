#include "stack.h"
#include <stdio.h>
void push(Stack *stack, char item) {
    if (is_full(stack))
        printf("Overflow\n");
    else {
        stack->top++;
        stack->data[stack->top] = item;
    }
}

void init(Stack *stack) {
    stack->top = -1; 
}

int is_empty(Stack *stack) {
    return stack->top == -1; 
}

int is_full(Stack *stack) {
    return stack->top == STACK_SIZE - 1; 
}

char pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Underflow\n");
        return -1; 
    } else {
        int item = stack->data[stack->top];
        stack->top--;
        return item;
    }
}
char peek (Stack *stack)
{
  return stack->data[stack->top];
}