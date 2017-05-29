#include <bits/stdc++.h>
using namespace std;
int fun(int x);
int fun2(int y);
int dp[35],dp2[35];
int main()
{
	while(1)
	{
		memset(dp,-1,sizeof(dp));
		memset(dp2,-1,sizeof(dp2));
		int n;
		cin>>n;
		if(n==-1)
			return 0;
		if(n==0)
			cout<<1<<endl;
		else if(n%2==1)
			cout<<0<<endl;
		else
		{
			cout<<fun(n)<<endl;
		}
	}
}
int fun(int x)
{
	if(x==0)
		return 1;
	if(x==1)
		return 0;
	if(x==2)
		return 3;
	if(x==3)
		return 0;
	if(dp[x]==-1)
	return(dp[x]=(fun(x-2)+2*fun2(x-1)));
	return(dp[x]);
}
int fun2(int y)
{
	if(y==0)
		return 0;
	if(y==1)
		return 1;
	if(y==2)
		return 0;
	if(dp2[y]==-1)
	return(dp2[y]=(fun(y-1)+fun2(y-2)));
	return(dp2[y]);
}