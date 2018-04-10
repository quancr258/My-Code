#include<stdio.h>
#include<conio.h>
#include<string.h>
struct xe
{
	char soxe[8];
	char loaixe[15];
	xe *tiep;
};
struct canhan
{
	char MSCN[5];
 	char Hoten[30];
 	xe *xel;
 	canhan *noi;
};
canhan *daucn;
void khoitao(canhan *&daucn)
{	daucn=NULL;	}
void nhapxe(xe *&dau)
{  
    xe *p,*q;
    char soxet[8];
    do{
    	printf("nhap so xe: ");
    	fflush(stdin);
    	gets(soxet);
    	if(strcmp(soxet,"\0")!=0)
    	{
    		p=new xe;
    		strcpy(p->soxe,soxet);
    		printf("loai xe: ");
    		fflush(stdin);
    		gets(p->loaixe);
    		p->tiep=NULL;
    		if(dau==NULL)
    		   dau=p;
    		else
    		   q->tiep=p;
    		q=p;
		}
	}
	while(strcmp(soxet,"\0")!=0);
    }
void nhapdl(canhan *&daucn)
{
	canhan *p,*q;
	char MSCNt[5];
	do{
		printf("MSCN: ");
		fflush(stdin);
		gets(MSCNt);
		if(strcmp(MSCNt,"\0")!=0)
		{
			p=new canhan;
			strcpy(p->MSCN,MSCNt);
			printf("Ho ten: ");
			fflush(stdin);
			gets(p->Hoten);
			p->xel=NULL;
			p->noi=NULL;
			nhapxe(p->xel);
			if(daucn==NULL)
				daucn=p;
			else 
				q->noi=p;
			q=p;
		}
	}
	while(strcmp(MSCNt,"\0")!=0);
}
//In ra MSCN, Hoten tung nguoi
void duyetxe(xe *dau)
{
	if(dau!=NULL)
	   {
	   	printf("\n\t %s %s",dau->soxe,dau->loaixe);
	   	duyetxe(dau->tiep);
	   }
	
}
void duyetcanhan(canhan *daucn)
{
	if(daucn!=NULL)
	{
		printf("\n %s - %s",daucn->MSCN,daucn->Hoten);
		duyetxe(daucn->xel);
		duyetcanhan(daucn->noi);
	}
}
//in ra ds nhung nguoi co sd xe loai honda
int honda(xe *dau)
{
	if(dau==NULL)
	   return 0;
	else
	    if(strcmp(dau->loaixe,"Honda")==0)
	       return 1;
	    else
	       return honda(dau->tiep);
}
void duyethonda(canhan *daucn)
{
	if(daucn!=NULL)
	{
		if(honda(daucn->xel)==1)
		   printf("\n %s %s",daucn->MSCN,daucn->Hoten);
		duyethonda(daucn->noi);
	}
}
int main()
{
	khoitao(daucn);
	nhapdl(daucn);
	printf("\nDanh sach quan ly xe:\n");
	duyetcanhan(daucn);
	printf("\nnguoi co sd xe honda la:");
	duyethonda(daucn);
	return 0;
}
