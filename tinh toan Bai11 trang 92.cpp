#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    int n,i,j,s1=0,s2=0,p=1,s3=0,gt=1,s4=0,gt1,k,l;
    float s5=1,s6=0,s7=0;
    printf("nhap vao n = ");
    scanf("%d",&n);
    if(n>0)
    {
    for(i=1;i<=n;i++)
    {    
         s1=s1+i;
         gt=gt*i;
         s3=s3+gt;
         if (i%2==0) 
         {
              s2=s2-i; 
              s4=s4-gt;
         }
         else 
         {
              s2=s2+i;
              s4=s4+gt;
         }
         for (j=1;j<=s1;j++)
         {
             gt1=gt1*j; 
             if (j==s1) 
             {
                 s5=(s5+gt1);
                 gt1=1;
             }
         }
         s6=sqrt(i+s6);
    }
    for (i=1;i<=(2*n-1);i++)
        p=p*i;
    for (i=n;i>0;i--)
        s7=sqrt(i+s7);
    printf("\n a. Tong cac so tu 1 den %d la:\n %6s S1= %d",n," ",s1);
    printf("\n b. Tong cac so le va hieu cac so chan tu 1 den %d la:\n %6s S2= %d",n," ",s2);
    printf("\n c. Tich cac so tu 1 den %d la:\n %6s P= %d",2*n-1," ",p);
    printf("\n d. Tong cac giai thua tu 1 den %d la:\n %6s S3= %d",n," ",s3);    
    printf("\n e. Tong cac giai thua le va hieu cac giai thua chan tu 1 den %d la:\n %6s S4= %d",n," ",s4);
    printf("\n f. Thuong so cua tong cac tong giai thua va %d! la:\n %6s S5= %f ",n," ",s5/gt);
    printf("\n i. Tong cac can bac 2 tu %d den 1 la:\n %6s S6= %f",n," ",s6);
    printf("\n j. Tong cac can bac 2 tu 1 den %d la:\n %6s S7= %f",n," ",s7);
    }
    else printf("\n so %d nhap vao khong hop le",n);
    getch();
}
