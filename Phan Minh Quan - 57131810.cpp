#include<stdio.h>
#include<conio.h>
struct nut
{
	int gtri;
	nut *tr,*ph; 
	/*tr : trai
	ph: phai
	*/
};
typedef nut Node;
Node *goc;
int i;
//khoi tao gia tri goc
void khoitao(Node *&goc)
{
	goc = NULL;
}
//moc 1 nut vao cay
void mocnut(Node *&goc,int x)
{
	if(goc == NULL)
	{
		goc = new Node;
		goc->gtri = x;
		goc->tr = NULL;
		goc->ph = NULL;
	}
	else
	{
		if(goc->gtri >= x)
			mocnut(goc->tr,x);
		else
			mocnut(goc->ph,x);
	}
}
//tao 1 cay nhi phan
void taocay(Node *&goc)
{
	int x;
	do
	{
		printf("Nhap 1 so nguyen, dung khi nhap 0: ");
		scanf("%d",&x);
		if(x!=0)
			mocnut(goc,x);
	}
	while (x!=0);
}
//duyet cay nhi phan theo thu tu giua LNR
void duyetLNR(Node *goc)
{
	if(goc != NULL)
	{
		duyetLNR(goc->tr);
		printf("%3d",goc->gtri);
		duyetLNR(goc->ph);
	}
}
//---------------Tim cac nut la-------------
void timla(Node *goc)
{
	if(goc!=NULL)
		if(goc->ph==NULL && goc->tr==NULL) printf("%3d",goc->gtri);
		else
		{
			timla(goc->ph);
			timla(goc->tr);
		}
}
//dem so nut la cua cay co gia tri be hon 10
int demla(Node *goc)
{
	if(goc == NULL)
		return 0;
	else
		if(goc->tr==NULL && goc->ph==NULL && goc->gtri<10)
			return 1;
		else
			return demla(goc->tr)+demla(goc->ph);
}
//---------------------------------------------
int Tongnut(Node *goc)
{
   if(goc==NULL)
      return 0;
   else
      if((goc->tr!=NULL) || (goc->ph!=NULL))
	 return goc->gtri+ Tongnut(goc->tr)+Tongnut(goc->ph);
}
//-------------Chuong trinh chinh------------
int main()
{
	khoitao(goc);
	taocay(goc);
	printf("\n-----------Duyet LNR----------\n");
	duyetLNR(goc);
	printf("\n-----------Tim nut la-------------\n");
	printf("Cac nut la cua cay: ");
	timla(goc);
	printf("\n-----------Dem la nho hon 10-------------\n");
	printf("So nut la cua cay nho hon 10 la: %d\n",demla(goc));
	printf("Tong cac nut nhanh: %d",Tongnut(goc));
	return 0;
}
