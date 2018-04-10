#include <stdio.h>
#include <string.h>
int main()
{
	int mk=0,n,j,i,s1;
	char s[300];
	gets(s);
	n = strlen(s);
	for(j=0;j<n;j++)
	{
		s1= s[j];
		mk += (s1-48);
	}
	printf("%d",mk);
}
