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
	if(a[p]==']' || a[p]=='}' || a[p]==')' || a[q]=='{' || a[q]=='[' || a[q]=='(')
		return 0;
	if((q-p)==1)
	{
		if(a[p]=='?' && a[q]=='?')
			return 3;
		return 1;
	}
	if(p==q)
		return 0;
	for(long long int i=p+1;i<=q;i++)
	{
		if(a[p]=='?')
		{
			if(a[i]=='?')
			{
				r+=3*fun(p+1,i-1)*fun(i+1,q);
				// if(r>md) 
				// {
				// 	f=1;
				// 	r%=md;
				// }
			}
			else if(a[i]==')' || a[i]==']' || a[i]=='}')
			{
				r+=fun(p+1,i-1)*fun(i+1,q);
				// if(r>md) 
				// {
				// 	f=1;
				// 	r%=md;
				// }
			}
		}
		else
		{
			if(a[p]=='{' && a[i]=='}')
				r+=fun(p+1,i-1)*fun(i+1,q);
			else if(a[p]=='(' && a[i]==')')
				r+=fun(p+1,i-1)*fun(i+1,q);
			else if(a[p]=='[' && a[i]==']')
				r+=fun(p+1,i-1)*fun(i+1,q);
			else if(a[i]=='?')
				r+=fun(p+1,i-1)*fun(i+1,q);
			// if(r>md) 
			// 	{
			// 		f=1;
			// 		r%=md;
			// 	}
		}
		i++;
	}
	vis[p][q]=true;
	return (dp[p][q]=r);
}
int main()
{
	cin>>n;
	cin>>a;
	memset(dp,0,sizeof(dp));
	memset(vis,false,sizeof(vis));
	long long int r=fun(0,n-1);
	// for(long long int i=0;i<n;i++)
	// {
	// 	for(long long int j=0;j<n;j++)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }	
	printf(f?"%05d\n":"%d\n",r);
	return 0;
}