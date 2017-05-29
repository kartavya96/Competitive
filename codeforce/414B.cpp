#include <bits/stdc++.h>
using namespace std;
const long long int MOD=1000000007;
int main()
{
    long long int n,k;
    cin>>n>>k;
    long long int dp[k+1][n+1];
    memset(dp,0,sizeof(dp));
    for(long long int i=1;i<=n;i++)
        dp[1][i]=1;
    for(long long int i=1;i<k;i++)
    {
        for(long long int j=1;j<=n;j++)
        {
             for(int t=1;j*t<=n;t++)
            {
                dp[i+1][j*t]+=dp[i][j];
                dp[i+1][j*t]%=MOD;
            }
        }
    }
    long long int s=0;
    for(int i=1;i<=n;i++)
        s+=dp[k][i];
    s%=MOD;
    cout<<s<<endl;
    return 0;
}