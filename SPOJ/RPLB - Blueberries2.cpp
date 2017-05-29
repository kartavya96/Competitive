#include <bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[1005],dp[1005][1005][2];
int fun(int x,int c,int w)
{
	if(x<0)
		return 0;
	if(c==0)
	{
		if(dp[x][w][0]!=-1)
			return dp[x][w][0];
		return(dp[x][w][0]=max(fun(x-1,0,w),fun(x-1,1,w)));
	}
	if(c==1)
	{
		if(dp[x][w][1]!=-1)
			return dp[x][w][1];
		if(w-a[x]>=0)
			return(dp[x][w][1]=max(a[x]+fun(x-2,0,w-a[x]),a[x]+fun(x-2,1,w-a[x])));
		return(dp[x][w][1]=max(fun(x-2,0,w),fun(x-2,1,w)));
	}
}
int main()
{
	int t,i=1;
	cin>>t;
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		cin>>n>>k;
		for(int i=0;i<n;i++)
			cin>>a[i];
		cout<<"Scenario #"<<i<<": "<<max(fun(n-1,0,k),fun(n-1,1,k))<<endl;
		i++;
	}
}
 	