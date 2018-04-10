#include <stdio.h>
#include <math.h>
int main()
{
    long long a,b,i,j,tong=0,tongi=0;
    scanf("%lld%lld",&a,&b);
    {
            for(i=1;i<=a/2;i++)
              if(a%i==0) tong+=i;
            for(i=1;i<=b/2;i++)
              if(b%i==0) tongi+=i;
            if (tong==b && tongi==a) printf("YES");
            else printf("NO");
    }
}
