#include <bits/stdc++.h>
using namespace std;
int sum[200];
int l;
string n;
int a[200][200];
int dp[200][200];
int fun(int x,int y)
{
	if(x==y)
	{
		if(n[x]=='0')
			return 0;
		else
			return 1;
	}
	if(a[x][y]>0)
		return(y-x+1);
	int ans=0;
	if(dp[x][y]==-1)
	{
		for(int i=x;i<y;i++)
		{
			if(a[x][i]>0)
			{
				if(a[i+1][y]>0)
					ans=max(ans,y-x+1);
				else
					ans=max(ans,fun(i+1,y)+i-x+1);
			}
			else
			{
				if(a[i+1][y]>0)
					ans=max(ans,fun(x,i)+y-i);
				else
					ans=max(ans,fun(x,i)+fun(i+1,y));
			}
		}
		return (dp[x][y]=ans);
	}
	else
		return (dp[x][y]);
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		memset(sum,0,sizeof(sum));
		memset(a,0,sizeof(a));
		cin>>l;
		cin>>n;
		if(n[0]=='0')
			sum[0]=-1;
		else
			sum[0]=+1;
		for(int i=1;i<l;i++)
		{
			if(n[i]=='0')
				sum[i]=sum[i-1]-1;
			else
				sum[i]=sum[i-1]+1;
		}
		for(int i=0;i<l;i++)
		{
			for(int j=0;j<l;j++)
			{
				int h;
				if(n[i]=='0')
					h=-1;
				else
					h=1;
				a[i][j]=sum[j]-sum[i]+h;
			}
		}
		cout<<fun(0,l-1)<<endl;
	}
	return 0;
}
