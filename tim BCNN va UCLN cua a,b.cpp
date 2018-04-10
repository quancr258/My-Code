#include <stdio.h>
#include <conio.h>
int main()
{
    int a,b,i,UCLN,BCNN,min,max;
    printf ("nhap vao a= ");
    scanf("%d",&a);
    printf ("nhap vao b= ");
    scanf("%d",&b);
    UCLN=1;
    BCNN=a*b;
    if(a>=b) 
      {
             min=b;
             max=a;
      }
    else 
      {
            min=a;
            max=b;
      }
            for(i=1;i<=min;i++)
              if(a%i==0 && b%i==0) 
                UCLN=i;
            for(i=max;BCNN<=0;i++)
              if(i%a==0 && i%b==0)
                BCNN=i;
            printf("\n uoc chung lon nhat cua %d va %d la: %d \n",a,b,UCLN);
            printf("\n boi chung nho nhat cua %d va %d la: %d \n",a,b,BCNN);
    getch();
}
