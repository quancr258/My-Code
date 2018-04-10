#include<stdio.h>
int main()
{
	int d,n,t=0;
	do
	{
		scanf("%d",&d);
	}
	while(d<0);
	if(d>20)
	{
		n=d-20;
		t+=n*10000;
		d-=n;
	}
	if(d>10 && d<=20)
	{
		n=d-10;
		t+=n*12000;
		d-=n;
	}
	if(d>1 && d<=10)
	{
		n=d-1;
		t+=n*15000;
		d-=n;
	}
	if(d<=1) t+=20000;
	printf("%d",t);
}
