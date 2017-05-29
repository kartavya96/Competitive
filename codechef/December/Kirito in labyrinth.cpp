#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005],dp[100005],dp2[100005];
int hcf(int n1,int n2)
{
	if(n2==0)
		return(n1);
	else
	{
		while(n1 != n2)
		{
			if(n1 > n2)
				n1 -= n2;
			else
				n2 -= n1;
		}
		return(n1);
	}
}
int holi(int x,int value)
{
	if(x>=n)
		return 0;
	if(dp[x]!=-1 && dp2[x]==value)
		return(dp[x]);
	int hh=0,gg=0;
	if(hcf(a[x],value)>1)
	{
		hh=holi(x+1,a[x])+1;
	}
	gg=holi(x+1,value);
	dp2[x]=value;
	return(dp[x]=max(hh,gg));
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<n;i++)
			cin>>a[i];
		cout<<holi(0,0)<<endl;
	}
	return 0;
}