#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001][2],n,a[1002],sum1=0,sum2=0;
int fun(int x,int y,int check)
{
	if(x>y || x>=n || y>=n || y<0)
		return 0;
	else if(check==1)
	{
		if(dp[x][y][0]==-1)
		{
			int pp=max(a[x]+fun(x+1,y,2),a[y]+fun(x,y-1,2));
			dp[x][y][0]=pp;
			return(pp);
		}
		else
			return(dp[x][y][0]);
	}
	else if(check==2)
	{
		if(dp[x][y][1]==-1)
		{
			if(a[x]>=a[y])
			{
				int qq=-a[x]+fun(x+1,y,1);
				dp[x][y][1]=qq;
				return(qq);
			}
			else
			{
				int qq=(-a[y]+fun(x,y-1,1));
				dp[x][y][1]=qq;
				return(qq);
			}
		}
		else
			return(dp[x][y][1]);
	}
}
int main()
{
	int t=1;
	while(1)
	{
		sum1=0;
		sum2=0;
		cin>>n;
		if(n==0)
			return 0;
		memset(dp,-1,sizeof(dp));
		memset(a,-1,sizeof(a));
		for(int i=0;i<n;i++)
			cin>>a[i];
		int ans=fun(0,n-1,1);
		cout<<"In game "<<t<<", the greedy strategy might lose by as many as "<<ans<<" points."<<endl;
		t++;
	}
	return 0;
}