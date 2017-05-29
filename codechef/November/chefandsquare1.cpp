#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i+j-1>n)
					cout<<i+j-1-n<<" ";
				else
					cout<<i+j-1<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
