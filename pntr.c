#include<stdio.h>

int main()
{
	int num=20;
	int *ptr;
	printf("the value of variable num is \n %d",num);
	*ptr=30;
	printf("the value of variable num is \n %d",num);
	ptr=&num;
	printf("\n the value of the variable num through the pointer variable ptr is \n %d",*ptr);
	return 0;
}
