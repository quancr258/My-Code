#include <stdio.h>
int main()
{
    int n,i;
    long long gt=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
           gt=gt*i;
    printf("%lld",gt);
}
