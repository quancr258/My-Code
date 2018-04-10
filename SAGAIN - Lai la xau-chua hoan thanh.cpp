#include<stdio.h>
#include<string.h>
int main()
{
	int k,i,j,n,l,d=0;
	char s[2000000],a[1],b[1],c[1],e[1];
	scanf("%d",&k);
	scanf("%s",&s);
	n=strlen(s);
	if(n<=k) printf("-1");
	else
	{
		if(k==1) printf("%c",s[0]);
		else
		{
		for(i=0;i<k/2;i++)
			for(j=k-1;j>=k/2;j--)
			{
				if(s[i]==s[j])
				{
					c[i]=s[i];e[i]=s[j];
					strcat(c,a);
					strcat(e,b);
					d+=2;
				}
			}
		if(d==k && k%2==0)
		{
			strrev(b);
			strcat(b,a);
			printf("%s",a);
		}
		else if(d==k-1 && k%2!=0)
		{
			c[i]=s[i];
			strrev(b);
			strcat(c,a);
			strcat(b,a);
			printf("%s",a);
		}
		else printf("-1");
		}
	}
}
