#include<bits/stdc++.h>
using namespace std;
bool kt(long long n);
int main()
{
	static long long n,i,a=0;
	cin>>n;
	if(n==0) cout<<10;
	else if(n<10) cout<<n;
	else if (kt(n)) cout<<-1;
	else
	{
		for(i=2;i<=9;i++)
		{
			if(n%i==0)
			{
				a=a*10+i;
				n/=i;
				i=2;
			}
			if(n==1) break;
		}
		if(n>1) cout<<-1;
		else cout<<a;	
	}
}
bool kt(long long n)
{
	if(n%2==0)return false;
	else {
		for (int i=3;i<=sqrt(n);i+=2)
		{
			if(n%i==0) return false;
		}
		return true;
	}
}
