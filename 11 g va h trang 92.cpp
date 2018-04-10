#include <stdio.h>
#include <math.h>
int main()
{
	int i,n,tong=0,gt=1;
	float s1=0,s2=0;
	printf("nhap vao so n = ");
	scanf("%d",&n);
	while(n<1)
	{
		printf("nhap vao so n = ");
		scanf("%d",&n);
	}
	for(i=1;i<=n;i++)
	{
		//câu g
		tong = tong + i;
		s1 = s1 + 1.0/tong;
		//câu h
		gt=gt*i;
		s2 = s2 + pow(-1,i+1)*exp(i)/gt;
	}
	printf("\n g. Tong S(g) = %f",s1);
	printf("\n h. Tong S(h) = %f",s2);
}
