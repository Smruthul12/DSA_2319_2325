#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 100 

typedef struct {
    char data[STACK_SIZE];
    int top;
} Stack;

// Function prototypes
void push(Stack *stack, char item);
void init(Stack *stack);
int is_empty(Stack *stack);
int is_full(Stack *stack);
char pop(Stack *stack);
char peek (Stack *stack);
#endif 
