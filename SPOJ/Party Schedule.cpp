#include <bits/stdc++.h>

using namespace std;
int cmp(pair<long long int,long long int> a,pair<long long int,long long int> b)
{
    if(a.first>b.first)
        return false;
    else if(a.first==b.first)
    {
        if(a.second>b.second)
            return true;
        return false; 
    }
    else
        return true;
}
int main()
{
    long long int x,y;
        cin>>x>>y;
        if(x==0 && y==0)
            return 0;
    while(1)
    {
        long long int mx=-1,an=-1;
        pair<long long int,long long int> a[y];
        long long int dp[y+1][x+1];
         for(long long int i=0;i<y;i++)
         {
             long long int p,q;
             cin>>p>>q;
             a[i].first=p;
             a[i].second=q;
        }
        sort(a,a+y,cmp);    
        for(long long int i=0;i<y+1;i++)
        {
            for(long long int j=0;j<x+1;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;

                else if(j<a[i-1].first)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=max((dp[i-1][j-a[i-1].first]+a[i-1].second),dp[i-1][j]);
            }
        }
        for(long long int i=1;i<x+1;i++)
        {
                if(dp[y][i]==dp[y][x])
                {
                    an=i;
                    break;
                }
        }
        cout<<an<<" "<<dp[y][x];
        cin>>x>>y;
        if(x==0 && y==0)
            return 0;
        cout<<endl;
    }
    return 0;
}