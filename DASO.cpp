#include <stdio.h>
int main()
{
    long long a[30000],n,i,j=1,so1,so2,d[30000],max,k;
    scanf("%lld",&n);
    max=d[j]=2;
    for(i=0;i<n;i++)
    {
    	scanf("%lld",&a[i]);
	}
	so1=a[0];so2=a[1];
    for(i=2;i<n;i++)
    {
        if(a[i]==(so1+so2))
        {
            d[j]++;
        }
        else if(d[j]>1)
        {
        	j++;d[j]=2;
		}
        so1=so2;
        so2=a[i];
    }
    for(k=j;k>0;k--)
    {
    	if(max<=d[k]) max=d[k];
	}
    if(max>2) printf("%lld",max);
    else printf("-1");
}
