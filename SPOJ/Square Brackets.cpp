#include <bits/stdc++.h>
using namespace std;
#define md 100000
long long int dp[202][202],n;
bool vis[202][202],f=0;
char a[202];
long long int fun(long long int p,long long int q)
{
	long long int r=0;
	//cout<<p<<" "<<q<<" "<<r<<endl;
	if(vis[p][q])
		return dp[p][q];
	if(p>q)
		return 1;
	if(a[p]==']' || a[q]=='[')
		return 0;
	if((q-p)==1)
		return 1;
	if(p==q)
		return 0;
	for(long long int i=p+1;i<=q;i++)
	{
		if(a[p]=='?')
		{
			if(a[i]=='?')
			{
				r+=fun(p+1,i-1)*fun(i+1,q);
			}
			else if(a[i]==']')
			{
				r+=fun(p+1,i-1)*fun(i+1,q);
			}
		}
		else
		{
			if(a[p]=='[' && a[i]==']')
				r+=fun(p+1,i-1)*fun(i+1,q);
			else if(a[i]=='?')
				r+=fun(p+1,i-1)*fun(i+1,q);
		}
		i++;
	}
	vis[p][q]=true;
	return (dp[p][q]=r);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,'?',sizeof(a));
		int k;
		cin>>n;
		cin>>k;
		int pos[k];
		n=2*n;
		for(int i=0;i<k;i++)
		{
			cin>>pos[i];
			a[pos[i]-1]='[';
		}
		// for(int i=0;i<n;i++)
		// {
		// 	cout<<a[i];
		// }
		memset(dp,0,sizeof(dp));
		memset(vis,false,sizeof(vis));
		long long int r=fun(0,n-1);	
		cout<<r<<endl;
	}
	return 0;
}