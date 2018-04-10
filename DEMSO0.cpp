#include <stdio.h>
#include <math.h>
int main()
{
    int n,d=0;
    scanf("%d",&n);
	while(n>=5)
	{
		d+=n/5;
		n/=5;
	}
	printf("%lld",d);
}
