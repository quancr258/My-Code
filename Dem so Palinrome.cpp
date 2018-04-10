#include <stdio.h>
#include <math.h>
int main()
{
    long long d[1001],l[1001],r[1001],k,n,t,i,j,max,min;
    scanf("%lld",&t);
    for(i=0;i<t;i++)
    	scanf("%d%d",&l[i],&r[i]);
    for(i=0;i<t;i++)
    {
    	d[i]=0;
    	if(l[i]>r[i])
    	{
    		max=l[i];min=r[i];
		}
		else
		{
			max=r[i];min=l[i];
		}
    	for(j=min;j<=max;j++)
    	{
    		k=j;n=0;
    		while(k!=0)
			{
				n=n*10+(k%10);
				k/=10;
			}
			if(j==n) d[i]++;
		}
	}
	for(i=0;i<t;i++)
		printf("%d\n",d[i]);
}
