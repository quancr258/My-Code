#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    int a,b,c;
    printf("nhap 3 so a,b,c: \n");
    scanf("%d%d%d",&a,&b,&c);
    if ((a<=0) || (b<=0) || (c<=0)) printf ("a,b,c khong phai do dai 3 canh tam giac");
    else
    {
        if (((a+b)>=c) && ((b+c)>=a) && ((a+c)>=b)) printf ("a,b,c la do dai ba canh tam giac");
        else printf ("a,b,c khong phai do dai 3 canh tam giac");
    }
    getch();
}
