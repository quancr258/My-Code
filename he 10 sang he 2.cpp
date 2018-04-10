#include<stdio.h>
#include<conio.h>
int main()
{
    int a[64],n,i,tp=0,l;
    printf("nhap vao so n = ");
    scanf("%d",&n);
    while (n>0)
    {
        i=n%2;
        a[tp]=i;
        n=n/2;
        tp++;
    }
    printf("da chuyen sang he 2 la :");
    for(i=tp-1;i>=0;i--)
    printf("%d ",a[i]);
    getch();
}
