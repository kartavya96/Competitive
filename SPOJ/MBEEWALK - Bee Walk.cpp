#include <bits/stdc++.h>
using namespace std;
int dx[6]={-1,0,1,1,0,-1},dy[6]={1,1,-1,0,-1,0};
int main()
{
	int t;
	cin>>t;
	static int dp[15][41][41]={0};
	dp[0][20][20]=1;
	for(int m=1;m<=14;m++)
	{
		for(int k=1;k<40;k++)
		{
			for(int i=1;i<40;i++)
			{
				for(int j=0;j<6;j++)
				{
					dp[m][k][i]+=dp[m-1][k+dx[j]][i+dy[j]];
				}
			}
		}
		for(int k=1;k<40;k++)
		{
			for(int i=1;i<40;i++)
			{
				cout<<dp[m][k][i]<<" ";
			}
			cout<<endl;
		}






		cout<<endl;
	}
	while(t--)
	{
		int n;
		cin>>n;
		cout<<dp[n][20][20]<<endl;
	}
}
