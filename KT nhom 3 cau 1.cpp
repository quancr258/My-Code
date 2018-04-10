#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
	int i,x;
	float s,e=0.001;
	printf("Nhap vao so x = ");
	scanf("%d",&x);
	while(x<=1)
	{
		printf("Nhap vao so x = ");
		scanf("%d",&x);
	}
	s=1.0/x;
	for(i=1;s<e;i++)
	{
		s=s+(1.0/(pow(x,i)));
	}
	printf("\nTong S = %f",s);
	getch();
}
