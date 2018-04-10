#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	int i,t,n,h=0,e=0,l=0,o=0;
	char a[100];
	gets(a);
	t=strlen(a);
	for(i=0;i<t;i++)
	{
		n=a[i];
		if((n==72 || n==104) && h!=1)
			h=1;
		if((n==69 || n==101) && h==1 && e!=1)
			e=1;
		if((n==76 || n==108) && h==1 && e==1 && l!=2)
			l++;
		if((n==79 || n==111) && h==1 && e==1 && l==2 && o!=1)
			o=1;
	}
	if(h==1 && e==1 && l==2 && o==1) printf("YES");
	else printf("NO");
}
