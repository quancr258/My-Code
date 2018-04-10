#include<iostream>
#include<conio.h>
#include<algorithm>
#define MAX 100
using namespace std;
struct chuongtrinh
{
	int tgvao,tgxuli,ut;
	int tgbd,tgra,wt,ta;
	char *tentt;
	/* Chu thich (theo moi tien trinh)
	tgvao: thoi gian vao
	tgxuli: thoi gian xu li
	ut: do uu tien
	tgbd: thoi gian bat dau thuc hien
	tgra: thoi gia ra
	wt: thoi gian cho
	ta: thoi gian o trong RL (TurnAround time)
	*/
}a[MAX];
void docfile(chuongtrinh a[],int &n,int &m,int &q);
bool sxSJF(const chuongtrinh &x,const chuongtrinh &y);
void SJF(chuongtrinh a[],int n, int m,int &TBwt);
void sodo(chuongtrinh a[],int i,int m);
void ghifile(chuongtrinh a[],int n, int m,int TBwt);
int maint()
{
	int n,m,q;
	int TBSJFwt = 0;
	/* Chu thich
	n: So tien trinh
	m: overhead
	q: quantum
	TBSJFwt: thoi gian cho trung binh cua ca qua trinh SJF
	*/
	docfile(a,n,m,q);
	SJF(a,n,m,TBSJFwt);
	ghifile(a,n,m,TBSJFwt);
	return 0;
}
//doc du lieu tu file Input.txt
void docfile(chuongtrinh a[],int &n,int &m,int &q)
{
	FILE *f=fopen("Input.txt","rt");
	if(f==NULL)
	{
		printf("Loi Mo File!! YEU CAU KIEM TRA FILE Input.txt");
	}
	else
	{
		fflush(f);
		fscanf(f,"%d",&n);
		fscanf(f,"%d",&m);
		fscanf(f,"%d",&q);
		for(int i=1;i<=n;i++)
		{
			fscanf(f,"%s",&a[i].tentt);
			fscanf(f,"%d",&a[i].tgvao);
			fscanf(f,"%d",&a[i].tgxuli);
			fscanf(f,"%d",&a[i].ut);
		}
	}
	fclose(f);
}
//Ham sap xep du lieu theo SJF (theo tgxuli)
bool sxSJF(const chuongtrinh &x,const chuongtrinh &y)
{
	return x.tgxuli < y.tgxuli;
}
//xu li du lieu theo SJF
void SJF(chuongtrinh a[],int n, int m,int &TBSJFwt)
{
	int i;
	FILE *f=fopen("Input.txt","rt");
	if(f!=NULL)
	{
		fflush(f);
		int Twt = 0; //tong thoi gian cho cua ca qua trinh
		sort(a,a+n,sxSJF); //sap xep du lieu theo SJF (theo tgxuli)
		for(i=1;i<=n;i++)
		{
			if(i==0)
			{
				a[i].tgbd = a[i].tgvao;
				a[i].wt = 0;
			}
			else if(i>0)
			{
				a[i].tgbd=a[i-1].tgra + m;
				a[i].wt = a[i].tgbd - a[i].tgvao;
			}
			a[i].tgra = a[i].tgbd + a[i].tgxuli;
			a[i].ta = a[i].tgra - a[i].tgvao;
			Twt += a[i].wt;
		}
		TBSJFwt = Twt*1.0/n;
	}
	fclose(f);
}
//ham ve so do gant
void sodo(FILE* f,chuongtrinh a[],int i,int m)
{
	int j;
	if(i==1)
	{
		//Ve so do cho tien trinh dau tien
		if(a[i].tgbd!=0)
		{
			fprintf(f,"0");	
			for(j=1;j<=a[i].tgbd;j++)
			{
				fprintf(f,"=");
			}
		}
		fprintf(f,"%d",a[i].tgbd);
		for(j=1;j<=a[i].tgxuli;j++)
		{
			if(i==a[i].tgxuli/2)
				fprintf(f,"%s",a[i].tentt);
			fprintf(f,"=");
		}
	}
	else
	{
		//Ve so do cho cac tien trinh tiep theo
		for(j=1;j<=m;j++)
		{
			fprintf(f,"=");
		}
		fprintf(f,"%d",a[i].tgbd);
		for(j=1;j<=a[i].tgxuli;j++)
		{
			if(i==a[i].tgxuli/2)
				fprintf(f,"%s",a[i].tentt);
			fprintf(f,"=");
		}
	}
	fprintf(f,"%d",a[i].tgra);
}
//ghi ket qua vao file Output.txt
void ghifile(chuongtrinh a[],int n, int m,int TBSJFwt)
{
	int i;
	FILE *f=fopen("Output.txt","wt");
	if(f!=NULL)
	{
		fflush(f);
		//Ve so do gant
		for(i=1;i<=n;i++)
			sodo(f,a,i,m);
		//In ket qua theo 3 muc sau
		fprintf(f,"\nTen tien trinh | Thoi gian WT | Thoi gian TA\n");
		for(i=1;i<=n;i++)
		{
			fprintf(f,"%15s%14d%13d\n",a[i].tentt,a[i].wt,a[i].ta);
		}
		//In ket qua thoi gian cho trung binh cua qua trinh SJF
		fprintf(f,"Thoi gian cho trung binh cua qua trinh SJF: %d",TBSJFwt);
	}
	fclose(f);
}
