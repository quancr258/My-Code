#include <stdio.h>
#include <math.h>
int main()
{
    int xd,xc,td,tc,a,b,c,d,e=0;
    scanf("%d%d%d%d",&xd,&xc,&td,&tc);
    c=td;d=tc;
	while(td>0 && tc>0)
	{
		if(xd!=td && xc!=tc) e++;
		td--;tc--;
	}
	td=c;tc=d;
	while(td>0 && tc<9)
	{
		td--;tc++;
		if(td>0 && tc<9 && (xd!=td && xc!=tc)) e++;
	}
	td=c;tc=d;
	while(td<9 && tc>0)
	{
		td++;tc--;
		if(td<9 && tc>0 && (xd!=td && xc!=tc)) e++;
	}
	td=c;tc=d;
	while(td<9 && tc<9)
	{
		td++;tc++;
		if(td<9 && tc<9 && (xd!=td && xc!=tc)) e++;
	}	
    printf("%d",e+=15);
}
