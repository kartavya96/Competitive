#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
const int maxn=100010;

int n,x[maxn],h[maxn],dp[maxn][3];

int main()
{
    //freopen("in.txt","r",stdin);
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%d%d",&x[i],&h[i]);
        }                       
        if(n<=2){               
            printf("%d\n",n);   
            continue;           
        }                       
        x[n+1]=INT_MAX;         
        memset(dp,0,sizeof(dp));
        dp[1][0]=0;             
        dp[1][1]=1;                 
        if(x[1]+h[1]<x[2]) dp[1][2]=1;
        for(int i=2;i<=n;i++){      
            //ith tree stay at position
            dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
            //cut ith to left, must 
            if(x[i]-h[i]>x[i-1]) 
                dp[i][1]=max(dp[i][1],max(dp[i-1][0],dp[i-1][1])+1);
            if(x[i]-h[i]>x[i-1]+h[i-1]) 
                dp[i][1]=max(dp[i][1],dp[i-1][2]+1);
            //cut ith tree to right, must
            if(x[i]+h[i]<x[i+1]){   
                dp[i][2]=max(dp[-i1][0],max(dp[i-1][1],dp[i-1][2]))+1;
            }                       
        }                           
        int ans=max(dp[n][0],max(dp[n][1],dp[n][2]));
        printf("%d\n",ans);     
    }                                       
    return 0;
}