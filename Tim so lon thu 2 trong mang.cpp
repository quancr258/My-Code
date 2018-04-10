#include <stdio.h>
#include <conio.h>
int nhapmang(int n, int a[])
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("nhap phan tu thu a[%d] = ",i+1);
        scanf("%d",&a[i]);
    }
}
int inmang(int n, int a[])
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("%5d ",a[i]);
    }
}
int ktra(int n, int a[])
{
    int i, max1=a[0],max2=0;
    for (i=0;i<n;i++)
    {
        if (a[i]>max1)
           max1=a[i];
    }
    for (i=0;i<n;i++)
    {
        if (a[i]>max2 && a[i]<max1)
           max2=a[i];
    }
    printf("%d",max2);
}
int main()
{
    int n,a[50],max2;
    printf("nhap vao so phan tu n = ");
    scanf("%d",&n);
    nhapmang(n,a);
    printf("\nmang vua nhap la: ");
    inmang(n,a);
    printf("\nso lon thu 2 trong mang la: ");
    ktra(n,a);
    getch();
}
