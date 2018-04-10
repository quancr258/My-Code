#include <stdio.h>
#include <math.h>
int main()
{
    long long n,i,j,tong=0,tongi;
    scanf("%lld",&n);
    {
            for(i=1;i<=n/2;i++)
              if(n%i==0) tong=tong+i;
            if (tong==n) printf("YES");
            else printf("NO");
    }
}
