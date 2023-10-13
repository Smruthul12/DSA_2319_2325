#include "bracketmatching.h"
#include "stack.h"

int isMatchingBrackets(const char* expression) {
    Stack stack;
    init(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];

        switch (c) {
            case '{':
            case '[':
            case '(':
                push(&stack,c);
                break;
            
            case '}':
                if (pop(&stack) != '{') return 0;
                break;
            
            case ']':
                if (pop(&stack) != '[') return 0;
                break;
            
            case ')':
                if (pop(&stack) != '(') return 0;
                break;
        }
    }

    return is_empty(&stack);
}