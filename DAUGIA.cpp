#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,t=0,k,l,d=0,i,j;
	cin>>a>>b;
	for(i=a;i<=b;i++)
	{
		k=i;l=0;
		while(k>0)
		{
			l=l*10+k%10;
			k/=10;
		}
		if(i==l)
		{
			for(j=2;j<=sqrt(i);j++)
			{
				if(i%j==0) t=1;
			}
			if(t==0)
			{
				d++;
			}
		}
		t=0;
	}
	cout<<d;
}
