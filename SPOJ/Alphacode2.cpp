#include <bits/stdc++.h>
using namespace std;
int main()
{
	while(1)
	{
		string x;
		cin>>x;
		long long int l=x.size();
		bool k=true,vis[l];
		if(l==1 && x[0]=='0')
			return 0;	
		if(x[0]=='0')
			k=false;
		long long int ans=0,dp[l];
		memset(dp,0,sizeof(dp));
		memset(vis,false,sizeof(vis));
		if(x[l-1]!='0')
			dp[l-1]=1;
		else
			dp[l-1]=0;
		for(long long int i=l-2;i>=0 && k;i--)
		{	
						//1111011010111	
			if(x[i]=='0' && x[i+1]=='0')
				k=false;
			if(i==l-2)
			{
				if(x[i]=='0')
				{
					if(x[i-1]<='2' && x[i-1]>'0')
					{
						dp[i]=dp[i+1];
						i--;
						dp[i]=dp[i+1];
						vis[i]=true;
					}
				}
				else if(x[i]<'2' && x[i]>'0' || (x[i]=='2' && x[i+1]<='6'))
				{
		   			dp[i]=1+dp[i+1];
				}
		   		else
		   		{
		   			dp[i]=dp[i+1];	
		   		}
			}
			//1111011010111	
			else if(i>=0)
			{
				if(x[i+1]=='0' && x[i]<='2')
				{
					dp[i]=dp[i]+dp[i+1];
					vis[i]=true;
					// i--;
					// dp[i]=dp[i]+dp[i+1];
					// vis[i]=true;
				}
				else if(x[i+1]=='0' && x[i]>'2')
					k=false;
				//1111011010111	 6.3.3.3.3.3.3.3.3.3.3.2.1.
				else 
				{
					if(((x[i]<'2' && x[i]>'0') || (x[i]=='2' && x[i+1]<='6')) && (vis[i+1]==false) && (vis[i]==false))
					{
		   				dp[i]=dp[i]+dp[i+2];
		   			}
		   			dp[i]=dp[i]+dp[i+1];
		   		}
		   	}
		}
		// for(int i=0;i<l;i++)
		// 	cout<<dp[i]<<".";
		if(k)
			cout<<dp[0]<<endl;
		else
			cout<<0<<endl;
	}
}
