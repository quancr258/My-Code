#include<bits/stdc++.h>
using namespace std;
int main()
{
	static long long n,s,t;
	cin>>n;
	s=n;
	while(s>0)
	{
		t+=s%10;
		s/=10;
	}
	if(n%t==0) cout<<1;
	else cout<<0;
}
