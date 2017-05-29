#include <bits/stdc++.h>
using namespace std;
long long int n,a[105],dp[105][105],dps[105];
long long int getit(long long int p,long long int q)
{
if(p==q)
	return 0;
long long int mi=10000000,hh;
for(long long int k=p;k<q;k++)
{
	if(dp[p][k]==-1)
		dp[p][k]=getit(p,k);
	if(dp[k+1][q]==-1)
		dp[k+1][q]=getit(k+1,q);
	hh=dp[p][k]+dp[k+1][q]+((dps[k]-dps[p]+a[p])%100)*((dps[q]-dps[k+1]+a[k+1])%100);
	if(hh<=mi)
		mi=hh;
}
return(mi);
}
int main()
{		
while(scanf("%d",&n)>0)
{
	memset(dp,-1,sizeof(dp));
	memset(dps,-1,sizeof(dps));
	memset(a,-1,sizeof(a));
	for(long long int i=0;i<n;i++)
		cin>>a[i];
	long long int sum=0;
	for(long long int i=0;i<n;i++)
	{
		sum+=a[i];
		dps[i]=sum;
	}
	cout<<getit(0,n-1)<<endl;
}
return 0;
}		