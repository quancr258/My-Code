#include<stdio.h>
#include<math.h>
#include<conio.h>
int laSoNt(int n)
{
    int i,d=0;
    for(i=1;i<=sqrt(n);i++)
    {
       if(n%i==0)
       {
          d++;
          if(d==2) break;
       }
    }
    if(d==2 || n==1) return(0);
    else  return(1);
}
int main()
{
    int n,a;
    for(n=2;n<1000;n++)
    {
       if(laSoNt(n)==1) printf("%d\t",n);
    }
    getch();
}
