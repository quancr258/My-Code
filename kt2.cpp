#include<stdio.h>
#include<math.h>
#include<conio.h>
int main()
{
    int i,n=0;
    float x,t=1,p,s=1,EPSILON;
    printf("x = "); scanf("%f",&x);
    printf("EPSILON = "); scanf("%f",&EPSILON);
    p=(pow(x,n+1))/(t*(n+1));
    for(i=1;p>=EPSILON;i++)
    {
       t*=i;
       s+=(pow(x,i))/t;
       n++;
       p=(pow(x,n+1))/(t*(n+1));
    }
    printf("gia tri = %f",s);
    getch();
}
