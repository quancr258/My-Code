#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,i;
	cin>>n;
	if(n%2==0) cout<<"-1";
	else
	{
		for(i=1;i<=n;i++)
		{
			cout<<i<<" ";
		}
	}
}
