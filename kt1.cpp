#include<stdio.h>
#include<math.h>
#include<conio.h>
int main()
{
    unsigned int x,n;
    int m,a[20],i,d=0,b=0;
    scanf("%u",&x);
    n=x;
    for(i=0;n>0;i++)
    { 
         m=n%2;
         n/=2;
         a[i]=m;
         d++;
    }
    for(i=0;i<d;i++)
    {
        printf("%d\n",a[i]);
    }
    if(d<15)
    for(i=d;i<15;i++) printf("0\n");
    getch();
}
