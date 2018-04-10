#include <iostream>
#include <conio.h>
using namespace std;
struct nut
{
	int gtri;
	nut *tiep;
};
typedef nut Node;
Node *dau;
void khoitao(Node *&dau);
void nhapds(Node *&dau);
void duyetds(Node *dau);
void nhapx(int x,Node *&p);
void sapxep(Node *&dau);
void chendau(Node *&dau,int x);
void chencuoi(Node*&dau, int x);
void chentt(Node *&dau,int x);
void xoadau(Node *&dau);
void xoacuoi(Node *&dau);
void xoax(Node *&dau,int x);
void xoatruocx(Node *&dau,int x);
void xoatrung(Node *&dau);
void daonguoc(Node *&dau);
int main()
{
	char t[5];
	int x;
	khoitao(dau);
	nhapds(dau);
	duyetds(dau);
	printf("\n----------sap xep danh sach-----------\n");
	sapxep(dau);
	duyetds(dau);
	printf("Ban co muon them nut x hay khong? (c/k): ");
	scanf("%s",&t[0]);
	if(t[0]=='c')
	{
		printf("Nhap x: x = ");
		scanf("%d",&x);
		printf("\n----------chen x vao dau danh sach-----------\n");
		chendau(dau,x);
		duyetds(dau);
		printf("\n----------chen x vao cuoi danh sach-----------\n");
		chencuoi(dau,x);
		duyetds(dau);
		printf("----------chen x khong thay doi thu tu danh sach-----------\n");
		chentt(dau,x);
		duyetds(dau);
		printf("----------xoa nhung nut co gia tri trung nhau-----------\n");
		xoatrung(dau);
		duyetds(dau);
		printf("----------xoa truoc x-----------\n");
		xoatruocx(dau,x);
		duyetds(dau);
		printf("----------xoa x-----------\n");
		xoax(dau,x);
		duyetds(dau);
	}
	else
	{
		printf("----------xoa nhung nut co gia tri trung nhau-----------\n");
		xoatrung(dau);
		duyetds(dau);
	}
	printf("----------xoa dau-----------\n");
	xoadau(dau);
	duyetds(dau);
	printf("----------xoa cuoi-----------\n");
	xoacuoi(dau);
	duyetds(dau);
	printf("\n----------sap xep lai danh sach-----------\n");
	sapxep(dau);
	duyetds(dau);
	printf("----------dao nguoc danh sach-----------\n");
	daonguoc(dau);
	duyetds(dau);
}
//Khoi tao gia tri ban dau cho danh sach
void khoitao(Node *&dau)
{
	dau = NULL;
}
//Khoi tao 1 danh sach moi
void nhapds(Node *&dau)
 {
    int tam; 
    Node *p, *q;
    do
	{
		printf("Nhap 1 so nguyen (0:dung): ");
        scanf("%d",&tam);
        if (tam!=0)
		{
			p= new Node;
            p->gtri=tam; p->tiep=NULL;
            if  (dau==NULL)   
				dau=p;
            else     
			q->tiep= p;
            q=p; 
		} 
	}  
	while (tam!=0);  
}
//Duyet va in ra danh sach
void duyetds(Node *dau)
{
	if(dau != NULL)
	{
		printf("%5d",dau->gtri);
		duyetds(dau->tiep);
	}
	printf("\n");
}
//Tao bien x
void nhapx(int x,Node *&p)
{
	p=new Node;
	p->gtri=x;
	p->tiep=NULL;
}
// Ham sap xep 
void sapxep(Node *&dau)
{
	Node *p, *q;
	int tam;
	p = dau;
	while (p -> tiep != NULL)
	{
		q = p -> tiep;
		while (q != NULL)
		{
		 	if (q -> gtri < p ->gtri)
		 	{
		 		tam = q -> gtri;
				 q -> gtri = p -> gtri;
				 p -> gtri = tam;	
			}
			q = q -> tiep;
		}	
		p = p -> tiep;
	}
}
//Chen x vao dau danh sach
void chendau(Node *&dau,int x)
{
	Node *p;
	nhapx(x,p);
	p->tiep=dau;
	dau=p;
}
// Chen x vao cuoi danh sach
void chencuoi(Node*&dau, int x)
{
	Node *p, *q;
	nhapx(x,p);
	q = dau;
	while (q -> tiep != NULL)
	 q = q -> tiep;
	 q -> tiep = p;
}
//Chen x vao danh sach sao cho van giu thu tu sap xep
void chentt(Node *&dau,int x)
{
	if ((dau == NULL) || (dau->gtri >= x))
		chendau(dau,x);
	else
		chentt(dau->tiep,x);
}
//Xoa nut dau cua danh sach
void xoadau(Node *&dau)
{
	Node *p;
	if(dau!=NULL)
	{
		p=dau;
		dau=dau->tiep;
		delete p;
	}
}
//Xoa nut cuoi cua danh dach
void xoacuoi(Node *&dau)
{
	Node *p,*q;
	if(dau!=NULL)
	{
		p=dau;q=NULL;
		while(p->tiep!=NULL)
		{
			q=p;
			p=p->tiep;
		}
		if(p==dau) xoadau(dau);
		else
		{
			q->tiep=NULL;
			delete p;
		}
	}
}
//Xoa nut mang gia tri la x
void xoax(Node *&dau,int x)
{
	Node *p,*q;
	if(dau!=NULL)
	{
		p=dau;q=NULL;
		while(p->gtri!=x && p!=NULL)
		{
			q=p;
			p=p->tiep;
		}
		if(p!=NULL)
		{
			if(p==dau) xoadau(dau);
			else
			{
				q->tiep = p->tiep;
				delete p;
			}
		}
	}
}
//xoa nut dung truoc nut mang gia tri la x
void xoatruocx(Node *&dau,int x)
{
	Node *p,*q,*l;
	if(dau!=NULL)
	{
		p=dau;q=NULL;l=NULL;
		while(p->gtri!=x && p!=NULL)
		{
			l=q;q=p;
			p=p->tiep;
		}
		if(p!=NULL)
		{
			if(p!=dau)
			{
				if(q==dau) xoadau(dau);
				else
				{
					l->tiep=p;
					delete l;
				}
			}
		}
	}
}
//xoa cac nut trung nhau
void xoatrung(Node *&dau)
{
	Node *p,*q;
	if(dau!=NULL)
	{
		p=dau;q=p->tiep;
		while(q!=NULL)
		{
			if(q->gtri==p->gtri)
			{
				p->tiep=q->tiep;
				delete q;
				q=p->tiep;
			}
			else
			{
				p=q;
				q=q->tiep;
			}
		}
	}
}
//ham dao nguoc danh sach
void daonguoc(Node *&dau)
{
	Node *p,*q;
	if(dau!=NULL)
	{
		q=NULL;p=dau;
		while(p!=NULL)
		{
			dau=dau->tiep;
			p->tiep=q;
			q=p;
			p=dau;
		}
		dau=q;
	}
}
