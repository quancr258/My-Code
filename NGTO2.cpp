#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<bool> a(10000000,true);
bool snt();
int main()
{
	static long long i,j,n;
	cin>>n;
	snt();
	for(i=2;i<=10000000;i++)
		{
			if(a[i]==true) 
			{
				j++;
				if(j==n) break;
			}
		}
	cout<<i;
}
bool snt()
{
	long long i,j;
	for(i=2;i<=sqrt(10000000);i++)
		{
			if(a[i])
			{
				for(j=i*i;j<=10000000;j+=i)
				a[j]=false;
			}
		}
}
