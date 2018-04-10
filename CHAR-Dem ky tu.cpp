#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j;
	char s[101];
	gets(s);
	n=strlen(s);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(s[i]==s[j])
			{
				s[j]=s[n-1];
				n--;i=0;
			}
			if(s[i]==s[j-1] && n==2)
			{
				n--;i=0;
			}
		}
	}
	printf("%d",n);
}
