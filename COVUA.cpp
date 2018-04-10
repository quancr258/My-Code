#include<stdio.h>
int nhap(int &n)
{
	scanf("%d",&n);
}
int main()
{
	int n,i,j=1;
	nhap(n);
	while(j<=n)
	{
		for(i=1;i<=n;i++)
		{
			if((i%2==0 && j%2==0) || (i%2!=0 && j%2!=0))
				printf("W");
				else printf("B");
		}
		printf("\n");
		j++;
	}
}
