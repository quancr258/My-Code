#include<stdio.h>
#include<conio.h>
#define max 50
int nhap(int &n)
{
    do
    {
        printf("so phan tu cua mang: n = ");
        scanf("%d",&n);
    }
    while(n<0);
}
int nhap_pt(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
       printf("nhap phan tu thu %d: ",i+1);
       scanf("%d",&a[i]);
    }
}
int USLN(int b, int c)
{
    int t;
    while(c>0)
    {
       t=b%c;
       b=c;
       c=t;
    }
    if(b==1) return 1;
    else return 0;
}
int main()
{
    int a[max],b,c,n,i,j,d=0;
    nhap(n);
    nhap_pt(a,n);
    printf("cac cap so nguyen to cung nhau trong mang la:\n");
    for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
    {
       if(a[i]==0 || a[j]==0) continue;
       else
       {
           b=a[i];c=a[j];
           if(USLN(b,c)==1) 
           {
              printf("\t%d va %d\n",b,c);
              d++;
           }
       }
    }
    if(d==0) printf("\"khong ton tai cac cap so nguyen to cung nhau trong mang\"");
    getch();
}
