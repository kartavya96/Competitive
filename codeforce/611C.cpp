#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	char a[n][m];
	int dp[n][m];
	dp[0][0]=0;
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i==0 && j==0)
				continue;
			if(i==0)
			{
				if(a[i][j]=='.')
				{
					if(a[i][j-1]=='.')
						dp[i][j]=dp[i][j]+1;
					else
						dp[i][j]=dp[i][j];
				}
				else
					dp[i][j]=dp[i][j];
				dp[i][j]=dp[i][j]+dp[i][j-1];
			}
			else if(j==0)
			{
				if(a[i][j]=='.')
				{
					if(a[i-1][j]=='.')
						dp[i][j]=dp[i][j]+1;
					else
						dp[i][j]=dp[i][j];
				}
				else
					dp[i][j]=dp[i][j];
				dp[i][j]=dp[i][j]+dp[i-1][j];
			}
			else
			{
				if(a[i][j]=='.')
				{
					if(a[i-1][j]=='.')
						dp[i][j]=dp[i][j]+1;
					if(a[i-1][j]=='#')
						dp[i][j]=dp[i][j];
					if(a[i][j-1]=='.')
						dp[i][j]=dp[i][j]+1;
					if(a[i][j-1]=='#')
						dp[i][j]=dp[i][j];
				}
				else
					dp[i][j]=dp[i][j];
				dp[i][j]=dp[i][j]+dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1];
			}
		}
	}
	int nn;
	cin>>nn;
	while(nn--)
	{
		int aa,b,p,q;
		cin>>aa>>b>>p>>q;
		int as=0;
		int i;
		for(i=(aa-1);i<(p-1);++i)
		{
			if(a[i][b-1]=='.' && a[i+1][b-1]=='.')
				as++;
		}
		for(i=b-1;i<q-1;i++)
		{
			if(a[aa-1][i]=='.' && a[aa-1][i+1]=='.')
				as++;
		}
		cout<<dp[p-1][q-1]-dp[p-1][b-1]-dp[aa-1][q-1]+as+dp[aa-1][b-1]<<" "<<endl;

	}
	return 0;
}