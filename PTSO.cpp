#include <stdio.h>
#include <math.h>
int main()
{
    long long a[500],m,n,i=2,k=0,j,l;
    int d=0;
    scanf("%lld",&n);
    while(n>1 && i<=n)
    {
    	for(j=1;j<=sqrt(i);j++)
    	{
    		if (i%j==0)
			{
				d++;
				if(d==2) break;
			}
		}
		if(d<2 && n%i==0)
			{
				if(n>i) printf("%lld*",i);
				else printf("%lld",i);
				n/=i;
				i=1;
			}
		d=0;
		i++;
	}
}
