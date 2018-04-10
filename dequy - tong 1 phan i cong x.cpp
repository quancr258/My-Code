//tinh tong s=1/(i+x) voi i->n
#include <stdio.h>
#include <math.h>
void nhap(float &n,char c);
float dequy(float n,float s,float x);
int main()
{
	float n,x,s=0;
	nhap(n,'n');
	nhap(x,'x');
	dequy(n,s,x);
	printf("tong s = %f",dequy(n,s,x));
}
void nhap(float &n,char c)
{
	do
	{
		printf("nhap %c = ",c);
		scanf("%f",&n);
	}
	while(n<0)
}
float dequy(float n,float s,float x)
{
	if(n>0)
		dequy(n-1,s+1/(n+x),x);
	else return s;
}
