#include <bits/stdc++.h>
using namespace std;
long long int n;
long long int a[10005],dp[10005];
int main()
{
	long long int t;
	cin>>t;
	long long int kk=1;
	while(t--)
	{
		cin>>n;
		for(long long int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		memset(dp,-1,sizeof(dp));
		dp[0]=a[0];
		dp[1]=max(dp[0],a[1]);
		for(int i=2;i<n;i++)
		{
			dp[i]=max(dp[i-1],dp[i-2]+a[i]);
		}
		cout<<"Case "<<kk<<": "<<dp[n-1]<<endl;
		kk++;
	}
	return 0;
}