#include<conio.h>
#include<stdio.h>
struct nut
{
	int gtri;
	nut *sau,*truoc;
};
typedef nut Node;
Node *dau,*q;
int i,dem;
void khoitao(Node *&dau)
{
	dau=NULL;
}
void nhapds(Node *&dau)
{
	int tam;
	Node *q,*p;
	do
	{
		printf("Nhap 1 so nguyen, dung khi nhap 0: ");
		scanf("%d",&tam);
		if(tam!=0)
		{
			p=new Node;
			p->gtri = tam;
			p->sau=NULL;
			p->truoc=NULL;
			if(dau==NULL)
				dau=p;
			else
			{
				q->sau=p;
				p->truoc=q;
			}
			q=p;
		}
	
	}
	while(tam!=0);
}
void duyetds(Node *dau)
{
	if(dau!=NULL)
  	{
  		printf("%3d",dau->gtri);
  		duyetds(dau->sau);
  	}
}
int tongdaucuoi(Node *dau)
{
	if(dau!=NULL)
	{
		if(dau->truoc == NULL || dau->sau == NULL)
			return dau->gtri + tongdaucuoi(dau->sau);
		else
			return tongdaucuoi(dau->sau);
	}
}
void xoa3(Node *&dau,Node *q,int dem)
{
	Node *p,*l;
	if(dem==1) q = NULL;
	p = dau;
	if(p!=NULL && dem == 3)
		{
			if(q!=NULL) //neu p khong phai dong 1 => q co gia tri != NULL
			{
				q->sau = p->sau;
				l = q->sau;
				delete p;
				p = l;
				p->truoc = q;
			}
			else 
			{
				dau = p->sau;
				delete p;
				dau->truoc = q;
				p = dau;
			}
		}
	else if(p!=NULL) xoa3(p->sau,q=p,dem+1);
}
int main()
{
	khoitao(dau);
	nhapds(dau);
	duyetds(dau);
	printf("\nTong gia tri nut dau va nut cuoi danh sach la: %d",tongdaucuoi(dau));
	printf("\nDanh sach sau khi Xoa nut thu 3 cua danh sach neu co:\n");
	xoa3(dau,q,1);
	duyetds(dau);
	return 0;
}
