#include <stdio.h>
int main()
{
    int n,i,so_thu_1=1,so_thu_2=1,t=3;
    scanf("%d",&n);
    printf("%d %d ",so_thu_1,so_thu_2);
    for(i=1;t<=n;i++)
    {
        if(i==(so_thu_1+so_thu_2))
        {
            printf("%d ",i);
            so_thu_1=so_thu_2;
            so_thu_2=i;
            t++;
        }
    }
}
