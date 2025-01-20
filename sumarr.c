#include<stdio.h>

int main()
{
	int arr[10],sum=0,n,i,j;
	printf("Enter the elements : ");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(j=0;j<=n-1;j++)
	{
		sum=sum+arr[j];
	}
	printf("sum = %d",sum);
	return 0;
}
