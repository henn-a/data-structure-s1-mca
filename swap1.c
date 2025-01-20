#include<stdio.h>

int main()
{
	int a,b;
	printf("enter the numbers:");
	scanf("%d,%d",&a,&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("the numbers after swapping : a = %d and b = %d",a,b);
	return 0;
}
