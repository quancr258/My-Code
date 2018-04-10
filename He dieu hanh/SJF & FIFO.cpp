#include<iostream>
#include<conio.h>
#include<algorithm>
#define MAX 100
using namespace std;
struct chuongtrinh
{
	int tgvao,tgxuli,ut;
	int tgbd,tgra,wt,ta;
	char tentt[10];
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
void khoitao(chuongtrinh a[]);
void docfile(chuongtrinh a[],int &n,int &m,int &q);
bool sxSJF(const chuongtrinh &x,const chuongtrinh &y);
void FIFO(chuongtrinh a[],int n, int m,float &TBwt);
void SJF(chuongtrinh a[],int n, int m,float &TBwt);
void sodo(chuongtrinh a[],int i,int m);
void ghifile(chuongtrinh a[],int n, int m,char t[],float TBwt);
int main()
{
	int n,m,q;
	float TBwt = 0;
	char t[10];
	chuongtrinh tam[MAX];
	int o;
	/* Chu thich
	n: So tien trinh
	m: overhead
	q: quantum
	TBwt: thoi gian cho trung binh cua ca qua trinh SJF
	t: Ten chuong trinh thuc hien
	o: tgra cua tien trinh truoc do trong RR
	*/
	khoitao(a);
	FILE *f=fopen("Output.txt","wt");
	docfile(a,n,m,q);
	FIFO(a,n,m,TBwt);
	ghifile(a,n,m,"FIFO",TBwt);
	SJF(a,n,m,TBwt);
	ghifile(a,n,m,"SJF",TBwt);
	printf("\nChuong trinh hoat tat!! Vui long kiem tra file Output.txt");
	return 0;
}
//Khoi tao gia tri dau
void khoitao(chuongtrinh a[])
{
	a[0].tgbd=0;a[0].tgra=0;a[0].tgvao=0;a[0].tgxuli=0;a[0].ut=0;
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
		//doc n,m,q
		fscanf(f,"%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++)
		{
			//doc cac thong so vao cua tung tien trinh
			fscanf(f,"%s%d%d%d",&a[i].tentt,&a[i].tgvao,&a[i].tgxuli,&a[i].ut);
		}
	}
	fclose(f);
}
//Ham sap xep du lieu theo FIFO (theo tgvao)
bool sxFIFO(const chuongtrinh &x,const chuongtrinh &y)
{
	return x.tgvao < y.tgvao;
}
//Ham sap xep du lieu theo SJF (theo tgxuli)
bool sxSJF(const chuongtrinh &x,const chuongtrinh &y)
{
	return x.tgxuli < y.tgxuli;
}
//xu li du lieu theo FIFO
void FIFO(chuongtrinh a[],int n, int m,float &TBwt)
{
	int i;
	FILE *f=fopen("Input.txt","rt");
	if(f!=NULL)
	{
		fflush(f);
		int Twt = 0; //tong thoi gian cho cua ca qua trinh theo FIFO
		sort(a+1,a+1+n,sxFIFO); //sap xep du lieu theo FIFO (theo tgvao)
		for(i=1;i<=n;i++)
		{
			if(i==1)
			{
				a[i].tgbd = a[i].tgvao;
				a[i].wt = 0;
			}
			else if(i>1)
			{
				a[i].tgbd=a[i-1].tgra + m;
				a[i].wt = a[i].tgbd - a[i].tgvao;
			}
			a[i].tgra = a[i].tgbd + a[i].tgxuli;
			a[i].ta = a[i].tgra - a[i].tgvao;
			Twt += a[i].wt;
		}
		TBwt = Twt*1.0/n;
	}
	fclose(f);
}
//xu li du lieu theo SJF
void SJF(chuongtrinh a[],int n, int m,float &TBwt)
{
	int i;
	FILE *f=fopen("Input.txt","rt");
	if(f!=NULL)
	{
		fflush(f);
		int Twt = 0; //tong thoi gian cho cua ca qua trinh theo SJF
		sort(a+1,a+1+n,sxSJF); //sap xep du lieu theo SJF (theo tgxuli)
		for(i=1;i<=n;i++)
		{
			if(i==1)
			{
				a[i].tgbd = a[i].tgvao;
				a[i].wt = 0;
			}
			else if(i>1)
			{
				a[i].tgbd=a[i-1].tgra + m;
				a[i].wt = a[i].tgbd - a[i].tgvao;
			}
			a[i].tgra = a[i].tgbd + a[i].tgxuli;
			a[i].ta = a[i].tgra - a[i].tgvao;
			Twt += a[i].wt;
		}
		TBwt = Twt*1.0/n;
	}
	fclose(f);
}
//ham ve so do gantt
void sodo(FILE* f,chuongtrinh a[],int i,int m)
{
	int j;
	if(i==1)
	{
		//Ve so do cho tien trinh dau tien
		if(a[i].tgbd!=0)
		{
			fprintf(f," 0 ");	
			for(j=1;j<=a[i].tgbd;j++)
			{
				fprintf(f," = ");
			}
		}
		fprintf(f," %d ",a[i].tgbd);
		for(j=1;j<=a[i].tgxuli;j++)
		{
			if((j==a[i].tgxuli/2 && a[i].tgxuli%2==0) || (j==((a[i].tgxuli/2)+1) && a[i].tgxuli%2!=0))
				fprintf(f," %s ",a[i].tentt);
			else fprintf(f," = ");
		}
	}
	else
	{
		//Ve so do cho cac tien trinh tiep theo
		for(j=1;j<m;j++)
		{
			fprintf(f," = ");
		}
		fprintf(f," %d ",a[i].tgbd);
		for(j=1;j<=a[i].tgxuli;j++)
		{
			if((j==a[i].tgxuli/2 && a[i].tgxuli%2==0) || (j==((a[i].tgxuli/2)+1) && a[i].tgxuli%2!=0))
				fprintf(f," %s ",a[i].tentt);
			else fprintf(f," = ");
		}
	}
	fprintf(f," %d ",a[i].tgra);
}
//ghi ket qua vao file Output.txt
void ghifile(chuongtrinh a[],int n, int m,char t[],float TBwt)
{
	int i;
	FILE *p=fopen("Input.txt","rt");
	FILE *f=fopen("Output.txt","at");
	if(p==NULL) fprintf(f,"Loi Mo File!! YEU CAU KIEM TRA FILE Input.txt");
	else
	{
		fflush(f);
		fprintf(f,"-----------------------------------------\n");
		fprintf(f,"***Bai lam %s:\n",t);
		//Ve so do gant
		for(i=1;i<=n;i++)
			sodo(f,a,i,m);
		//In ket qua theo 3 muc sau
		fprintf(f,"\nTen tien trinh | Thoi gian WT | Thoi gian TA\n");
		for(i=1;i<=n;i++)
		{
			fprintf(f,"%10s%15d%15d\n",a[i].tentt,a[i].wt,a[i].ta);
		}
		//In ket qua thoi gian cho trung binh cua qua trinh SJF
		fprintf(f,"Thoi gian cho trung binh cua qua trinh %s: %f\n",t,TBwt);
	}
	fclose(f);
}
