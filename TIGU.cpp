#include <stdio.h>
#include <math.h>
int main()
{
    long long n,m,g,i=0;
    float t,tt;
    scanf("%lld%lld",&n,&m);
    while(n<m)
    {
    	i++;
    	t=n*(0.1);g=t;tt=t-g;
    	if(tt>=0.5) g++;
    	n+=g;
	}
	printf("%lld",i);
}
