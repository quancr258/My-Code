#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    int n,m;
    printf("nhap vao thang: ");
    scanf("%d",&n);
    if (((n%2)>1) || (n<=0) || (n>12)) printf ("thang nhap vao khong hop le");
    else 
    {
         if (n==2)
         {
                  printf ("nhap nam: ");
                  scanf("%d",&m);
                  if (m<0) printf("nam nhap vao khong hop le");
                  else
                  {
                      if (((m%400)==0) || (((m%4)==0) && ((m%100)!=0))) printf("thang 2 nam %d co 29 ngay vi la nam nhuan",m);
                      else printf("thang 2 nam %d co 28 ngay vi la nam khong nhuan",m);
                  }
         }
         else
         {
                  if (n<=7)
                  {
                           if (n%2==1) printf("thang %d co 31 ngay",n);
                           else if (n%2==0) printf ("thang %d co 30 ngay",n);
                  }
                  else
                  {
                           if (n%2==0) printf ("thang %d co 31 ngay",n);
                           else if (n%2==1) printf("thang %d co 30 ngay",n);
                  }
         }
    }
    getch();
}
                      
