#include <stdio.h>
#include <math.h>
int main()
{
    int h,p,s,h1,p1,s1;
    scanf("%d%d%d",&h,&p,&s);
    if(s<59)
    {
    	s1=s+1;p1=p;h1=h;
	}
    else if(s==59 && p<59)
    {
    	s1=0;p1=p+1;h1=h;
	}
	else if(s==59 && p==59 && h<23)
	{
		s1=0;p1=0;h1=h+1;
	}
	else if(s==59 && p==59 && h==23)
	{
		s1=0;p1=0;h1=0;
	}
	printf("%d %d %d",h1,p1,s1);
}
