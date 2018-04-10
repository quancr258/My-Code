#include <stdio.h>
#include <conio.h>
//------------------------------------
struct nut
{
	int gtri;
	nut *tiep;
};
typedef nut Node;
Node *dau;
//------------------------------------
void khoitao(Node *&dau)
{
	dau = NULL;
}
//------------------------------------
void taods(Node *&dau)
{
	Node *p, *q;
	int tam;
	do
	{
		printf("Nhap vao 1 do nguyen, 0: dung ");
		scanf("%d",&tam);
		if (tam != 0)
		{//--tao mot nut moi
			p = new Node;
			p ->gtri = tam;
			p ->tiep =NULL;
			//----------------------------------
			/*Moc vao danh sach*/
			if (dau == NULL)
			dau = p;
			else 
			q->tiep = p;
			q = p;
		}
	}
	while (tam != 0);
}
// Duyet danh sach
void duyetds(Node *dau)
{
	if (dau != NULL)
	{
		printf("%3d",dau->gtri);
		duyetds(dau->tiep);
	}
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
// Chen phan tu vao dau danh sach
void chendau(Node *&dau, int x)
{
	Node *p;
	//-------------Tao nut moi-----------
	p = new Node;
	p -> gtri = x;
	p -> tiep = NULL;
	//------------Moc vao dau danh sach
	p -> tiep = dau;
	dau = p;
}

// Chen x vao cuoi danh sach
void chencuoi(Node*&dau, int x)
{
	Node *p, *q;
	p = new Node;
	p -> gtri = x;
	p -> tiep = NULL;
	q = dau;
	while (q -> tiep != NULL)
	 q = q -> tiep;
	 q -> tiep = p;
}
//-------------------------------------------
int main()
{
	khoitao(dau);
	taods(dau);
	printf("\n------------------\n");
	duyetds(dau);
	sapxep(dau);
	printf("\n---------Sap xep---------\n");
	duyetds(dau);
	chendau(dau,99);
	printf("\n Chen 99 vao dau danh sach\n");
	duyetds(dau);
	chencuoi(dau,77);
	printf("\n Chen 99 vao cuoi danh sach\n");
	duyetds(dau);
	chencuoi(dau,100);
	printf("\n--Chen 100 vao cuoi danh sach\n");
	duyetds(dau);
	getch();
}
