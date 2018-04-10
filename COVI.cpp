#include <stdio.h>
#include <math.h>
int main()
{
    int x1,y1,x2,y2,x3,y3,x4,y4,t1,t2,d=0;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    if(x1<=x2<0 || y1<=y2<0)
	{
		t1=abs(abs(y1)-abs(y2));
		t2=abs(abs(x1)-abs(x2));
	}
	else
	{
		t1=abs(y1-y2);
		t2=abs(x1-x2);
	}
    if(x1!=x2 && y1!=y2)
    {
    	if(t1>=t2>1 || t1==t2==1 || t1<=t2<-1 || t1==t2==-1)
    	{
	    	x3=x1;y3=y2;
    		x4=x2;y4=y1;
    	}
    	else {printf("%d",-1);d=1;}
	}
	else if(x1==x2)
	{
		x3=x4=x1+t1;
		y3=y1;y4=y2;
	}
	else if(y1==y2)
	{
		y3=y4=y1+t2;
		x3=x1;x4=x2;
	}
	if(d!=1) printf("%d %d %d %d",x3,y3,x4,y4);
}
