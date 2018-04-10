#include<stdio.h>
#define max 255
int nhap(int n,int a[][max])
{
	int i,j;
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
	   {
	   		printf("nhap vao phan tu a[%d][%d]: ",i+1,j+1);
	   		scanf("%d",&a[i][j]);
	   }
}
int xuat(int n,int a[][max])
{
	int i,j;
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
	   {
	   		printf("%d\t",a[i][j]);
	   		if(j==n-1) printf("\n");
	   }
}
//cau a: Xac dinh ma tran B thong qua loai bo hang i va cot j
int cau_a(int n,int a[][max])
{
	int i,j,c,d;
	do
	{
		printf("nhap hang can loai bo: i = ");
		scanf("%d",&c);
		printf("\nnhap cot can loai bo: j = ");
		scanf("%d",&d);
	}
	while(c>n || d>n || c<1 || d<1);
	printf("Ket qua cua cau a, Ma tran B la: \n");
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
	   {
	   		if(i==c-1 || j==d-1) {continue;}
	   		else 
			{
				printf("%d\t",a[i][j]);
	   			if((j>=n-2 && n<=4) || (j>n-2 && n>=5)) printf("\n");
	   		}
	   }
}
//cau b: Xac dinh ma tran B thong qua hoan vi 2 cot i va j
int cau_b(int n,int a[][max])
{
	int i,j,c,d,e,f,t;
	do
	{
		printf("nhap cot can hoan vi: i = ");
		scanf("%d",&c);
		printf("\nnhap cot duoc hoan vi: j = ");
		scanf("%d",&d);
	}
	while(c>n || d>n || c==d || c<1 || d<1);
	if(c<d)
	{
		e=c-1;
		f=d-1;
	}
	else 
	{
		e=d-1;
		f=c-1;
	}
	printf("Ket qua cua cau b, Ma tran B la: \n");
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
	   {
	   		if(j==e)
	   		{
	   			t=a[i][e];
	   			a[i][e]=a[i][f];
	   			a[i][f]=t;
			}
			{
				printf("%d\t",a[i][j]);
	   			if(j>=n-1) printf("\n");
	   		}
	   }
}
int main()
{
	int a[max][max],n;
	printf("n = "); scanf("%d",&n);
	nhap(n,a);
	printf("Ma tran vuong vua nhap la: \n");
	xuat(n,a);
	printf("Cau a: \n");
	cau_a(n,a);
	printf("Cau b: \n");
	cau_b(n,a);
}
