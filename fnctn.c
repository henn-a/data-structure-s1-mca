#include<stdio.h>

int sum(int,int);

int main()
{
	int num1=10,num2=20,res;
	res=sum(num1,num2);
	printf("%d\n",res);
	return 0;
}
int sum(int num1,int num2)
{
	int res;
	res=(num1+num2);
	return(res);
}
