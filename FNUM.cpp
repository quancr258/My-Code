#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
	char s[1000000];
	long long t=0,n;
	gets(s);n=strlen(s);
	for(long long i=0;i<n;i++)
	{
		t+=s[i]-48;
	}
	while(t>9)
	{
		n=t/10;
		t=t%10+n;
	}
	cout<<t;
}
