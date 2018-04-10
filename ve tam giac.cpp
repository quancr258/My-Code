#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    int n,m,k,h,i,j,f;
    printf("nhap vao do dai canh tam giac: ");
    scanf("%d",&n);
    printf("\n");
    if (n>1)
    {
                   for(m=n;m>0;m--)
                      {
                            for (i=1;i<=m;i++)
                            {
                                printf ("*");
                                if (i==m) printf("\n");
                                }
                      }
                   printf("\n");
                   for(k=0;k<n;k++)
                      {
                            for (i=k;i>=0;i--)
                            {
                                printf ("*");
                                if (i==0) printf("\n%");
                            }
                      }
                   printf("\n");
                   for(h=n;h>0;h--)
                      {
                            for (i=1;i<=h;i++)
                            {
                                printf ("*");
                                if (i==h) printf("\n%");
                            }
                      }
    }
    else printf("\nDay khong phai la hinh tam giac");
    getch();
}
