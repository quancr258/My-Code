#include <stdio.h>
#include <math.h>
int main()
{
	long i,n,d;
	scanf("%ld",&n);
	d=n;
	while(n>=10)
	{
		n-=10;
		n+=3;
		d+=3;

	}
	printf("%ld",d);
}
