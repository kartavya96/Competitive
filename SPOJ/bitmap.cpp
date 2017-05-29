#include <bits/stdc++.h>

using namespace std;
long long int m,n,in[190][190],ou[190][190];
bool vis[190][190];
long long int xx[4]={-1,0,1,0};
long long int yy[4]={0,-1,0,1};
void bfs()
{
    queue<pair<long long int, long long int> >q;
    queue<long long int> dis;
    for(long long int i=0;i<n;i++)
    {
        for(long long int j=0;j<m;j++)
        {
            if(in[i][j]==1)
            {
                ou[i][j]=0;
                q.push(make_pair(i,j));
                dis.push(0);
                vis[i][j]=true;
            }
        }
    }
    while(!q.empty())
    {
        pair<long long int, long long int> temp;
        temp=q.front();
        q.pop();
        long long int diss=dis.front();
        dis.pop();
        long long int x=temp.first;
        long long int y=temp.second;
        for(long long int i=0;i<4;i++)
        {
            long long int x1=x+xx[i];
            long long int y1=y+yy[i];
            if(x1<n && y1<m && x1>=0 && y1>=0 && !vis[x1][y1])
            {
                vis[x1][y1]=true;
                q.push(make_pair(x1,y1));
                ou[x1][y1]=diss+1;
                dis.push(diss+1);
            }
        } 
    }
    return;
}
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        char aa[n][m];
        for(long long int i=0;i<n;i++)
        {
            for(long long int j=0;j<m;j++)
            {
                cin>>aa[i][j];
                if(aa[i][j]=='1')
                    in[i][j]=1;
                else
                    in[i][j]=0;
            }
        }
        memset(ou,0,sizeof(ou));
        memset(vis,false,sizeof(vis));
        bfs();
        for(long long int i=0;i<n;i++)
        {
            for(long long int j=0;j<m;j++)
            {
                cout<<ou[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}