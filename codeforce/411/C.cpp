#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n%2==0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	else
	{
		cout<<(((n/2)+1))%(n+1)<<endl;
		return 0;
	}
}