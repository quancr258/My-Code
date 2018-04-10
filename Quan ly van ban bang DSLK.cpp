#include<stdio.h>
#include<string.h>
#include<conio.h>
struct nut
{
	char data[80];
	nut *sau,*truoc;
};
typedef nut Node;
Node *dau,*p,*q,*dau1;
int n,i,j,k,dem;
char s[80];
void khoitao(Node *&dau)
{
	dau = NULL;
}
//Tao va lien ket cac nut trong danh sach
void lienketnut(Node *&dau,Node *&p,Node *&q,char s[])
{
	p=new Node;
	strcpy(p->data,s);
	p->sau = NULL;
	p->truoc = NULL;
	if(dau==NULL)
		dau = p;
	else
	{
		q->sau = p;
		p->truoc = q;				
	}
	q=p;
}
//TAO LAP DANH SACH VAN BAN
void nhapvb(Node *&dau,int &n)
{
	n=1;
	Node *p,*q;
	do
	{
		printf("Nhap vao van ban dong %d, Enter thi dung: ",n);
		fflush(stdin);
		gets(s);
		if(strcmp(s,"\0")!=0);
		lienketnut(dau,p,q,s);
		n++;
	}
	while(strcmp(s,"\0")!=0);
}
//DUYET DANH SACH VUA MOI TAO LAP
void duyetvb(Node *dau,int i)
{
	if(dau!=NULL && strcmp(dau->data,"\0")!=0)
	{
		printf("\ndong %d: %s",i,dau->data);
		duyetvb(dau->sau,i+1);
	}
}
//IN DU LIEU CUA DONG THU I
void indongi(Node *dau,int dem,int i)
{
	Node *p;
	p = dau;
	if(p!=NULL && dem == i)
		printf("\ndu lieu dong %d: %s",i,p->data);
	else if(p!=NULL) indongi(p->sau,dem+1,i);
	else printf("\nKhong co dong %d trong danh sach",i);
}
//IN DU LIEU CUA DONG THU I DEN J
void indongij(Node *dau,int i,int j,int dem)
{
	
	Node *p;
	p = dau;
	if(i<=j)
	{
		if(p!=NULL && dem==i)
			{
				printf("du lieu dong %d: %s\n",i,p->data);
				indongij(p->sau,i+1,j,dem+1);
			}
		else if(p!=NULL) indongij(p->sau,i,j,dem+1);
	}
}
//XOA DONG THU I
void xoai(Node *&dau,Node *q,int i,int dem)
{
	Node *p,*l;
	if(dem==1) q = NULL;
	p = dau;
	if(p!=NULL && dem == i)
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
	else if(p!=NULL) xoai(p->sau,q=p,i,dem+1);
}
//SAO CHEP TU DONG I DEN DONG J
void saochepij(Node *dau,Node *&dau1,int i,int j,int dem)
{
	if(dem==1) {p = NULL;q = NULL;}
	if(i<=j)
	{
		if(dau!=NULL && dem==i)
		{
			lienketnut(dau1,p,q,dau->data);
			saochepij(dau->sau,dau1,i+1,j,dem+1);
		}
		else if(dau!=NULL) saochepij(dau->sau,dau1,i,j,dem+1);
	}
}
//CHEP DONG I -> J VUA SAO CHEP DUOC VAO SAU DONG K
void chepij(Node *&dau,Node *dau1,int k,int dem)
{
	Node *p;
	if(i<=j)
	{
		if(dem<k) chepij(dau->sau,dau1,k,dem+1);
		else if(dem==k)
		{
			p = dau->sau;
			dau->sau = dau1;
			dau1->truoc = dau;
			while(dau1->sau!=NULL)
				dau1 = dau1->sau;
			if(dau1->sau == NULL)
			{
				dau1->sau = p;
				p->truoc = dau1;
			}
		}
	}
}
//XOA DONG THU I ->J
void xoaij(Node *&dau,Node *q,int i,int j,int dem)
{
	Node *p;
	p=dau;
	if(dem==1) q = NULL;
		else if(p!=NULL && dem==i-1) q = p;
	if(i<=j)
	{
		if(p!=NULL && dem==i)
		{
			dau=p->sau;
			delete p;
			xoaij(dau,q,i+1,j,dem+1);
		}
		else if(dau!=NULL) xoaij(dau->sau,q,i,j,dem+1);
	}
	else if(i==j+1)
	{
		if(q!=NULL)
		{
			q->sau = p;
			p->truoc = q;
		}
		else
			p->truoc = q;
	}
}
int main()
{
	khoitao(dau);
	khoitao(dau1);
	nhapvb(dau,n);
	printf("\nDanh sach vua tao la:\n");
	duyetvb(dau,1);
	printf("\n\n------------------------------------------------------");
	printf("\n\nNhap dong can in i: ");scanf("%d",&i);
	indongi(dau,1,i);
	printf("\n\n------------------------------------------------------\n");
	do
	{
		printf("\nNhap dong dich j (%d<= j <%d) : ",i,n-1);scanf("%d",&j);
	}while(j>=n-1 || j<i);
	printf("\nDu lieu tu dong %d den dong %d la:\n\n",i,j);
	indongij(dau,i,j,1);
	xoai(dau,q,i,1);
	printf("\n------------------------------------------------------\n");
	printf("\nDanh sach sau khi xoa dong %d la:\n",i);
	duyetvb(dau,1);
	printf("\n\n------------------------------------------------------\n");
	do
	{
		printf("\nNhap dong k (k<%d) : ",n-2),scanf("%d",&k);
	}while(k>=n-2);
	printf("\n\n------------------------------------------------------\n");
	while(i>=n-2)
	{
		printf("\nVi danh sach da duoc cap nhat va dong %d khong con dung \n Xin vui long Nhap lai dong xuat phat i (i <%d) : ",i,n-2);
		scanf("%d",&i);
	}
	printf("\n\n------------------------------------------------------\n");
	while(j>=n-2 || j<i)
	{
		printf("\nVi danh sach da duoc cap nhat va dong %d khong con dung \n Xin vui long Nhap lai dong dich j (%d<= j <%d) : ",j,i,n-2);
		scanf("%d",&j);
	}
	printf("\n------------------------------------------------------\n");
	printf("\nDanh sach sao chep tu dong %d den dong %d la:\n",i,j);	
	saochepij(dau,dau1,i,j,1);
	duyetvb(dau1,i);
	printf("\n\n------------------------------------------------------\n");
	printf("\nDanh sach sau khi sao chep tu dong %d den dong %d vao sau dong %d la:\n",i,j,k);	
	chepij(dau,dau1,k,1);
	duyetvb(dau,1);
	printf("\n------------------------------------------------------\n");
	printf("\nDanh sach sau khi xoa tu dong %d toi dong %d la:",i,j);
	xoaij(dau,q,i,j,1);
	duyetvb(dau,1);
	return 0;
}
