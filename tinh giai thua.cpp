#include <stdio.h>
#include <conio.h>
int main()
{
    int n,i,gt;
    printf("nhap vao n = ");
    scanf("%d",&n);
    gt=1;
    for(i=1;i<=n;i++)
           gt=gt*i;
    printf("giai thua cua %d! la: %d",n,gt);
    getch();
}
