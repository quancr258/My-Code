#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<iostream>
#define MAX 50
//Cau e: nhap mang
int nhap(int a[],int &n)
{
    int i;
    do
    {
        system("cls");
        printf("nhap vao so phan tu: n = ");
        scanf("%d",&n);
    }
    while(n<0 || n>MAX);
    for(i=0;i<n;i++)
    {
        printf("nhap vao phan tu thu a[%d]: ",i+1);
        scanf("%d",&a[i]);
    }
}
//Cau f: xuat mang
int xuat(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%5d",a[i]);
    }
}
//cau g
int ktr(int c)
{
    int b;
    b=sqrt(c);
    if(b*b==c && c>0) return 0;
}
//Cau h:
int Tachmang(int a[],int n, int cp[],int &ncp,int t[], int &nt)
{
    int c,i,j=0,k=0;
    ncp=0;nt=0;
    for(i=0;i<n;i++)
    {
        c=sqrt(a[i]);
        if(c*c==a[i] && a[i]>0)
        {
            cp[ncp]=a[i];ncp++;
        }
        else
        {
            t[nt]=a[i];nt++;
        }
    }
}
int main()
{
    int a[MAX],cp[MAX],ncp,t[MAX],nt,i,c,n,d=0;
    printf("\nCau e:\n");
    nhap(a,n);
    printf("\nCau f:Mang vua nhap la:\n");
    xuat(a,n);
    printf("\nCau g: Cac phan tu la so chinh phuong trong mang la: \n");
    for(i=0;i<n;i++)
    {
        c=a[i];
        if(ktr(c)==0)
        {
            printf("%5d",c);
            d++;
        }
    }
    if(d==0) printf("\n Khong co phan tu thoa man\n");
    printf("\n Co %d phan tu la so chinh phuong trong mang \n",d);
    printf("\nCau h:\n");
    Tachmang(a,n,cp,ncp,t,nt);
    printf("\nMang chua cac phan tu la so chinh phuong:\n");
    xuat(cp,ncp);
    printf("\nMang chua cac phan tu khong la so chinh phuong:\n");
    xuat(t,nt);
    getch();
}
