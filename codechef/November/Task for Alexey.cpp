#include <bits/stdc++.h>
using namespace std;
long long int lcm(long long int n1,long long int n2)
{
	long long int hcf,lc;
	hcf=__gcd(n1,n2);
    lc = (n1*n2)/hcf;
    return(lc);
}
int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		long long int ans=-1,a[n];
		for(long long int i=0;i<n;i++)
			cin>>a[i];
		for(long long int i=0;i<n-1;i++)
		{
			for(long long int j=i+1;j<n;j++)
			{
				long long int hh=lcm(a[i],a[j]);
				if(ans==-1)
					ans=hh;
				else
				{
					if(ans>hh)
						ans=hh;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}