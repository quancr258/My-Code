#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    float n,tong,tong1,tong2,tong3;
    int i;
    printf("nhap vao so n = ");
    scanf("%f",&n);
    tong=0;
    tong1=0;
    tong2=0;
    tong3=0;
    if (n>=0)
    {
        for (i=1;i<=n;i++)
                tong=tong+i;
        printf("\n S1: tong cac so tu 1 den %.0f = %.0f\n",n,tong);
        for (i=1;i<=(2*n-1);i++)
                {
                    if(i%2==1)
                    tong1=tong1+i;
                }
        printf("\n S2: tong cac so le tu 1 den %.0f = %.0f\n",2*n-1,tong1);
        for (i=1;i<=n;i++)
                    tong2=tong2+pow(i,2);
        printf("\n S3: tong cac so binh phuong tu 1 den %.0f = %.0f\n",n,tong2);
        for (i=1;i<=n;i++)
                    tong3=tong3+float(1)/i;
        printf("\n S4: tong cac phan so tu 1 den 1/%.0f = %.2f\n",n,tong3);
        printf("\n S5: can bac 2 cua tong cac so binh phuong tu 1 den %.0f = %.2f\n",n,float(sqrt(tong2)));
    }
    else printf("\n so %.0f nhap vao khong hop le\n",n);
    getch();
}                            
