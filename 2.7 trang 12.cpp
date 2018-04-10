#include<stdio.h>
void nhap(float &a,float &b,float &c,float &d,float &e,float &f)
{
	printf("3 doi so cua pt 1: ");
	scanf("%f%f%f",&a,&b,&c);
	printf("3 doi so cua pt 2: ");
	scanf("%f%f%f",&d,&e,&f);
}
void tinh(float &a,float &b,float &c,float &d,float &e,float &f)
{
	float x,y;
	if(   (a==0 && b==0 && c==0)
		||(d==0 && e==0 && f==0)
		||(((a==c && d==f) || (a==0 && d==0)) && (c/b==f/e))
		||(b==c && e==f) || (b==0 && e==0 )&& (c/a==f/d))
	{
		printf("he phuong trinh co vo so nghiem");
	}
	else if(b*d==e*a) printf("he phuong trinh vo nghiem");
	else if(a!=0 && e!=0)
	{
		y=(c*d-f*a)/(b*d-e*a);
		x=(c-b*y)/a;
		printf("x = %f\ty = %f",x,y);
	}
	else if(b!=0 && d!=0)
	{
		x=(f*b-e*c)/(b*d-e*a);
		y=(c-a*x)/b;
		printf("x = %f\ty = %f",x,y);
	}
}
int main()
{
	float a,b,c,d,e,f;
	nhap(a,b,c,d,e,f);
	tinh(a,b,c,d,e,f);
}
