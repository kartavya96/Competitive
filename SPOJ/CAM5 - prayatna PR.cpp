#include <bits/stdc++.h>
using namespace std;
int n,e;
list<int> adj[100005];
bool vis[100005];
void dfs(int v)
{
	if(vis[v])
		return;
	vis[v]=true;
	list<int>::iterator it;
	for (it=adj[v].begin();it!=adj[v].end();++it)
    {
    	if(!vis[*it])
    		dfs(*it);
    }
    return;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>e;
		memset(vis,false,sizeof(vis));
		if(e==0)
			cout<<n<<endl;
		else
		{
			int ans=0;
			for(int i=0;i<e;i++)
			{
				int a,b;
				cin>>a>>b;
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
			for(int i=0;i<n;i++)
			{
				if(!vis[i])
				{
					ans++;
					dfs(i);
				}
			}
			cout<<ans<<endl;
		}
		for(int i=0;i<n;i++)
			adj[i].clear();
	}
	return 0;
}