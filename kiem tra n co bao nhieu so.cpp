#include <stdio.h>
#include <conio.h>
int main()
{
    int n,tong=0;
    printf ("nhap vao n= ");
    scanf("%d",&n);
    while(n>0)
    {
              n=n/10;
              tong=tong+1;
    }
    printf("%d",tong);
    getch();
}
