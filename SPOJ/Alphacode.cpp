#include <bits/stdc++.h>
using namespace std;
int main()
{
	while(1)
	{
		string x,y;
		cin>>x;
		if(x.size()==1 && x[0]=='0')
			return 0;	
		char a[2];
		bool k=true,vis[x.size()];
		memset(vis,false,sizeof(vis));
		long long int j=0;
		if(x[0]=='0')
			k=false;
		for(long long int i=0;i<x.size()-1 && k==true;i++)
		{
			if(x[i]=='0' && x[i+1]=='0')
			{
				k=false;
			}
		} 
		for(long long int i=0;i<x.size()-1 && k==true;i++)
		{
			if(x[i+1]=='0')
			{
				if(x[i]<='2')
				{
					y[j]='9';
					vis[j]=true;
					j++;
					i++;
				}
				else
					k=false;
			}
			else
			{
				y[j]=x[i];
				j++;
			}
		} 
		if(x[x.size()-1]!='0' && k==true)
		{
			y[j]=x[x.size()-1];
			j++;
		}
		if(k==true)
		{
			long long int ans=0,dp[j];
			memset(dp,0,sizeof(dp));
			dp[0]=1;
			for(long long int i=1;i<j ;i++)
			{	
				if(i==1)
				{
					a[0]=y[i-1];
					a[1]=y[i];
					if(((a[0]<'2' || (a[0]=='2' && a[1]<='6')) && (vis[i]==0)))
		   				dp[i]=2;
		   			else
		   				dp[i]=1;	
					}
				else
				{
					a[0]=y[i-1];
					a[1]=y[i];
					if(((a[0]<'2' || (a[0]=='2' && a[1]<='6')) && (vis[i]==0)))
		   				dp[i]=dp[i]+dp[i-2];
		   			dp[i]=dp[i]+dp[i-1];	
				}
			}
			cout<<dp[(j-1)]<<endl;
		}
		else
			cout<<0<<endl;
	}
}
