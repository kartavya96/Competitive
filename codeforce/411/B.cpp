#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<'a';
		return 0;
	}
	char a[n];
	a[0]='a';
	a[1]='b';
	cout<<"ab";
	for(int i=2;i<n;i++)
	{
		if(a[i-2]!='a')
		{
			a[i]='a';
			cout<<'a';
		}
		else if(a[i-2]!='b')
		{
			a[i]='b';
			cout<<'b';
		}
	}
}