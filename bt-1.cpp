#include<conio.h>
#include<stdio.h>
# define max 107
int a[max];

void hamnhap(int a[], int n)
{    int i;
  
       for(i=0;i<n;i++)
       {
       	 printf("nhap vao cac so nguyen a[%d]:",i);
       	 scanf("%d",&a[i]);
       }
}
//--------------------
//-------------------------
void xuatmang(int a[],int n)
{   int i;
   for(i=0;i<n;i++)
   {
   	printf("a[%d]=",i);
    
   	printf("%d",a[i]);
   	printf("\n");
   } 
    
}
//----------------------
//--------------------------
int kt(int a[], int n)
{
	if(n<=1)
	 return 1;
	else 
	if (a[n]>=a[n-1])
	  return kt(a,n-1);
	else 
	  return 0;
	  
}
int main()
{
	int n;
	printf("nhap vao so luong phan tu: ");
	scanf("%d",&n);
	//------------------------
  hamnhap(a,n);
  //---------------------
  xuatmang(a,n);
  printf("\n");
  //==========================
  printf("kiem tra mang %d\n",kt(a,n));
  if(kt(a,n)==1)
  {
  	printf("day tang dan");
  }
  else 
  {
  	printf("day ko tang dan");
  }
  
  //==== ===================
  getch();
  return 0;
  
}

