#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	static long long k,t[1000000],p[1000000],i,j=0,tt=0;
	cin>>k;
	for(i=0;i<k;i++)
	{
		cin>>t[i];
	}
	sort(t,t+k);
	for(i=0;i<k;i++)
	{
		p[j]++;
		if(t[i]!=t[i+1])
		{
			if(p[j]<=5) tt+=100;
			else tt+=100+p[j]-5;
			j++;
		}
	}
	cout<<tt;
}
