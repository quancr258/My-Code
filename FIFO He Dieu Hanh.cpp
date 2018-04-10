#include<stdio.h>
#include<conio.h>
#include<algorithm>
#define MAX 10000
using namespace std;
void nhap(struct chuongtrinh a[],int &n,int &m);
void xuat(struct chuongtrinh a[],int n);
void nhapf(char *d,struct chuongtrinh a[],int n,int m);
void lamf(char *d,struct chuongtrinh a[],int n, int m);
void xuatf(char *d,struct chuongtrinh a[],int n,int m);
bool sosanh(const chuongtrinh &x,const chuongtrinh &y);
struct chuongtrinh
{
	int tgvao;
	int tglam;
	int tgcho;
	int tgra;
	int tgbd;
	int ta;
	int p;
};
int main()
{
	int n,m;
	char *d;
	struct chuongtrinh a[MAX],p;
	nhap(a,n,m);
	nhapf("D:\\DevC++\\Bai Tap\\FIFO He Dieu Hanh.txt",a,n,m);
	sort(a,a+n,sosanh);
	lamf("D:\\DevC++\\Bai Tap\\FIFO He Dieu Hanh.txt",a,n,m);
	xuat(a,n);
	xuatf("D:\\DevC++\\Bai Tap\\FIFO He Dieu Hanh.txt",a,n,m);
}
void nhap(struct chuongtrinh a[],int &n,int &m)
{
	int i;
	printf("Numprocess: "); scanf("%d",&n);
	printf("Overhead: "); scanf("%d",&m);
	for(i=0;i<n;i++)
	{
		a[i].p=i+1;
		printf("P%d ",a[i].p);scanf("%d%d",&a[i].tgvao,&a[i].tglam);
		printf("\n");
	}
}
void xuat(struct chuongtrinh a[],int n)
{
	int i;
	printf("Bai lam:\n");
	for(i=0;i<n;i++)
	{
		if(a[i].tgvao != 0 && i==0)
		{
			printf("\t 0 \n\n\t %d \n\n\t P%d \n\n\t %d\n\n",a[i].tgbd,a[i].p,a[i].tgra);
		}
		else
		{
			printf("\t %d \n\n\t P%d \n\n\t %d\n\n",a[i].tgbd,a[i].p,a[i].tgra);
		}
	}
	printf("\nKet qua: \n");
	{
		for(i=0;i<n;i++)
			printf("P%d %d %d\n",a[i].p,a[i].ta,a[i].tgcho);
	}
}
void nhapf(char *d,struct chuongtrinh a[],int n,int m)
{
	int i;
	FILE* f;
	f=fopen(d,"wt");
	if(f==NULL)
	{
		printf("Loi mo FILE!");
	}
	else
	{
		fflush(stdin);
		fprintf(f,"Numprocess: %d\n",n);
		fprintf(f,"Overhead: %d\n",m);
		for(i=0;i<n;i++)
		{
			fprintf(f,"P%d %d %d\n",a[i].p,a[i].tgvao,a[i].tglam);
		}
	}
	fclose(f);
}
void lamf(char *d,struct chuongtrinh a[],int n, int m)
{
	int i;
	FILE* f=fopen(d,"r+t");
	if(f==NULL)
	{
		printf("Loi mo FILE!");
	}
	else
	{
		fflush(stdin);
		fscanf(f,"%d%d",&n,&m);
		fscanf(f,"%d%d",&a[i].tgvao,&a[i].tglam);
		for(i=0;i<n;i++)
		{
			if(i==0)
			{
				a[i].tgbd = a[i].tgvao;
				a[i].tgra = a[i].tgvao + a[i].tglam;
				a[i].tgcho = 0;
				a[i].ta = a[i].tgra - a[i].tgvao;
			}
			else if(i>0)
			{
				a[i].tgbd=a[i-1].tgra+m;
				a[i].tgra = a[i].tgbd + a[i].tglam;
				a[i].tgcho = a[i].tgbd - a[i].tgvao;
				a[i].ta = a[i].tgra - a[i].tgvao;
			}
		}
	}
	fclose(f);
}
void xuatf(char *d,struct chuongtrinh a[],int n,int m)
{
	int i;
	FILE* f;
	f=fopen(d,"at");
	if(f==NULL)
	{
		printf("Loi mo FILE!");
	}
	else
	{
		fflush(stdin);
		fprintf(f,"\nBai lam:\n");
		for(i=0;i<n;i++)
		{
			if(a[i].tgvao != 0 && i==0)

			{
				fprintf(f,"\t 0 \n\n\t %d \n\n\t P%d \n\n\t %d\n\n",a[i].tgbd,a[i].p,a[i].tgra);
			}
			else
			{
				fprintf(f,"\t %d \n\n\t P%d \n\n\t %d\n\n",a[i].tgbd,a[i].p,a[i].tgra);
			}
		}
		fprintf(f,"\nKet qua: \n");
		for(i=0;i<n;i++)
		{
			fprintf(f,"P%d %d %d\n",a[i].p,a[i].ta,a[i].tgcho);
		}
	}
	fclose(f);
}
bool sosanh(const chuongtrinh &x,const chuongtrinh &y)
{
	return x.tgvao < y.tgvao;     
}
