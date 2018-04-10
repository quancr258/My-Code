#include <stdio.h>
#include <conio.h>
int main()
{
    int i;
    float n;
    i=0;
    n=0.1;
    while (n<=1000)
    {
        i++;
        n=n*2;
    }
    printf ("phai gap %d, %f lan de to giay co do day 0.1mm thanh 1m",i,n);
    getch();
}
