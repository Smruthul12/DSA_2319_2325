#include <stdio.h>
#include "stack.h"
#include "postfixeval.h"
int main()
{
	
	int n;
	char exp[100];
	Stack mystack;
    printf("\nhello.");
	
	do
	{
		printf("\nMenu:\n0: Exit \n1: Quicksort sort \n2: Merge sort \n3: Stack \n4: Postfix Evaluation \n5: Infix to Postfix \n6: Braket matching: ");
		printf("\nEnter value of n:");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			printf("\nQuicksort sort\n");
			break;

		case 2:
			printf("\nMerge sort\n");
			break;
            
		case 3:
			printf("\nStack\n");
			init(&mystack);
			// push
	        push(&mystack,50);
			push(&mystack, 10);
			push(&mystack, 29);
			push(&mystack, 22);

			//printf("%d",pop(&mystack));
			
			// pop
			while (!is_empty(&mystack))
			{
				int item = pop(&mystack);
				printf("%d\n", item);
			}
			break;

		case 4:
			printf("\nPostfix Evaluation\n");
			//scanf("%[^\n]s",exp);
            //char exp[] = "231*+9-";
			char exp[30] ;
            int result;
			printf("Enter postfix expression");
            scanf("%s",exp);
            result= evaluate(exp);  
            printf("Result= %d\n", result);
			break;
		
		case 5:
			printf("\nInfix to Postfix\n");
			char postfix[30];
			printf("Enter infix expression");
        	scanf("%s",exp);
        	infixToPostfix(exp, postfix);  
       		result= evaluate(postfix);  
        	printf("Result= %d\n", result);

		case 6:
			printf("\nBracket matching\n");
			printf("Enter expression");          
			scanf("%s",exp);
         	if (isMatchingBrackets(exp)) 
              	printf("Brackets are balanced!\n");
			else 
                printf("Brackets are not balanced!\n");
            

		case 0:

		default:
			printf("\nNo sorting for you\n");
			break;
		}

	} while (n != 0);

	return 0;
}
