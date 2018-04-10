#include <stdio.h>
#include <math.h>
int main()
{
    long long a,b,i;
    scanf("%lld%lld",&a,&b);
    while(b>0)
    {
    	i=a%b;
    	a=b;
    	b=i;
	}
    printf("%lld",a);
}
