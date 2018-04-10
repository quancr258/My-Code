#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
#include<conio.h>
struct ptrang
{
	int ptu;
	/*chu thich
	ptu: phan tu cua chuoi truy xuat
	*/
}a[MAX];
int n,skt,ycttt,b[MAX],t[MAX];
int loi,d=1;
int lFIFO,lLRU,lOPT;
char *x,*y;
int w,q;
/* skt: so khung trang
	n: so phan tu cua chuoi truy xuat
	ycttt: yeu cau thay the trang
	b[MAX]: Mang dieu khien cac khung trang
	t[MAX]: mang chua phan tu truy xet tam thoi
	loi: so loi trang
	d: vi tri phan tu nan nhan
	lFIFO,lLRU...: so loi cua tung giai thuat tuong ung
	x,y,w,q: xem ham sosanh va chuong trinh chinh de hieu ro hon
*/
//------------KHOI TAO DU LIEU------------------------
void khoitao(ptrang a[],int &n,int &skt,int &loi)
{
	int i;
	srand(time(NULL));//khoi tao ngau nhien cac phan tu khong giong nhau moi lan chay khac nhau
	ycttt = rand()%3;
	n = rand()%21;//khoi tao ngau nhien n so phan tu cua chuoi truy xuat tu 0 ->20
	skt = rand()%11;//khoi tao ngau nhien skt tu 0 ->9
	loi = n;
	for(i=1;i<=n;i++)
		a[i].ptu = rand()%100;//khoi tao ngau nhien phan tu thu i cua chuoi truy xuat tu 0 -> 99
}
//------------KHOI TAO DU LIEU KHUNG TRANG------------------------
void khungtrang(int b[],int skt)
{
	int i;
	for(i=1;i<=skt;i++)
		b[i] = -1;//Khoi tao gia tri ban dau moi khung trang la rong (-1)
}
//------------DUYET DU LIEU------------------------
void duyet(ptrang a[],int ycttt,int n,int skt)
{
	int i;
	printf("Yeu cau thay the trang: ");
	if(ycttt==0) printf("FIFO\n");
	else if(ycttt==1) printf("LRU\n");
	else printf("OPT\n");
	printf("Co %d khung trang (Khung trang rong mang gia tri -1)\n",skt);
	printf("Chuoi truy xuat gom %d phan tu : \n",n);
	for(i=1;i<=n;i++)
		if(i!=n) printf(" %3d ;",a[i].ptu);
		else printf(" %3d .",a[i].ptu);
}
//----------------------Ve BANG TRUY XUAT------------------
void ve(int b[],int skt,int kt1)
{
	int i;
	if(kt1!=0) printf("%5s*%5s"," "," ");
		else printf("%5s %5s"," "," ");
	for(i=1;i<=skt;i++)
	{
		if(i==skt) printf(" %3d ",b[i]);
		else printf(" %3d ;",b[i]);
	}
}
//------------THUAT TOAN FIFO------------------------
int FIFO(ptrang a[],int b[],int n,int skt,int d,int loi)
{
	int i,j;
	int kt1=0,kt2=0;//kt: dung de kiem tra xem moi phan tu da duoc xu li hay chua
	for(i=1;i<=n;i++)
	{
		j=1;
		do
		{
			if(kt1==0)
			{
				if(b[j] == a[i].ptu)
				{
					loi--;kt2 = 1;
				}
				else if(j == skt)
				{
					j = 1;kt1 = 1;
				}
			}
			if(kt1==1)
			{
				if(b[j] == -1)
				{
					b[j] = a[i].ptu;kt2 = 1;
				}
				else if(j == skt)
				{
					j = 1;kt1 = 2;
				}
			}
			if(kt1==2)
			{
				b[d] = a[i].ptu;
				d++;
				kt2 = 1;
			}
			j++;
		}
		while(j<=skt && kt2==0);
		if(ycttt==0)
		{
			printf("\n");
			ve(b,skt,kt1);
		}
		//Dinh dang lai dieu kien lap
		if(d>skt) d = 1;
		kt1=0;kt2=0;
	}
	return lFIFO = loi; 
}
//------------THUAT TOAN LRU----------------------------
int LRU(ptrang a[],int b[],int n,int skt,int d,int loi)
{
	int i,j,k=1,dem=0;
	int kt1=0,kt2=0;//kt: dung de kiem tra xem moi phan tu da duoc xu li hay chua
	{
		for(i=1;i<=n;i++)
		{
			j=1;
			do
			{
				if(kt1==0)
				{
					if(b[j] == a[i].ptu)
					{
						loi--;kt2 = 1;
						k=1;
						while(t[k]!=j) k++;
						for(k=k;k<dem;k++)
							t[k] = t[k+1];
						t[dem] = j;
					}
					else if(j == skt)
					{
						j = 1;kt1 = 1;
					}
				}
				if(kt1==1)
				{
					if(b[j] == -1)
					{	
						dem++;
						b[j] = a[i].ptu;kt2 = 1;
						t[j] = j;
					}
					else if(j == skt)
					{
						j = 1;kt1 = 2;
					}
				}
				if(kt1==2)
				{
					d = t[1];
					b[d] = a[i].ptu;
					for(k=1;k<dem;k++)
							t[k] = t[k+1];
					t[dem] = d;
					kt2 = 1;
				}
				j++;
			}
			while(j<=skt && kt2==0);
			if(ycttt==1)
			{
				printf("\n");
				ve(b,skt,kt1);
			}
			//Dinh dang lai dieu kien lap
			kt1=0;kt2=0;
		}		
		return lLRU = loi; 
	}
}
//------------THUAT TOAN OPT----------------------------
int OPT(ptrang a[],int b[],int t[],int n,int skt,int d,int loi)
{
	int i,j,k=1,l;
	int kt1=0,kt2=0;//kt: dung de kiem tra xem moi phan tu da duoc xu li hay chua
	for(i=1;i<=n;i++)
	{
		j=1;
		do
		{
			if(kt1==0)
			{
				if(b[j] == a[i].ptu)
				{
					loi--;kt2 = 1;
				}
				else if(j == skt)
				{
					j = 1;kt1 = 1;
				}
			}
			if(kt1==1)
			{
				if(b[j] == -1)
				{
					b[j] = a[i].ptu;kt2 = 1;
				}
				else if(j == skt)
				{
					j = 1;kt1 = 2;
				}
			}
			if(kt1==2)
			{
				d=0;
				for(k=1;k<=skt;k++)
				{
					for(l=i;l<=n;l++)
					{
						if(b[k]==a[l].ptu)
						{
							t[k] = l;break;
						}
						else if(l==n && b[k]!=a[l].ptu)
						{
							d = k;break;
						}
					}
					if(d==k) break;
					else if(k==skt)
					{
						d=1;
						for(l=2;l<=skt;l++)		
							if(t[d]<t[l]) d = l;
					}
				}
				b[d] = a[i].ptu;
				kt2 = 1;
			}
			j++;
		}
		while(j<=skt && kt2==0);
		if(ycttt==2)
		{
			printf("\n");
			ve(b,skt,kt1);
		}
		//Dinh dang lai dieu kien lap
		if(d>skt) d = 1;
		kt1=0;kt2=0;
	}
	return lOPT = loi; 
}
//------------SO SANH GIAI THUAT------------------------
void sosanh(int q,int w, char *x,char *y)
{
	if(q == w)
		printf("\t%s va %s nhu nhau\n",x,y);
	else if(q < w)
		printf("\t%s toi uu hon %s\n",x,y);
	else printf("\t%s toi uu hon %s\n",y,x);
}
//------------CHUONG TRINH CHINH------------------------
int main()
{
	khoitao(a,n,skt,loi);
	duyet(a,ycttt,n,skt);
	if(skt==0 && n!=0) printf("\nChuong trinh co vo so loi trang");
	else
	{
		khungtrang(b,skt);
		if(ycttt==0 && n>0) printf("\n\n\t\tBANG TRUY XUAT FIFO THEO HANG DOC\n");
		printf("\n\n**So loi trang trong giai thuat FIFO la: %d loi trang",FIFO(a,b,n,skt,d,loi));
		khungtrang(b,skt);
		if(ycttt==1 && n>0) printf("\n\n\t\tBANG TRUY XUAT LRU THEO HANG DOC\n");
		printf("\n\n**So loi trang trong giai thuat LRU la: %d loi trang",LRU(a,b,n,skt,d,loi));
		khungtrang(b,skt);
		if(ycttt==2 && n>0) printf("\n\n\t\tBANG TRUY XUAT OPT THEO HANG DOC\n");
		printf("\n\n**So loi trang trong giai thuat OPT la: %d loi trang",OPT(a,b,t,n,skt,d,loi));
		printf("\n\n\t\tSO SANH CAC GIAI THUAT:\n\n");
		sosanh(lFIFO,lLRU,"FIFO","LRU");
		sosanh(lFIFO,lOPT,"FIFO","OPT");
		sosanh(lOPT,lLRU,"OPT","LRU");
	}
	getch();
}
