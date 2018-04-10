#include<stdio.h>
#include<string.h>
int main()
{
	int i,n,s;
	do
	{
		scanf("%d",&n);
	}
	while(n<=0);
	while(n>0)
	{
		s=n%10;
		printf("%d",s);
		n=n/10;
	}
}
