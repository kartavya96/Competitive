#include <bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[1005],dp[1005][1005];
int fun(int x,int w)
{
	if(x>n-1)
		return w;
	if(dp[x][w]!=-1)
		return dp[x][w];
	if(w+a[x]<=k)
		return(dp[x][w]=max(fun(x+2,w+a[x]),fun(x+1,w)));
	return(dp[x][w]=fun(x+1,w));
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
		cout<<"Scenario #"<<i<<": "<<fun(0,0)<<endl;
		i++;
	}
}
