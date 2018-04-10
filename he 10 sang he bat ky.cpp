#include<stdio.h>
#include<conio.h>

void kiemtr(int a[],int n,int x)
{
    int i,j,tp=0,m,l;
    if(x==2||x==8||x==16)
    {
    while (n != 0)
    {
        i=n%x;
        a[tp]=i;
        n=n/x;
        tp++;
    }
    m=x;
    if(m==16)
    {
        printf("\nda chuyen doi sang he 16 la:");
        for(l=tp-1;l>=0;l--)
        {
            switch(a[l])
            {
                case 10: printf("A "); break;
                case 11: printf("B "); break;
                case 12: printf("C "); break;
                case 13: printf("D "); break;
                case 14: printf("E "); break;
                case 15: printf("F "); break;
                default : printf("%d ",a[l]);
            }
        }
    }
    else
    {
    printf("da chuyen sang he %d la :",x);
    for(j=tp-1;j>=0;j--)
    printf("%d ",a[j]);
    }
    }
    else printf("ban nhap he ko dung");
}

int main()
{
    int b[20],n,x;
    printf("\n nhap so can doi: ");
    scanf("%d",&n);
    printf("\n nhap so he can chuyen: ");
    scanf("%d",&x);
    kiemtr(b,n,x);
    getch();
} 
