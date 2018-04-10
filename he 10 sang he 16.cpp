#include<stdio.h>
#include<conio.h>
int main()
{
    int a[64],n,i,tp=0,l;
    printf("nhap vao so n = ");
    scanf("%d",&n);
    while (n>0)
    {
        i=n%16;
        a[tp]=i;
        n=n/16;
        tp++;
    }
    printf("\nda chuyen doi sang he 16 la: ");
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
    getch();
}
