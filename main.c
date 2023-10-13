#include <stdio.h>
#include "stack.h"
//#include "postfixeval.h"
int main()
{
	
	int n;
	char exp[100];
	Stack mystack;
    printf("\nhello.");
	
	do
	{
		printf("\nMenu:\n0: Exit \n1: Quicksort sort \n2: Merge sort \n3: Stack");
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
			printf("\nPostfix evaluation\n");
			//scanf("%[^\n]s",exp);
            //char exp[] = "231*+9-";
			char exp[30] ;
            int result;
			printf("enter postfix expression");
            scanf("%s",exp);
            result= evaluate(exp);  
            printf("Result= %d\n", result);
			break;

		case 0:

		default:
			printf("\nNo sorting for you\n");
			break;
		}

	} while (n != 0);

	return 0;
}
