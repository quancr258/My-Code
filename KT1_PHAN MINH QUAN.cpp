//de so 2 - Cau 1:
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    int n,i,tong=0;
    float s1=0,s2=0;
    printf("nhap vao n= ");
    scanf("%d",&n);
    if(n>0)
    {
           for(i=1;i<=n;i++)
           {
              s1=s1+1.0/(2*i);
              tong=tong+i;
              s2=(s2+tong);
           }
           printf("\n S1= %f \n",s1);
           printf("\n S2= %f \n",sqrt(s2));
    }
    else printf("\n so %d nhap vao khong hop le",n);
    getch();
}
