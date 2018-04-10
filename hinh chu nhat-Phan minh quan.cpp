#include <stdio.h>
#include <conio.h>
int main()
{
    int a,b,i,j;
    printf("nhap vao chieu dai hinh chu nhat: ");
    scanf("%d",&a);
    printf("nhap vao chieu rong hinh chu nhat: ");
    scanf("%d",&b);
    if (a>=b>0)
    {
               i=1;
               j=1;
              do
              {
                  if (i==1 || i==a || j==1 || j==b) 
                  printf("*");
                  if (j==1 || j==b)
                  {
                           for(i=1;i<=a-1;i++)
                           printf ("*");
                  }
                  else if (j!=1 && j!=b)
                  {
                           for(i=1;i<=a-1;i++)
                           if (i>1 && i<a)
                           printf (" ");
                  }
                  if (j!=1 && j!=b && i==a)
                           printf ("*");
                  if (i=a-1) printf("\n") && j++;
                  i++;
              }
              while(j<=b);
    }
    else printf("\nDay khong phai la hinh chu nhat");
    getch();
}
