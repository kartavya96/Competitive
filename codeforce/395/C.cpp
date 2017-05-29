#include <bits/stdc++.h>
using namespace std;
vector<int> a[100001];
int b[100000],ans=-1;
bool vis[100001];
int fun(int x)
{
	vis[x]=true;
	int co;
	int count=1;
	for(int i=a[x].begin();i<a[x].end();i++)
	{
		if(count==1)
		{
			co=fun(a[x][i]);
		}
		else
		{
			int coo=fun(a[x][i]);
			if(coo==co)
				count++;
		}
	}
	if(count==a[x].size())
	{
		ans=x+1;
		return 0;
	}
}
int main()
{	
	int n;
	cin>>n;
	memset(vis,false,sizeof(vis));
	for(int i=0;i<n-1;i++)
	{
		int p,q;
		cin>>p>>q;
		p--;
		q--;
		a[p].push_back(q);
		a[q].push_back(p);
	}
	for(int i=0;i<n;i++)
		cin>>b[i];
	int co=fun(0);
	cout<<ans<<endl;
	return 0;
}		