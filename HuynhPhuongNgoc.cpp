#include<stdio.h>
#include<conio.h>
#include<algorithm>
using namespace std;
#define MAX 100
struct chuongtrinh
{ 
	char tentientrinh[3];
	int tgbd,tgvao,tgxuli,tgra, douutien,tgTA,tgWT;
}fifo[MAX];
 void xulififo(chuongtrinh fifo[], int sotientrinh,int overhead);
 bool sosanh(const chuongtrinh &x,const chuongtrinh &y);
int main()
 {
 	int sotientrinh, quantum, overhead;
 	{
 	int i;
 	FILE*HPN=fopen("input.txt","rt");
 	if(HPN==NULL)
 		printf("khong the doc file");
 	else
 	{
 		fscanf(HPN,"%d",&sotientrinh);
 		fscanf(HPN,"%d",&overhead);
 		fscanf(HPN,"%d",&quantum);
 		for(i=0; i<sotientrinh;i++)
 		{
 			fscanf(HPN,"%s",&fifo[i].tentientrinh);
 			fscanf(HPN,"%d",&fifo[i].tgvao);
 			fscanf(HPN,"%d",&fifo[i].tgxuli);
 			fscanf(HPN,"%d",&fifo[i].douutien);
 		}
 		printf("da doc xong\n");
 	}
 	fclose(HPN);
 	}	
 	sort(fifo,fifo+sotientrinh,sosanh);
 	xulififo(fifo,sotientrinh,overhead);	
 }
 void xulififo(chuongtrinh fifo[], int sotientrinh,int overhead)
  {
 	FILE* HPN;
 	if((HPN=fopen("output.txt","wt"))==NULL)
 		printf("Khong the tao file");
 	else
	 {
	 	//Ve bieu do
	 	printf("so tien trinh: %d\n",sotientrinh);
	 	fprintf(HPN,"so tien trinh: %d\n",sotientrinh);
	 	for(int i=0;i<sotientrinh;i++)
		 {
		 	int tongtgdungcpu=0;
		 	tongtgdungcpu+=fifo[i].tgxuli;
		 	printf("ten tien trinh: %s\n",fifo[i].tentientrinh);
			printf("tong tg dung cpu cua tien trinh %s: %d\n",fifo[i].tentientrinh,tongtgdungcpu);
		 	fprintf(HPN,"ten tien trinh: %s\n",fifo[i].tentientrinh);
		 	fprintf(HPN,"tong tg dung cpu cua tien trinh %s: %d\n",fifo[i].tentientrinh,tongtgdungcpu);
		 }
 		printf("\n");
 // Tinh TA cua tung tien trinh
 for(int i=0;i<sotientrinh;i++)
 {
 		if(i==0)
			{
				fifo[i].tgbd = fifo[i].tgvao;
				fifo[i].tgra = fifo[i].tgvao + fifo[i].tgxuli;
				fifo[i].tgWT = 0;
				fifo[i].tgTA = fifo[i].tgra - fifo[i].tgvao;
			}
			else if(i>0)
			{
				fifo[i].tgbd = fifo[i-1].tgra + overhead;
				fifo[i].tgra = fifo[i].tgbd + fifo[i].tgxuli;
				fifo[i].tgWT = fifo[i].tgbd - fifo[i].tgvao;
				fifo[i].tgTA = fifo[i].tgra - fifo[i].tgvao;
			}
 }
 printf("Ve bieu do:\n");
 fprintf(HPN,"Ve bieu do:\n");
 for(int i=0;i<sotientrinh;i++)
		{
			if(fifo[i].tgvao != 0 && i==0)

			{
				printf("\t 0 \n\n\t %d \n\n\t %s \n\n\t %d\n\n",fifo[i].tgbd,fifo[i].tentientrinh,fifo[i].tgra);
				fprintf(HPN,"\t 0 \n\n\t %d \n\n\t %s \n\n\t %d\n\n",fifo[i].tgbd,fifo[i].tentientrinh,fifo[i].tgra);
			}
			else
			{
				printf("\t %d \n\n\t %s \n\n\t %d\n\n",fifo[i].tgbd,fifo[i].tentientrinh,fifo[i].tgra);
				fprintf(HPN,"\t %d \n\n\t %s \n\n\t %d\n\n",fifo[i].tgbd,fifo[i].tentientrinh,fifo[i].tgra);
			}
		}
//xuat TA & Wt ra man hinh & file
printf("\n\t Bang gia tri\n");
fprintf(HPN,"\n\t Bang gia tri \n");
printf("Tien trinh \t TA \t WT \n");
fprintf(HPN,"Tien trinh \t TA \t WT \n");
for(int i=0;i<sotientrinh;i++)
{
	printf("%5s",fifo[i].tentientrinh);
	fprintf(HPN,"%5s",fifo[i].tentientrinh);
	printf("\t\t%3d",fifo[i].tgTA);
	fprintf(HPN,"\t\t%3d",fifo[i].tgTA);
	printf("\t%3d",fifo[i].tgWT);
	fprintf(HPN,"\t%3d",fifo[i].tgWT);
	printf("\n");
	fprintf(HPN,"\n");		
}
//tg cho trung binh
int tongWT=0;
float tgWTtb=0;
for(int i=0;i<sotientrinh;i++)
{
	tongWT+=  fifo[i].tgWT;
}
tgWTtb=float(tongWT)/sotientrinh;
printf("\nThoi gian cho trung binh = %2f",tgWTtb);
fprintf(HPN,"\nThoi gian cho trung binh = %2f",tgWTtb);
printf("\n Ghi file hoan tat!");
}
}
bool sosanh(const chuongtrinh &x,const chuongtrinh &y)
{
	return x.tgvao < y.tgvao;     
}

