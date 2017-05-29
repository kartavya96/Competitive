#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int a[1000];
	long long int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		long long int dp[s.size()+1];
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		memset(a,-1,sizeof(a));
		for(long long int i=1;i<=s.size();i++)
		{
			if(dp[i-1]<0)
				dp[i]=(2*(dp[i-1] + 1000000007))%1000000007;
			else
				dp[i]=(2*dp[i-1])%1000000007;

			if(a[s[i-1]]!=-1)
			{
				if(dp[i]<=dp[a[s[i-1]]])
				{
					dp[i]=(dp[i]-dp[a[s[i-1]]]);
					dp[i]=(dp[i]+1000000007)%1000000007;
					//dp[i]=dp[i];
				}
				else
				{
					dp[i]=(dp[i]-dp[a[s[i-1]]]);
					dp[i]=(dp[i]+1000000007)%1000000007;
				}
				if(dp[i]<0)
					dp[i]+=1000000007;
			}
			a[s[i-1]]=i-1;
		}
		cout<<dp[s.size()]%1000000007<<endl;
	}
	return 0;
}