#include<stdio.h>

int main()
{
	int a;
	printf("enter the number : ");
	scanf("%d",&a);
	if( a%2==0)
	{
		printf("%d is a prime number",a);
	}
	else
	{
		printf("%d is not a prime number",a);
	}
	return 0;
}
