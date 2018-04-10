#include <stdio.h>
#include <math.h>
int main()
{
    long long n,i;
    int d=0;
    scanf("%lld",&n);
    for(i=2;i<=sqrt(n);i++)
    { 
		if (n%i==0)
		{
			d=1;break;
		}
    }
    if(d==1 || n==1) printf("NO");
    else printf("YES");
}                              
