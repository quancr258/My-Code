#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
	int n,i,x,t=0;
	float s;
	//nhap vao so 0<n<50
	printf("nhap vao n = ");
	scanf("%d",&n);
	while(n<=0 || n>=50)
	{
		printf("nhap vao n = ");
		scanf("%d",&n);
	}
	//nhap vao so x>0
	printf("\nnhap vao x = ");
	scanf("%d",&x);
	while(x<=0)
	{
		printf("nhap vao x = ");
		scanf("%d",&x);
	}
	//tinh
	for(i=1;i<=n;i++)
	{
		t=t+i;
		s=s+x/(sqrt(t));
	}
	printf("\n Tong S = %f",s);
}
