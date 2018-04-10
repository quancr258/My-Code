#include <stdio.h>
#include <math.h>
int main()
{
	long long n,i;
	double a;
		scanf("%lld",&n);
		a=sqrt(8*n+1);
		if(a==(long long)a) printf("YES");
		else printf("NO");
}
