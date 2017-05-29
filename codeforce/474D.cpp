#include <cstdio>
#include <cstring>
#include <bits/stdc++.h> 
using namespace std;
long long int t,k,a[100010];
long long int cal(long long int x)
{        
        if(x<k)
            return a[x]=1;
        if(a[x]!=-1)
            return a[x];

            return a[x]=((cal(x-k)+cal(x-1)))%1000000007;
}         
int main()
{        
    cin>>t>>k;
    memset(a,-1,sizeof(a));
    a[0]=0;
    for(long long int i=1;i<100010;i++)
    {   
        cal(i);
    }   
    //     for(long long int i=1;i<10;i++)
    // {   
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    for(long long int i=1;i<100010;i++)
    {   
        a[i]=(a[i-1]+a[i])%1000000007;
    }
    // for(long long int i=1;i<10;i++)
    // {   
    //     cout<<a[i]<<" ";
    // }   
    long long int c,b;
    while(t--)
    {   
        cin>>c>>b;
        cout<<(a[b]-a[c-1]+1000000007)%1000000007<<endl;
    }                         
    return 0;
}