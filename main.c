#include <stdio.h>
#include "stack.h"
#include "postfixeval.h"
#include "dijkstra.h"
#include "binarytree.h"
#include "bracketmatching.h"
#include "infixtopostfix.h"
#include <stdlib.h>
int main()
{

	int n;
	char exp[100];
	Stack mystack;
	printf("\nhello.");
	int c , m, value;
    Node* root = NULL;
	do
	{
		printf("\nMenu:\n0: Exit \n1: Quicksort sort \n2: Merge sort \n3: Stack \n4: Postfix Evaluation \n5: Infix to Postfix \n6: Braket matching \n7: Dijkstra Algorithm \n8: Binary Tree");
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
			push(&mystack, 50);
			push(&mystack, 10);
			push(&mystack, 29);
			push(&mystack, 22);

			// printf("%d",pop(&mystack));

			// pop
			while (!is_empty(&mystack))
			{
				int item = pop(&mystack);
				printf("%d\n", item);
			}
			break;

		case 4:
			printf("\nPostfix Evaluation\n");
			// scanf("%[^\n]s",exp);
			// char exp[] = "231*+9-";
			char exp[30];
			int result;
			printf("Enter postfix expression");
			scanf("%s", exp);
			result = evaluate(exp);
			printf("Result= %d\n", result);
			break;

		case 5:
			printf("\nInfix to Postfix\n");
			char postfix[30];
			printf("Enter infix expression");
			scanf("%s", exp);
			infixToPostfix(exp, postfix);
			result = evaluate(postfix);
			printf("Result= %d\n", result);

		case 6:
			printf("\nBracket matching\n");
			printf("Enter expression");
			scanf("%s", exp);
			if (isMatchingBrackets(exp))
				printf("Brackets are balanced!\n");
			else
				printf("Brackets are not balanced!\n");

		case 7:
			printf("Shortest path using dijkstra algorithm\n");
			int src = 0;
			int graph[V][V] = {
				{0, 4, 0, 0, 0, 0, 0, 8, 0},
				{4, 0, 8, 0, 0, 0, 0, 11, 0},
				{0, 8, 0, 7, 0, 4, 0, 0, 2},
				{0, 0, 7, 0, 9, 14, 0, 0, 0},
				{0, 0, 0, 9, 0, 10, 0, 0, 0},
				{0, 0, 4, 14, 10, 0, 2, 0, 0},
				{0, 0, 0, 0, 0, 2, 0, 1, 6},
				{8, 11, 0, 0, 0, 0, 1, 0, 7},
				{0, 0, 2, 0, 0, 0, 6, 7, 0}};
			dijkstra(graph, src);
			break;

		case 8:
			printf("Binary tree\n");
			do{
			printf("\n Enter 1: Insert node \n 2: preorder,inorder,postorder");
			
			scanf("%d", &c);
			switch (c)
			{
			case 1:
				printf("Enter the number of nodes: ");
				scanf("%d", &m);

				for (int i = 0; i < m; i++)
				{
					printf("Enter value for node %d: ", i + 1);
					scanf("%d", &value);
					insert(&root, value);
				}
				break;
			case 2:
				preorderTraversal(root);
				inorderTraversal(root);
				postorderTraversal(root);
			default:
				c = 0;
			}
			}
			while(c);
			free(root);
			break;

	case 0:

	default:
		printf("\nNo sorting for you\n");
		break;
	}
}
while (n != 0);

return 0;
}
