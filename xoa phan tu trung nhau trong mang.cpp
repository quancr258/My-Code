#include <stdio.h>
#define max 50
int main()
{
	int n,i,a[max],t,j;
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
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		if(a[i]==a[j])
		{
			a[i]=a[n-1];
			n--;
			i=-1;
		}
	}
	printf("\n day so sau khi chinh sua la: ");
	for(i=0;i<n;i++)
	printf("%5d",a[i]);
}
