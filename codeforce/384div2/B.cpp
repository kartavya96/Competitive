#include <bits/stdc++.h>
using namespace std;
long long int n,k,d;
int main()
{		
	cin>>n>>k;
	if((k%2)!=0)
		cout<<1<<endl;
	else
	{
		if(pow(2,n-1)==k)
			cout<<(n);
		else
		{
			for(int i=2;i<n;i++)
			{
				if(k==(pow(2,i-1)))
				{
					cout<<i<<endl;
					return 0;
				}
			
			}
			for(int i=2;i<n;i++)
			{
				long long int f=pow(2,i),g=pow(2,i-1);
				if((k-g)%(f)==0 && (k-g)>0)
				{
					cout<<i<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}		