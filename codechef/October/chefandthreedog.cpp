#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
int main()
{
	long double t,ans=0;
	long long int L,v;
	cin>>t;
	while(t--)
	{
		cin>>L>>v;
		long double p=2*L;
		long double q=3*v;
		ans=p/q;
		cout<<setprecision(30)<<ans<<endl;
	}
	return 0;
}