#include <stdio.h>
#include <math.h>
int main()
{
	long long n,m,g=0,c=0;
	scanf("%d%d",&n,&m);
	if(n*2==m) g=n;
	else if(n*4==m) c=n;
	else if(n*4<m) g=-1;
	else if(n*4>m)
	{
		if((n*4-m)>=4)
		{
			if(((n*4-m)%4)==0) 
			{
				g=(n*4-m)/4;c=n-g;
				while(g*2+c*4!=m)
				{
					c--;g++;
				}
			}
			else g=-1;
		}
		else
		{
			g=(n*4-m)/4;c=n-g;
			while(g*2+c*4!=m)
			{
				c--;g++;
			}
		}
	}
	if(g>=0 && c>=0) printf("%d %d",g,c);
	else printf("-1");
}
