#include <bits/stdc++.h>
using namespace std;
long long int n,x[2005],dp[2005][2005];
int su(int age,int p,int q)
{
	if(p>q)
		return 0;
	if(dp[p][q]!=-1)
		return dp[p][q];
	return(dp[p][q]=max(su(age+1,p+1,q)+(x[p]*age),su(age+1,p,q-1)+(x[q]*age)));
}
int main()
{			
	cin>>n; 
	long long int p=1,q=n;
	x[0]=0;
	for(long long int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	for(long long int i=0;i<=n;i++)
		for(long long int j=0;j<=n;j++)
			dp[i][j]=-1;

	cout<<su(1,1,n);
	return 0;
}
