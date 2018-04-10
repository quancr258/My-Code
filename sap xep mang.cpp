#include <stdio.h>
#define max 50
int main()
{
	int n,i,a[max],t;
	printf("nhap vao so phan tu n = ");
	scanf("%d",&n);
	while(n<1)
	{
		printf("nhap vao so phan tu hop le n = ");
		scanf("%d",&n);
	}
	for(i=0;i<n;i++)
	{
		printf("\n nhap vao phan tu thu a[%d] :",i+1);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
		{
			t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
			i=-1;
		}
	}
	printf("\n day so sau khi sap xep tang dan la : ");
	for(i=0;i<n;i++)
	printf("%5d",a[i]);
	for(i=0;i<n-1;i++)
	{
		if(a[i]<a[i+1])
		{
			t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
			i=-1;
		}
	}
	printf("\n day so sau khi sap xep giam dan la: ");
	for(i=0;i<n;i++)
	printf("%5d",a[i]);
}
