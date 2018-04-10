#include<stdio.h>
#include<conio.h>
#include<string.h>

struct nut 
{
	int hs;
	int mu;
	nut *tiep;
};
typedef nut Node;
 Node *dau;
void khoitao(Node *&dau)
{
	dau=NULL;
}
//-------------------------
//---------------------------
void nhapdt(Node *&dau)
{
	Node *p,*q = NULL;
	int heso,lt;
	do
	{
		printf("nhap he so,0 thi dung: ");
		scanf("%d",&heso);
		if(heso!=0)
		{
			p=new Node;
			p->hs=heso;
			printf("nhap so mu ");
			scanf("%d",&lt);
			p->mu=lt;
			p->tiep=NULL;
			if (dau==NULL)
				dau=p;
			else 
				q->tiep=p;
			q=p;
		}
   }while(heso!=0);
}
//------------------------
//----------------------------
void indt(Node *dau)
{
	Node *p;
	p=dau;
  while (p!=NULL)
  {
  	if(p->tiep != NULL) printf("(%dx^%d) + ",p->hs,p->mu);
  	else printf("(%dx^%d)",p->hs,p->mu);
  	p=p->tiep;
  }
}
//------------------
//---------------------
void daoham(Node *&dau)
{
	Node *p,*q;
	
	if(dau!=NULL)
	{
		p=dau;
		q=NULL;
	while (p!=NULL)
	{
	 if(p->mu!=0)
	 {
	 	p->hs=p->hs*p->mu;
	 	p->mu=p->mu-1;
	 	q=p;
	 	p=p->tiep;
	 }
	 else
	 if(p==dau)
	 {
	 	dau=NULL;
	 	delete p;
	 }
	 else
	 {
	 	q->tiep=NULL;
	 	delete p;
	 } 
	}
	}
}
//--------------------
//-----------------------
int main()
{
	khoitao(dau);
	//----------------------
	nhapdt(dau);
	//-----------------------
	indt(dau);
	//-----------------
	daoham(dau);
	//-------------------
	printf("\nPhuong trinh dao ham la:\n");
	indt(dau);
	//-------------------
	getch();
	return 0;
}
