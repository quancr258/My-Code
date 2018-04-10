#include <stdio.h>
#include <math.h>
int main()
{
	char a[100],n,i,t=0,p=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		if(a[i]==1) t++;
		else p++;
	}
	printf("%d",abs(t-p));
}
