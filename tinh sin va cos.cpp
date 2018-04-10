#include<stdio.h>
#include<math.h>
#include<conio.h>
int main ( )
{
int i, n;
float tong,x;
printf(" nhap n : ");
scanf("%d",&n);
printf("\n nhap x: ");
scanf("%f",&x);
{
for (i=1; i<=n; i++)
if(i%2!=0)
tong=tong+sin(i*x);
else
tong=tong+cos(i*x);
}
printf("\n F=%f",tong);
getch ();
}
