#include<stdio.h>
#include<conio.h>
#include<string.h>

   struct nut
   {
   	int gtri;
   	nut *tiep;
   };
   typedef nut Node;
   Node *dau;
void khoitao(Node *&dau)
{
	dau=NULL;
}
//-------------------------
//--------------------------
void nhapds(Node *&dau)
{
	int tam;
	Node *p,*q;
	do
	{
		printf("nhap vao so nguyen,0,dung:");
		scanf("%d",&tam);
		if(tam!=0)
		{
			p=new Node;
			p->gtri=tam;
			p->tiep=NULL;
		if(dau==NULL)
		{
			dau=p;
		}
		else
		{
			q->tiep=p;
		}
		  q=p;
		}
	}
	while (tam!=0);
}
//---------------
//-------------------
void duyetdequy(Node *dau)
{
	if(dau!=NULL)
	{
		printf("%d",dau->gtri);
		duyetdequy(dau->tiep);
	}
}
//--------------------
//----------------------------
void xoa(Node *&dau)//xoa nut truoc nut cuoi
{
	Node *p,*q,*t;
	q=NULL;
	t=NULL;
	p=dau;
	if(p!=NULL)
  {
		p=dau;
	while(p->tiep!=NULL)
	{
    	q=t;
    	t=p;
    	p=p->tiep;
     }
	if(t!=NULL)
	{
		if(t==dau)
		{
	    dau=dau->tiep;
	    delete t;
	    }
	
	else
	 {
			q->tiep=p;
		delete t;
	 } 
	}
  }
}
//------------------------
//---------------------------
int tong(Node *dau)//tinh tong cac  nut co so thu  tu le 
{
 int stt;
	Node *p;
 int tong=0;
	p=dau;
	stt=1;
 while (p!=NULL) 
 {
 	if (stt%2!=0)
 		tong+=1;
 	p=p->tiep;
 	stt+=1;
 	
 }
  return tong;
 }
	
int main()
{
	khoitao(dau);
	//---------------------
	nhapds(dau);
	//-------------------
	duyetdequy(dau);
	printf("\n");
	//---------------
	printf("danh sach vua duoc xoa nut truoc nut cuoi :\n");
	xoa(dau);
	duyetdequy(dau);
	printf("\n");
	//-------------------------
	printf("tong cac nut co so thu  tu le la:\n%d",tong(dau));
	//----------------------------
	getch();
	return 0;
}







