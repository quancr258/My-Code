#include <stdio.h>
#include <conio.h>
int main()
{
	int n,i;
	float tong=1;
	printf("nhap vao n = ");
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		if(i%2==0) tong= tong + 1.0/i;
		else tong= tong - 1.0/i;
	}
	
	printf("\ntong cua bai toan la: tong = %f",tong);
	getch();
}
