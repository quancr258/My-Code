#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t,i,x,y,c;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>x>>y>>c;
		if(2*x*y>c*c) cout<<"SAFE"<<endl;
		else cout<<"DANGER"<<endl;
	}
}
