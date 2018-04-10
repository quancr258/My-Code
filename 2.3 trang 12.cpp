#include<stdio.h>
#include<conio.h>
int nhap(int a[])
{
    int i;
    for(i=0;i<4;i++)
    {
        scanf("%d",&a[i]);
    }
}
int sx(int a[])
{
    int i,d=0,min,n=4,j;
    while(d<4)
    {
    min=a[0];
    for(i=0;i<n;i++)
    {
        if(min>=a[i]) min=a[i];
    }
    for(j=0;;j++)
    {
        if(min==a[j])
        {
           printf("%d ",a[j]);
           a[j]=a[n-1];
           n--;
           d++;
           break;
        }
    }
    }
}
int main()
{
    int a[255];
    nhap(a);
    sx(a);
    getch();
}
