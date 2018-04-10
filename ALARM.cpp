#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[]={6,2,5,5,4,5,6,3,7,6},h,m,n,d=0;
	cin>>n;
	for(h=0;h<24;h++)
	{
		for(m=0;m<60;m++)
		{
			if(a[h/10]+a[h%10]+a[m/10]+a[m%10]==n)
			{
				cout<<h/10<<h%10<<":"<<m/10<<m%10;
				d=1;
				break;
			}
		}
		if(d==1) break;
	}
	if(d==0) cout<<"Impossible";
}
