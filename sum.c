#include <stdio.h>

int main()

{
	int i, s = 0,n = 10;
	i = 1;
	while (i <= n)
	{
		s += i;
		i++;
	}
	printf("Sum = %d", s);
	return 0;
}
