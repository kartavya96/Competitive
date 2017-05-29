#include <bits/stdc++.h>
using namespace std;
int main()
{			
	long long int n;  
	cin>>n; 
	long long int x[n+1],sum=0,p=1,q=n;
	x[0]=0;
	for(long long int i=1;i<=n;i++)
		cin>>x[i];
	for(long long int i=1;i<=n;i++)
	{
		if(q>=p)
		{
			if(x[p]>=x[q])
			{
				sum=sum+i*x[q];
				q--;
			}
			else
			{
				sum=sum+i*x[p];
				p++;
			}
		}
	}
	cout<<sum;
	return 0;
}
