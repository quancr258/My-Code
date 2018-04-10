#include <stdio.h>
#include <math.h>
int main()
{
	long a,i,n,d;
	scanf("%ld%ld",&a,&n);
	d=a;
	for(i=1;i<n;i++)
	d=(d*a)%10;
	printf("%ld",d);
}
