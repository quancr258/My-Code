#include <stdio.h>
#include <conio.h>
int main()
{
    int n,i,j,tong=0,tongi;
    printf("nhap vao so n = ");
    scanf("%d",&n);
    if (n>0)
    {
            //kiem tra n co phai la so hoan hao khong
            for(i=1;i<n;i++)
              if(n%i==0) tong=tong+i;
            if (tong==n) printf("\n %d la so hoan hao \n",n);
            else printf("\n %d khong phai la so hoan hao \n",n);
            //xuat cac so hoan hao <10000
            printf("\n cac so hoan hao <10000 la: \n");
             for(i=1;i<=10000;i++)
              {
                   tongi=0;
                   for(j=1;j<i;j++)
                     if(i%j==0) tongi=tongi+j;
                   if (tongi==i) printf("%d \t",i);
              }         
    }
    else printf("\n so %d nhap vao khong hop le \n",n);
    getch();
}
