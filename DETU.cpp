#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	int n,i,t[100],j=0,d=0,m=0;
    char a[100];
    gets(a);
    n=strlen(a);
    for(i=0;i<n;i++)
    {
    	t[j]=a[i];
    	if(i==n-1 && t[j]!=46) d++;
    	else if(t[j]!=46) m+=t[j];
    	else if(t[j]==46)
    	{
    		if(m>46) {d++;m=0;}
		}
		j++;
	}
	printf("%d",d);
}
