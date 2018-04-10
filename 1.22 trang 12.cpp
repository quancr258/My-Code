#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	long long x,s,n,m,t,d;
	for(n=1;n<1000000;n++)
	{
	s=n;x=n;d=0;t=0;m=0;
	while(s>0)
	{
		s/=10;
		d++;
	}
	while(x>0)
	{
		m=x%10;
		t+=pow(m,d);
		x/=10;
	}
	if(t==n) printf("%lld\t",t);
	}
}
