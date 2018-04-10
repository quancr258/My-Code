#include <stdio.h>
#include <math.h>
int main()
{
	float a12,a13,a14,a23,a24,a34,b;
    int x1,y1,x2,y2,x3,y3,x4,y4,d=0;
    scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
    a12=pow((x1-x2),2)+pow((y1-y2),2);
    a13=pow((x1-x3),2)+pow((y1-y3),2);
    a14=pow((x1-x4),2)+pow((y1-y4),2);
    a23=pow((x2-x3),2)+pow((y2-y3),2);
    a24=pow((x2-x4),2)+pow((y2-y4),2);
    a34=pow((x3-x4),2)+pow((y3-y4),2);
    if(a12==a13)
    {
    	if(a14==a12*2) d=1;
	}
	if(a12==a14)
    {
    	if(a13==a12*2) d=1;
	}
	if(a13==a14)
    {
    	if(a12==a13*2) d=1;
	}
	if(a23==a12)
    {
    	if(a24==a23*2) d=1;
	}
	if(a23==a24)
    {
    	if(a12==a24*2) d=1;
	}
	if(a12==a24)
    {
    	if(a23==a12*2) d=1;
	}
	if(a23==a13)
    {
    	if(a34==a13*2) d=1;
	}
	if(a34==a13)
    {
    	if(a23==a13*2) d=1;
	}
	if(a23==a34)
    {
    	if(a13==a23*2) d=1;
	}
	if(d==1) printf("YES");
	else printf("NO");
}
