#include <stdio.h>
#include <math.h>
int main()
{
    long long a[1001],k,l;
    int i,n;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
    	scanf("%lld",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		k=a[i],l=0;
		while(a[i]!=0)
		{
			l=l*10+(a[i]%10);
			a[i]=a[i]/10;
		}
		if(k==l) printf("%lld ",k);
	}
}
