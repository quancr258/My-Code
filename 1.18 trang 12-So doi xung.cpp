#include <stdio.h>
#include <math.h>
int main()
{
    long long n,k,l;
    int i;
    do
	{
		scanf("%lld",&n);
	}
	while(n<=0);
		k=n,l=0;
		while(n>0)
		{
			l=l*10+(n%10);
			n=n/10;
		}
		if(k==l) printf("YES");
		else printf("NO");
}
