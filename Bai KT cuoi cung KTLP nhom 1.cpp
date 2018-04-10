#include<stdio.h>
#include<math.h>
#define MAX 50
int nhap(int a[][MAX],int &m, int &n)
{
	int i,j;
	do
	{
		printf("Nhap vao so hang 0<m<%d: m = ",MAX);
		scanf("%d",&m);
		printf("\nNhap vao so cot 0<n<%d: n = ",MAX);
		scanf("%d",&n);
	}
	while(m<=0 || n<=0 || m>=MAX || n>=MAX);
	for(i=0;i<m;i++)
	  for(j=0;j<n;j++)
	  {
	  	printf("\nNhap vao phan tu thu a[%d][%d]: ",i+1,j+1);
	  	scanf("%d",&a[i][j]);
	  }
}
int xuat(int a[][MAX],int m, int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
}
bool snt(int a[][MAX],int m, int n)
{
	int i,j,k,d=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=2;k<=sqrt(a[i][j]);k++)
				if(a[i][j]%k==0 || a[i][j]<=1)
				{
					d=1;
					break;
				}
			if(d==1) break;
		}
		if(d==1) break;
	}
	if(d==1) return false;
	else return true; 
}
int nhapx(int &x,int n)
{
	do
	{
		printf("\nNhap vao cot 0<x<=%d can tinh tong: ",n);
		scanf("%d",&x);
	}
	while(x<=0||x>n);
}
int tongx(int a[][MAX],int m, int n,int x,int s)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==x-1)
			s+=a[i][j];
		}
	}
	return s;
}
int tongmax(int a[][MAX],int m, int n,int &k)
{
	int u=1,max=0,s;
	while(u<=n)
	{
		if(tongx(a,m,n,u,s)>max) 
		{
			max=tongx(a,m,n,u,s);
			k=u;
		}
		u++;
	}
	return max;
}
void file(int a[][MAX],int m, int n)
{
	int i,j;
	FILE* f;
	f=fopen("D:\\DevC++\\Bai Tap\\Bai KT cuoi cung KTLP nhom 1.txt","w+t");
	if(f==NULL)
	{
		printf("Loi mo FILE!");
	}
	else
	{
		fflush(stdin);
		fprintf(f,"Ma tran mxn : %dx%d\n",m,n);
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
		  	{
		  		fprintf(f,"%5d",a[i][j]);
		  	}
		  	fprintf(f,"\n");
		}
		printf("Da ghi file");
		fclose(f);
	}
}
void mofile(int a[][MAX],int m,int n)
{
	int i,j;
	FILE* f;
	f=fopen("D:\\DevC++\\Bai Tap\\Bai KT cuoi cung KTLP nhom 1.txt","rt");
	if(f==NULL)
	{
		printf("Loi mo FILE!");
	}
	else
	{
		fflush(stdin);
		fscanf(f,"%d%d",&m,&n);
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
		  	{
		  		fscanf(f,"%d",&a[i][j]);
		  	}
		  	printf("\n");
		}
		printf("\nMang sau khi doc tu file:\n");
		xuat(a,m,n);
		printf("Da in file");
		fclose(f);
	}
}
int main()
{
	int a[MAX][MAX],m,n,x,k,s;
	nhap(a,m,n);
	printf("\nMa tran vua nhap la:\n");
	xuat(a,m,n);
	if(snt(a,m,n)==false) printf("\nTrong ma tran co phan tu khong phai la so nguyen to\n");
	else printf("\nTat ca cac phan tu trong ma tran deu la so nguyen to\n");
	nhapx(x,n);
	printf("\nTong cac phan tu tren cot %d la: %d\n",x,tongx(a,m,n,x,s));
	printf("\nCot co tong lon nhat la %d voi tong la: %d\n",k,tongmax(a,m,n,k));
	file(a,m,n);
	mofile(a,m,n);
}
