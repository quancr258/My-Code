#include<stdio.h>
#include<conio.h>
struct tientrinh
{
	int tgvao;
	int tgxl;
	int wt;
};
void doc(char *s,int &n,tientrinh a[])
{
	FILE *fp=fopen(s,"rt");
	fscanf(fp,"%d\n",&n);
	for (int i=0;i<n;i++)
	{
		fscanf(fp,"%d%d",&a[i].tgvao,&a[i].tgxl);
	};
	fclose(fp);
	printf("%d\n",n);
	for (int i=0;i<n;i++)
	{
		printf("%d %d\n",a[i].tgvao,a[i].tgxl);
	};
}
int xuli(tientrinh a[],int n,float &s)
{
	s=0;
	int t=0;
	for (int i=1;i<n;i++)
	{	
		t=t+a[i-1].tgxl;
		a[i].wt=t-a[i].tgvao;
		s=s+a[i].wt;
	};
	s=s/float(n);
}
void ghi(char *s,float c)
{
	FILE *fp=fopen(s,"wt");
	fprintf(fp,"%f",c);
}	
int main()
{
	int n;
	float s;
	tientrinh a[100];
	doc("D:\\DevC++\\Bai Tap\\FIFO huynh phuong ngoc.txt",n,a);
	xuli(a,n,s);
	ghi("D:\\DevC++\\Bai Tap\\FIFO huynh phuong ngoc.txt",s);
}
