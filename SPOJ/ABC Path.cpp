#include <bits/stdc++.h>
using namespace std;
int ans=0,n,m;
char a[55][55];
int vis[55][55];
int dx[8]={0,1,-1,0,1,-1,1,-1};
int dy[8]={1,0,0,-1,1,-1,-1,1};
void dfs(int sx,int sy,char c)
{
	ans=max(ans,int(c-'A'));
	for(int i=0;i<8;i++)
	{
		if(sx+dx[i]<n && sy+dy[i]<m && sx+dx[i]>=0 && sy+dy[i]>=0 && !vis[sx+dx[i]][sy+dy[i]])
		{
			if(int(a[sx+dx[i]][sy+dy[i]]-a[sx][sy])==1)
			{
				vis[sx+dx[i]][sy+dy[i]]=1;
				sx=sx+dx[i];
				sy=sy+dy[i];
				c=a[sx][sy];
				dfs(sx,sy,c);
			}
		}
	}
	return;
}
int main()
{
	int cas=0;
	while(1)
	{
		ans=0;
		int sx,sy;
		cin>>n>>m;
		vector<pair<int, int> > v;
		if((n==0 && m==0))
			break;
		else
		{
			cas++;
			bool check=false;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					cin>>a[i][j];
					vis[i][j]=0;
					if(a[i][j]=='A')
					{
						check=true;
						sx=i;
						sy=j;
						v.push_back(make_pair(sx,sy));
					}
				}
			}
			char c='A';
			if(check)
			{
				for(int i=0;i<v.size();i++)
				{
					sx=v[i].first;
					sy=v[i].second;
					vis[sx][sy]=1;
					c=a[sx][sy];
					dfs(sx,sy,c);
				}
				cout<<"Case "<<cas<<": "<<ans+1<<endl;
			}
			else
				cout<<"Case "<<cas<<": "<<ans<<endl;
		}
	}
	return 0;
}