#include<stdio.h>
#include<string.h>
int main()
{
	int s=0,t=0,i,n;
	do
	{
		scanf("%d",&n);
	}
	while(n<=0);
	t=n%10;n=n/10;
	while(n>0)
	{
		s=n%10;
		if(s<t) t=s;
		else break;
		n=n/10;
	}
	if(n==0) printf("YES");
	else printf("NO");
}
