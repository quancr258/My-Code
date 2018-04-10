#include <stdio.h>
#include <math.h>
int main()
{
    long long n,t=0;
    scanf("%lld",&n);
    while(n>0)
    {
    	t+=n%10;
    	n/=10;
	}
	if(t%10==9) printf("YES");
	else printf("NO");
}
