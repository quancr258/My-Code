#include <stdio.h>
#include <math.h>
int main()
{
    int a,b=7,c=0;
    scanf("%d",&a);
    if((a/7)%2==0)
    {
    	b=a%7;
    	c=7-b;
	}
	else
	{
		c=a%7;
		b=7-c;
	}
    printf("%d %d",c,b);
}
