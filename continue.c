#include<stdio.h>

int main()
{
	int i = 1;
	while( i <= 10 )
	{
		if( i <= 5 )
		{
			i=i+1;
			continue;
		}
	printf("%d",i);
	i=i+1;
	}
	return 0;
}		
