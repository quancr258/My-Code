#include<bits/stdc++.h>
#define MAX 100000
using namespace std;
int main()
{
	long long a[MAX],t,d=0,i,j,n,k;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
 	}
 	sort(a,a+n);
 	for(i=0;i<n;i++)
		{
			t=a[i]+k;
			for(j=i+1;j<n;j++)
			{
				if(t<a[j])
					break;
				if(a[j]==t)
					{
						d++;
					}
			}
		}
	cout<<d;
}
