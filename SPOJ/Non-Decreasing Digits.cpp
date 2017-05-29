#include <bits/stdc++.h>
using namespace std;
unsigned long long int dp[10][65];
unsigned long long int fun(unsigned long long int x,unsigned long long int y)
{
	unsigned long long int sum=0;
	if(x==0)
		return 1;
	if(y==1)
		return 1;
	if(y<=0)
		return 0;
	if(dp[x][y]==-1)
	{
		for(unsigned long long int i=0;i<=x;i++)
		{
			sum+=fun(i,y-1);
		}
		return dp[x][y]=sum;
	}
	else
		return dp[x][y];
}
int main()
{
	unsigned long long int t=0;
	cin>>t;
	memset(dp,-1,sizeof(dp));
	while(t--)
	{
		unsigned long long int sum=0;
		unsigned long long int cas,n;
		cin>>cas;
		cin>>n;
		for(unsigned long long int i=0;i<10;i++)
		{
			sum+=fun(i,n);
		}
		cout<<cas<<" "<<sum<<endl;
	}
	return 0;
}