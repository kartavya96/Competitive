#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s,s1;
		cin>>s;
		s1=s;
		reverse(s1.begin(),s1.end());
		int le=s.size();
		int dp[le+1][le+1];
		memset(dp,0,sizeof(dp));
		for(int i=0;i<le+1;i++)
		{
			for(int j=0;j<le+1;j++)
			{
				if(i==0 || j==0)
					dp[i][j]=0;
				else if(s[i-1]==s1[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout<<le-dp[le][le]<<endl;
	}
	return 0;
}