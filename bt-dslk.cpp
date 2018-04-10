#include<conio.h>
#include<stdio.h>
#include<string.h>

  struct nut
  {
  	int gtri;
  	nut *tiep ;
  };
  	typedef nut Node;
  	Node *dau;
void khoitao(Node *&dau)
   {
	dau=NULL;
	}
	//--------------------
	//-----------------------
void nhapds(Node *&dau)
{
     int tam;
     Node *p,*q;
     do
	 {
	 	printf("nhap so nguyen,0:dung: ");
	 	scanf("%d",&tam);
	 	if(tam!=0) 
	   {
	 		p=new Node;
	 	    p->gtri=tam;
	 		p->tiep =NULL;
	 		
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
  //--------------------------
  //----------------------------
  void duyetdequy(Node *dau)
  {
  	if(dau!=NULL)
  	{
  		printf("%3d",dau->gtri);
  		
  		duyetdequy(dau->tiep);
  	}
  }
  //-------------
  //----------------
  void sapxep(Node *&dau)
  {
  	Node *p,*q;
  	int tam;
  	p=dau;
  	while (p->tiep!=NULL)
   {
  	   q=p->tiep;
  	while (q!=NULL)
     {
  		if(q->gtri<p->gtri)
  		{
  			tam=p->gtri;
  			p->gtri=q->gtri;
  				q->gtri=tam;
  			
  		}
  		   	q=q->tiep;
      }
      	p=p->tiep; 
   }
  }
  //-----------------------
  //-----------------------
  void chendau(Node *&dau,int x)
  { 
      Node *p;
      p=new Node;
      p->gtri=x;
      p->tiep=dau;
      dau=p;
  }
  	//--------------
  	//----------------
void chencuoi(Node *&dau,int y)
  	{
  		Node *p,*q;
  		p=dau;
  		while(p->tiep!=NULL)
  			p=p->tiep;
  			q=new Node;
  			q->gtri=y;
  			q->tiep=NULL;
  			p->tiep=q;
  	}
  	//---------------
  	//----------------------
void chen_xvaotruoc_y(Node *&dau,int z,int v)
{
	Node *p,*q,*t;
	q=NULL;
	p=dau;
  while ((p!=NULL)&&(p->gtri!=v))
   {
   	q=p;
    p=p->tiep;
   } 
  if(p!=NULL)
  if(p==dau)
	{
		chendau(dau,z);
    }
  else
  {
  	t=new Node;
  	t->gtri=z;
  	t->tiep=p;
  	q->tiep=t;
  }
}
  //----------------
  //----------------------
void xoatruocx(Node *&dau,int k)
{
	Node *p,*q,*t;
	q=NULL;
	t=NULL;
	p=dau;
  while((p!=NULL)&&(p->gtri!=k))
    {
    	q=t;
    t=p;
    p=p->tiep;
    }
  if(p!=NULL)
  if(p!=dau)
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
 //----------------------
 //---------------------------
 void xoatrung(Node *&dau)
 {
 	Node *p,*q;
 	  p=dau;
 	  q=p->tiep;
 	while (q!=NULL)
 	{
 		if(p->gtri==q->gtri)
 		{
 			p->tiep=q->tiep;
 			delete q;
 			q=p->tiep;
 		}
 		else
 		{
 			p=p->tiep;
 			q=q->tiep;
 		}
 	}
 }
 //------------------------
 //------------------------------
 void daonguocds(Node *&dau)
 {
 	Node *p,*q;
 	p=NULL;
 	q=NULL;
  while (dau!=NULL)
 	{
 		p=dau;
 		dau=dau->tiep;
 		p->tiep=q;
 		q=p;
 	}
 	  dau=p;
}
  //=======================
  //=========================
  void doicho(Node *&dau)//doi cho nut dau va nut cuoi cho nhau
  {  int tam;
  		Node *p;
  		if(dau!=NULL)
  		{
  				p=dau;
  	while (p->tiep!=NULL)
  		p=p->tiep;	
  	if (dau!=p)
  	{
  		tam=dau->gtri;
  	dau->gtri=p->gtri;
  	p->gtri=tam;
  	}
  	
  		}
}
  //---------------------------------
  //----------------------------------------
  	
  int main()
  {  
       int x,k;
       int y,z,v;
  	khoitao(dau);
  	nhapds(dau);
  	//----------------
  	printf("day so da duoc nhap vao:\n");
  	duyetdequy(dau);
  	printf("\n");
  	//----------------------
  	printf("day so da duoc sap xep:\n");
  	sapxep(dau);
  	duyetdequy(dau);
  	printf("\n");
  	//------------------------
  	printf("nhap so can chen dau:\n");
  	scanf("%d",&x);
  	chendau(dau,x);
  	printf("day da duoc chen dau:\n");
  	duyetdequy(dau);
  	printf("\n");
  	//-------------------------
	printf("nhap so can chen cuoi:\n");
  	scanf("%d",&y);
  	printf("day cua chen cuoi la\n");
  	chencuoi(dau,y);
  	duyetdequy(dau);
  	printf("\n");
  	//---------------
  	
  	printf("nhap so can tim de chen truoc:\n");
  	scanf("%d",&v); 
  	printf("nhap vao so can chen truoc %d\n",v) ;
    scanf("%d",&z);
    printf("day vua duoc chen la\n");
	chen_xvaotruoc_y(dau,z,v);
	duyetdequy(dau);
	printf("\n");
	//----------------------------
	printf("nhap vao so can tim de xoa so truoc no\n");
	scanf("%d",&k);
	printf(" day da xoa nut dung truoc %d\n",k);
	xoatruocx(dau, k);
	duyetdequy(dau);
	printf("\n");
    //----------------------------
    printf("day da duoc xoa cac so trung nhau\n");
    xoatrung(dau);
    duyetdequy(dau);
    printf("\n");
    //------------------------
    printf("day duoc dao nguoc la :\n");
    daonguocds(dau);
    duyetdequy(dau);
    printf("\n");
  	//----------------------------
  	printf("danh sach da duoc doi cho la \n");
  	doicho(dau);
  	duyetdequy(dau);
	printf("\n");
  	
  	
  	getch();
  	return 0;
  }
