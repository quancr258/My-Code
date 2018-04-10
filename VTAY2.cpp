#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
string s="";
int main()
{
	cin>>s;
	string min=s;
	for(int i=0;i<s.size();i++)
	{
		s.push_back(s[0]);
		s.erase(s.begin());
		if(s<min)
			min=s;
	}
	cout<<min;
	return 0;
}
