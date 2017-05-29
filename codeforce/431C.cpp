#include <bits/stdc++.h>
using namespace std;
int dp[105][2],n,k,d;
const int mod = 1e9 + 7;
int main()
{		
	cin>>n>>k>>d;
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	dp[0][1]=0;
	for(int x=1;x<=n;x++)
	{
		for(int i=1;i<=k;i++)
		{	
			if((x-i)>=0)
			{
				if(i<d)
				{
					dp[x][0]=(dp[x][0]%mod+dp[x-i][0]%mod)%mod;
					dp[x][1]=(dp[x][1]%mod+dp[x-i][1]%mod)%mod;
				}
				else
				{
					dp[x][1]=(dp[x][1]%mod+dp[x-i][1]%mod)%mod;
					dp[x][1]=(dp[x][1]%mod+dp[x-i][0]%mod)%mod;
				}
			}
			else
				break;
		}
	}
	cout<<dp[n][1]<<endl;	
	return 0;
}		