#include <stdio.h>
#include <conio.h>
int main()
{
    int n,i;
    printf("nhap vao so n = ");
    scanf("%d",&n);
    if (n>=0)
    for(i=1;i<n;i++)
              { if (i!=1 && n%i==0) 
               {
                   i=n+1;
                   printf("\n %d khong phai la so nguyen to",n);
               }
               else if (i==n-1 || n==2) printf("\n %d la so nguyen to",n);
              }
    else printf("\n so %d khong hop le",n);
    getch();
}                              
