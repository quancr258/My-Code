#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
	char s[10000];
	long d=0,n,i,j,a[10000];
	gets(s);
	n=strlen(s);
	switch(s[0])
		{
			case 'I': a[0]=1;break;
			case 'V': a[0]=5;break;
			case 'X': a[0]=10;break;
			case 'L': a[0]=50;break;
			case 'C': a[0]=100;break;
			case 'D': a[0]=500;break;
			case 'M': a[0]=1000;break;
		}
	if(n==1) d+=a[0];
	else
	{
		for(i=1;i<n;i++)
		{
			switch(s[i])
			{
				case 'I': a[i]=1;break;
				case 'V': a[i]=5;break;
				case 'X': a[i]=10;break;
				case 'L': a[i]=50;break;
				case 'C': a[i]=100;break;
				case 'D': a[i]=500;break;
				case 'M': a[i]=1000;break;
			}
			if(a[i]>a[i-1]) d-=a[i-1];
			else d+=a[i-1];
			if(i==n-1) d+=a[i];
		}
	}
	cout<<d;
}
