#include <stdio.h>
#include <math.h>
int main()
{
    long long m,n,t,l,k,s;
    scanf("%lld%lld%lld",&m,&n,&t);
    l=n/(m+1);
    k=n%(m+1);
    s=k*t+l*m*t;
    printf("%lld",s);
}    
