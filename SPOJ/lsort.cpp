#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n],p[n+1],dp[n+1][n+1],w1[n+1][n+1],w2[n+1][n+1];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			p[a[i]]=i+1;
		}
		for(int i=1;i<=n;i++)
		{
			w1[i][i]=p[i];
			for(int j=i+1;j<=n;j++)
			{
				w1[i][j]=w1[i][j-1]-(p[j] < p[i] ? 1 : 0);
			}
		}
		for(int i=1;i<=n;i++)
		{
			dp[i][i]=p[i];
			w2[i][i]=p[i];
			for(int j=i-1;j>=1;j--)
			{
				w2[i][j]=w2[i][j+1]-(p[j] < p[i] ? 1 : 0);
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i+k<=n;i++)
			{
				int j=i+k;
				int n=k+1;
				dp[i][j]=min(dp[i+1][j]+(n)*w1[i][j],dp[i][j-1]+(n)*w2[j][i]);
			}
		}
		cout<<dp[1][n]<<endl;
	}
	return 0;
}