#include <stdio.h>
#include <conio.h>
int main()
{
    int n,i,so_thu_1=1,so_thu_2=2;
    printf("nhap vao so n = ");
    scanf("%d",&n);
    if (n>0)
    {
            printf("Day so Fibonaci la: \n");
            for(i=1;i<=n;i++)
            {
                if(i<=2) printf("%d \t",i);
                else if(i==(so_thu_1+so_thu_2))
                {
                   printf("%d \t",i);
                   so_thu_1=so_thu_2;
                   so_thu_2=i;
                }
            }
    }
    else printf("\n so %d nhap vao khong hop le \n",n);
    getch();
}
