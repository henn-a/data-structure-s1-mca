#include<stdio.h>

int main()
{
	int a,b,c;
	printf("enter the numbers:");
	scanf("%d,%d,%d",&a,&b,&c);
	if( a > b )
	{
		printf("%d is the largest",a);
	}
	else
	{
		if( b > c )
		{
			printf("%d is the largest",b);
		}
		else
		{
			printf("%d is the largest",c);
		}
	}
	return 0;
}
