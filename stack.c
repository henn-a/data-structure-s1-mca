#include<stdio.h>
#include <stdlib.h>  
#define SIZE 10

int top = -1,arr[SIZE];  
void push();  
void pop();  
void traversal();  

int main()

{
	int ch;  
	while (1)
	{  
		printf("\nPerform operations on the stack:");  
		printf("\n1.Push\n2.Pop\n3.Traversal\n4.End");  
		printf("\n\nEnter the choice: ");  
		scanf("%d", &ch);  
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				traversal();
				break;
			case 4:
				return(0);
			default:
			printf("\n\nWrong choice entered");
		}
	}
}

void push()  
{  
	int n; 
	if (top == SIZE - 1)  
	{  
		printf("\nOverflow!!");  
	}  
	else  
	{  
		printf("\nEnter the element to be added onto the stack: ");  
		scanf("%d", &n);  
		top = top + 1;  
		arr[top] = n;  
	}  
}
  
void pop()  
{  
	if (top == -1)  
	{  
		printf("\nUnderflow!!");  
	}  
	else  
	{	  
		printf("\nPopped element: %d",arr[top]);  
		top = top - 1;  
	}  
}  

void traversal()  
{  
	if (top == -1)  
	{  
		printf("\nUnderflow!!");  
	}  
	else  
	{  
		printf("\nElements in the stack: \n");  
		for (int i = top; i >= 0; --i)  
		printf("%d\n",arr[i]);  
	}  
}  
