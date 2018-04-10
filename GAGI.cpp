#include <stdio.h>
#include <math.h>
int main()
{
	int a,b,i=0;
	scanf("%d%d",&a,&b);
    while (a<=b)
    {
        i++;
        a=a*2;
    }
    printf ("%d",--i);
}
