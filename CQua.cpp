#include <stdio.h>
#include <math.h>
int main()
{
    int a,n,i,b=0,c;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
		scanf("%d",&a);
		if(a==200) b++;
		else c++;
	}
    if((c%2==0)&&(c!=0) ||((b%2==0)&&(c==0))) printf("YES");
    else printf("NO");
}
