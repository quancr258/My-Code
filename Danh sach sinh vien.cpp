#include<stdio.h>
#include<conio.h>
#include<string.h>
struct nut
{
	char MSSV[9];
	char Holot[30],Ten[10];
	float d1,d2,d3;
	int vthu;
	nut *tiep;
};
typedef nut Node;
Node *dau;
void khoitao(Node *&dau)
{
	dau = NULL;
}
void taods(Node *&dau)
{
	Node *p,*q;
	char tam[30];
	do
	{
		printf("Nhap MSSV, 0 = OUT : ");
		scanf("%s",&tam);
		if(strcmp(tam,"0")!=0)
		{
			p = new Node;
			fflush(stdin);
			strcpy(p->MSSV,tam);
			printf("Nhap Ho lot: ");
			scanf("%s",&tam);
			fflush(stdin);
			strcpy(p->Holot,tam);
			printf("Nhap Ten: ");
			fflush(stdin);
			scanf("%s",&tam);
			strcpy(p->Ten,tam);
			printf("Nhap diem 3 mon: ");
			scanf("%f%f%f",&p->d1,&p->d2,&p->d3);
			if(dau==NULL)
				dau = p;
			else
				q->tiep = p;
			q = p;
		}
	}
	while(strcmp(tam,"0")!=0);
}
void duyetds(Node *dau)
{
	if(dau!=NULL)
	{
		printf("\n");
		puts(dau->MSSV); 
		puts(dau->Holot); 
		puts(dau->Ten); 
		printf("%3.3f ; %3.3f ; %3.3f",dau->d1,dau->d2,dau->d3);
		duyetds(dau->tiep);
	}
}
void sapxep(Node *&dau)
{
	Node *p,*q;
	char tMSSV[9],tHolot[30],tTen[10];
	float td1,td2,td3;
	if(dau!=NULL)
	{
		p = dau;
		while(p->tiep!=NULL)
		{
			q=p->tiep;
			while(q!=NULL)
			{
				if((q->d1+q->d2+q->d3)/3>(p->d1+p->d2+p->d3)/3)
				{
					strcpy(tMSSV,p->MSSV);
					strcpy(tHolot,p->Holot);
					strcpy(tTen,p->Ten);
					td1=p->d1;td2=p->d2;td3=p->d3;
					strcpy(p->MSSV,q->MSSV);
					strcpy(p->Holot,q->Holot);
					strcpy(p->Ten,q->Ten);
					p->d1=q->d1;p->d2=q->d2;p->d3=q->d3;
					strcpy(q->MSSV,tMSSV);
					strcpy(q->Holot,tHolot);
					strcpy(q->Ten,tTen);
					q->d1=td1;q->d2=td2;q->d3=td3;
				}
				q=q->tiep;
			}
			p=p->tiep;
		}
	}
}
/*void vithu(Node *dau)
{
	Node *p,*q;
	int vt=1,dem=1;
	if(dau!=NULL)
	{
		p = dau;
		p->vthu = vt; dem++;
		while(p->tiep != NULL)
		{
			q=p;
			p=p->tiep;
			while(p!=NULL)
			{
				if((q->d1+q->d2+q->d3)/3 != (p->d1+p->d2+p->d3)/3)
					vt = dem;
				p->vthu = vt;
			}
			dem++;
		}
	}
}*/
void vithu(Node *&dau)
{
	int vt = 1;
	int dem = 0;
	float DTB = (dau->d1+dau->d2+dau->d3)/3;
	Node *p;
	p = dau;
	while(p!=NULL)
	{
		if((p->d1+p->d2+p->d3)/3==DTB)
		{
			p->vthu = vt;
			dem++;
		}
		else
		{
			vt = vt +dem;dem=1;
			DTB=((p->d1+p->d2+p->d3)/3);
			p->vthu=vt;
		}
		p=p->tiep;
	}
}
int main()
{
	khoitao(dau);
	taods(dau);
	duyetds(dau);
	sapxep(dau);
	vithu(dau);
}
