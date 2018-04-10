#include <stdio.h>
#include <conio.h>
int main()
{
	int a[60],n,i,j,max1,max2=0;
	//2.1
	printf("Nhap vao so phan tu N = ");
	scanf("%d",&n);
	while(n<4 || n>8)
	{
		printf("Nhap vao so phan tu N = ");
		scanf("%d",&n);
	}
	for(i=0;i<n;i++)
	{
		printf("\nNhap vao phan tu thu a[%d] = ",i+1);
		scanf("%d",&a[i]);
	}
	//2.2 in ra cac so nguyen to
	printf("\nCac so nguyen to trong day la: ");
	for(i=0;i<n;i++)
	{
	  	for(j=1;j<a[i];j++)
		{
		  if(a[i]>1)
		  {
			if(j!=1 && a[i]%j==0) break;
			if(j==a[i]-1 || a[i]==2) printf("%5d",a[i]);
		  }
		}
	}
	//2.3 tim so lon thu 2 trong day
	max1=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>max1) 
		 max1=a[i];
	}
	for(i=0;i<n;i++)
	{
		if(a[i]>max2 && a[i]<max1)
		max2=a[i];
	}
	printf("\nSo lon thu 2 trong day la: %d",max2);
	//2.4 chia day so thanh k day con
	int k,dem1,dem2,m=0;
	printf("\nNhap vao so day con K = ");
	scanf("%d",&k);
	while(k>n || k<1)
	{
		printf("\nNhap vao so day con K = ");
		scanf("%d",&k);
	}
	dem1=n%k; dem2=n/k;
	if(dem1>0)
	{
		m++;
		printf("\n Day con thu %d la:",m);
		for(i=0;i<(dem1+dem2);i++)
		{
			printf("%5d",a[i]);
			a[i]=a[n-1];
			n--;
		}
	}
	while(m<k)
	{
		m++;
		printf("\n Day con thu %d la:",m);
		for(i=0;i<dem2;i++)
		{
			printf("%5d",a[i]);
			a[i]=a[n-1];
			n--;
		}
	}
}
