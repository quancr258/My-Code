#include <stdio.h>
#include <string.h>
int main()
{
    int n,k,i;
    char q[250];
    gets(q);
    scanf("%d",&k);
    n=strlen(q);
    for(i=k-1;i>=0;i--)
    {
    	printf("%c",q[i]);
	}
    for(i=n-1;i>=k;i--)
    {
    	printf("%c",q[i]);
	}
}
