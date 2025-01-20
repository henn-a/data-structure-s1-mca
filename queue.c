#include<stdio.h>
#include<stdlib.h>  
#define maxsize 5
  
void enqueue();
void dequeue();
void traversal();

int FRONT = -1,REAR = -1;  
int queue[maxsize];  

int main()

{
	int ch;   
	while(ch != 4)   
	{
		printf("\n1.Enqueue an element  \n2.Dequeue an element  \n3.traversal the elements  \n4.Exit  \n");
		printf("\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:		
			enqueue();
			break;
			
			case 2:
			dequeue();
			break;

			case 3:
			traversal();
			break;

			case 4:
			exit(0);
			break;

			default:
	
			printf("enter a valid choice");
		}
	}
}

void enqueue()
{
	int ITEM;
	printf("\nEnter the element : \n");
	scanf("%d",&ITEM);
	if (REAR == maxsize-1)
	{
		printf("\n Overflow \n");
		return;
	}
	if (FRONT == -1 && REAR == -1)
	{
		FRONT = REAR = 0;
	}
	else
	{
		REAR = REAR + 1;
	}
	queue[REAR] = ITEM;
	printf("\n element inserted\n");
}

void dequeue()
{
	int ITEM;
	if (FRONT ==-1)
	{
	printf("\n UNDERFLOW\n");
	return;	
	}
	else
	{
	ITEM = queue[FRONT];
	if (FRONT == REAR)
	{
		FRONT = -1;
		REAR = -1;
	}
	else
	{
		FRONT = FRONT + 1;
	}
	printf("\n element deleted\n");
	}
}

void traversal()
{
	int i;
	if (REAR == -1)
	{
		printf("\n Queue is empty \n");
	}
	else
	{
		for(i = FRONT ; i <= REAR ; i++)
		{
			printf("\n %d\n",queue[i]);
		}
	}
}

