//de so 2 - Cau 2:
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    int n,i,a,b;
    printf("nhap vao n= ");
    scanf("%d",&n);
    if(n>0)
    {
    //cau a
           a=sqrt(n);
           if (a*a==n) printf("\n %d la so chinh phuong \n",n);
           else printf("\n %d khong phai la so chinh phuong \n",n);
    }
    else printf("\n So %d nhap vao khong hop le\n",n);
    //cau b
           printf("\n Cac so chinh phuong <10000 la:\n\n");
           for (i=1;i<10000;i++)
           {
             b=sqrt(i);
             if(b*b==i) printf("%5d",i);
           }
    getch();
}
