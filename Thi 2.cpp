#include <stdio.h>
#include <conio.h>
int nhap(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("nhap vao phan tu thu a[%d]: ",i+1);
		scanf("%d",&a[i]);
	}
}
int xuat(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%5d",a[i]);
}
int max(int a[],int n)
{
	int i,max=a[0],t;
	for(i=0;i<n;i++)
		if(max<a[i]) max=a[i];
	for(i=0;i<n;i++)
	{
		if(a[i]==max)
		{
			t=a[i];
			a[i]=a[0];
			a[0]=t;
		}
	}
	for(i=0;i<n;i++)
		printf("%5d",a[i]);
}
int snt(int x)
{
	int i,d=0;
	for(i=1;i<=x;i++)
	{
		if(x%i==0) d++;
	}
	if(d==2) printf("%d la so nguyen to",x);
	else printf("%d khong phai la so nguyen to",x);
}
int ktr(int a[],int n)
{
	int i,j,v=0;
	for(i=0;i<n;i++)
	{   
	   for(j=1;j<=a[i];j++)
		{
			if(a[i]%j==0) v++;
		}
		if(v==2) printf("%5d",a[i]);
		v=0;
	}
}
int main()
{
	int a[60],n,x;
	printf("nhap n = ");
	scanf("%d",&n);
	while(n<1 || n>50)
	{
		printf("nhap vao n = ");
		scanf("%d",&n);
	}
	nhap(a,n);
	printf("mang vua nhap la: ");
	xuat(a,n);
	printf("\nmang sau khi chinh sua: ");
	max(a,n);
	printf("\nnhap vao so tu nhien x = ");
	scanf("%d",&x);
	while(x<0)
	{
		printf("nhap vao so tu nhien x = ");
		scanf("%d",&x);
	}
	snt(x);
	printf("\ncac so nguyen to trong mang la: ");
	ktr(a,n);
}
