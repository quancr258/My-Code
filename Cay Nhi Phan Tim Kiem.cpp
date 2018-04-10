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
Node *goc,*goc1;
int i,muc=1,x;
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
//duyet cay nhi phan theo thu tu truoc NLR
void duyetNLR(Node *goc)
{
	if(goc != NULL)
	{
		printf("%3d",goc->gtri);
		duyetNLR(goc->tr);
		duyetNLR(goc->ph);
	}
}
//duyet cay nhi phan theo thu tu truoc NRL
void duyetNRL(Node *goc)
{
	if(goc != NULL)
	{
		printf("%3d",goc->gtri);
		duyetNRL(goc->ph);
		duyetNRL(goc->tr);
	}
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
//duyet cay nhi phan theo thu tu giua RNL
void duyetRNL(Node *goc)
{
	if(goc != NULL)
	{
		duyetLNR(goc->ph);
		printf("%3d",goc->gtri);
		duyetLNR(goc->tr);
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
//dem la cua cay
int demla(Node *goc)
{
	if(goc == NULL)
		return 0;
	else
		if(goc->tr==NULL && goc->ph==NULL)
			return 1;
		else
			return demla(goc->tr)+demla(goc->ph);
}
//ham so sanh tim max
int max(int a,int b)
{
	if(a>=b) return a;
	else return b;
}
//chieu cao cua cay
int chieucao(Node *goc)
{
	if(goc == NULL)
		return 0;
	else
		if(goc->tr==NULL && goc->ph==NULL)
			return 1;
		else
			return 1 + max(chieucao(goc->tr),chieucao(goc->ph));
}
//-----------------In ra cac nut o muc i----------------
void inmuci(Node *goc,int i,int muc)
{
	if(goc!=NULL)
		if(muc==i) printf("%3d",goc->gtri);
		else
		{
			inmuci(goc->ph,i,muc+1);
			inmuci(goc->tr,i,muc+1);
		}
}
//-----------------Tong gia tri cac nut o muc i----------------
int tongmuci(Node *goc,int i,int muc=1)
{
	if(goc!=NULL)
		if(muc==i) return goc->gtri;
		else	return tongmuci(goc->ph,i,muc+1) + tongmuci(goc->tr,i,muc+1);
	else return 0;
}
//----------Dem co bao nhieu nut co cay con trai thap hon cay con phai--------------
int demcay(Node *goc)
{
	if(goc!=NULL)
		if(chieucao(goc->tr)<chieucao(goc->ph)) return 1 + demcay(goc->ph) + demcay(goc->tr);
		else
		{
			return demcay(goc->ph) + demcay(goc->tr);
		}
	else return 0;
}
//----------Tinh tong cac nut co cay con trai thap hon cay con phai--------------
int tongdemcay(Node *goc)
{
	if(goc!=NULL)
		if(chieucao(goc->tr)<chieucao(goc->ph)) return goc->gtri + tongdemcay(goc->ph) + tongdemcay(goc->tr);
		else return tongdemcay(goc->ph) + tongdemcay(goc->tr);
	else return 0;
}
//--------------Gan tat ca cac nut la = x----------
void gangtrinutla(Node *goc,int x)
{
	if(goc!=NULL)
		if(goc->ph==NULL && goc->tr==NULL) goc->gtri = x;
		else
		{
			gangtrinutla(goc->ph,x);
			gangtrinutla(goc->tr,x);
		}
}
//--------------Sao chep cay---------------
void saochep(Node *goc,Node *&goc1)
{
	if(goc==NULL)
		goc1 = NULL;
	else
	{
		goc1 = new Node;
		goc1->gtri = goc->gtri;
		saochep(goc->tr,goc1->tr);
		saochep(goc->ph,goc1->ph);
	}
}
//-------------Tinh tong gia tri cac nut------------
int tongnut(Node *goc)
{
	if(goc==NULL) return 0;
	else
		return goc->gtri + tongnut(goc->tr) + tongnut(goc->ph);
}
//-------------Dem so nut co tong gia tri cay con trai > tong gia tri cay con phai-------------
int demtrhph(Node *goc)
{
	if(goc==NULL) return 0;
	else
	{
		if(tongnut(goc->tr)>tongnut(goc->ph))
			return 1 + demtrhph(goc->tr) + demtrhph(goc->ph);
		else
			return demtrhph(goc->tr) + demtrhph(goc->ph);
	}
}
//--------------------Xet chan le---------------
int chanle(Node *goc)
{
	if((goc->gtri%2)==0) return 0;
	else return 1;
}
//-------------Dem so nut co nut (goc) con trai la le va phai la chan--------------
int demchanle(Node *goc)
{
	if(goc==NULL) return 0;
	else
	{
		if(goc->tr != NULL && goc->ph !=NULL)
		{
			if(chanle(goc->tr)==1 && (chanle(goc->ph)==0))
				return 1 + demchanle(goc->tr) + demchanle(goc->ph);
			else 
				return demchanle(goc->tr) + demchanle(goc->ph);
		}
		else 
			return demchanle(goc->tr) + demchanle(goc->ph);
	}
}
//-------------Chuong trinh chinh------------
int main()
{
	khoitao(goc);
	khoitao(goc1);
	taocay(goc);
	printf("\n-----------Duyet NLR----------\n");
	duyetNLR(goc);
	printf("\n-----------Duyet NRL----------\n");
	duyetNRL(goc);
	printf("\n-----------Duyet LNR----------\n");
	duyetLNR(goc);
	printf("\n-----------Duyet RNL----------\n");
	duyetRNL(goc);
	printf("\n-----------Tim nut la-------------\n");
	printf("Cac nut la cua cay: ");
	timla(goc);
	printf("\n-----------Dem la-------------\n");
	printf("So nut la cua cay: %d\n",demla(goc));
	printf("Chieu cao cua cay: %d\n",chieucao(goc));
	printf("Gia tri i = ");scanf("%d",&i);
	printf("\nCac nut o muc %d la: ",i);
	inmuci(goc,i,muc);
	printf("\nTong cac nut o muc %d la: %d",i,tongmuci(goc,i,muc));
	printf("\nSo nut co cay con phai cao hon cay con trai la: %d",demcay(goc));
	printf("\nTong gia tri so nut co cay con phai cao hon cay con trai la: %d\n",tongdemcay(goc));
	printf("\nCay moi sau khi sao chep theo NLR: ");
	saochep(goc,goc1);
	duyetNLR(goc1);
	printf("\nNhap gia tri x can gan vao cac nut la: ");scanf("%d",&x);
	gangtrinutla(goc,x);
	printf("\nCay sau khi duoc gan gia tri %d vao nut la theo NLR: ",x);
	duyetNLR(goc);
	printf("\nSo nut co tong gia tri cay con trai > cay con phai la: %d",demtrhph(goc));
	printf("\nSo nut co tong nut (goc) con trai la le va nut (goc) con phai la chan la: %d",demchanle(goc));
	return 0;
}
