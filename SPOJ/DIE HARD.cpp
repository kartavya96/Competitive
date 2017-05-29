#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010][4];
int solve(int a,int b,int check)
{
    if(a<=0 || b<=0)
        return 0;
    if(dp[a][b][check]!=-1)
        return dp[a][b][check];
    else if(dp[a][b][check]==-1 )
    {
        if(check==0)
            return(dp[a][b][check]=max(solve(a+3,b+2,1),max(solve(a-5,b-10,2),solve(a-20,b+5,3))));
        else if(check==1)
            return(dp[a][b][check]=max(solve(a-5,b-10,2)+1,solve(a-20,b+5,3)+1));
        else if(check==2)
            return(dp[a][b][check]=max(solve(a+3,b+2,1)+1,solve(a-20,b+5,3)+1));
        else
            return(dp[a][b][check]=max(solve(a+3,b+2,1)+1,solve(a-5,b-10,2)+1));

    }
    return 0;

}
int main() 
{
    int t;
    cin>>t;
    while (t--) 
    {
        int h,a;
        memset(dp,-1,sizeof(dp));
        cin>>h>>a;
        cout<<solve(h,a,0)<<endl;
    }
  return 0;
}