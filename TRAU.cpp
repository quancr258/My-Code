#include <stdio.h>
#include <math.h>
int main()
{
	long long bc,n,m,a=0,b=0,c=0;
	scanf("%lld%lld",&n,&m);
	bc=n/3; c=bc*3;
	if(n>c)
	{
		a=n-c;
		while(c/3+a*5<=m && a>=0 && b>=0 && c>=0)
		{
			c-=3;a+=3;
		}
		while(c/3+a*5+b*3!=m && a>=0 && b>=0 && c>=0)
		{
			while(c/3+a*5+b*3<m && a>=0 && b>=0 && c>=0)
			{
				c-=3;b+=3;
			}
			while(c/3+a*5+b*3>m && a>=0 && b>=0 && c>=0)
			{
				a-=1;b+=1;
			}
		}
	}
	if(a>0 && b>0 && c>0) printf("%d %d %d",a,b,c);
	else printf("-1");
}
