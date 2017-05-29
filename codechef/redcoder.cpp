#include <bits/stdc++.h>
using namespace std;
long long int mod=1000000007;
long long int nextPow2(long long int n) 
{ 
    if ( n <= 1 ) return n;
    double d = n-1; 
    return 1 << ((((int*)&d)[1]>>20)-1022); 
}
long long int C(long long int n, long long int r)
{
    long long f[n + 1];
    f[0] = 1;
    for (long long int i = 1; i <= n; i++)
        f[i] = ((i%mod)*(f[i - 1]%mod)%mod);
    return ((f[n])/(f[r])/(f[n-r]))%mod;
}
long long int fac(long long int n)
{
	if(n==1)
		return 1;
	if(n==0)
		return 1;
	long long int to=(nextPow2(n));
	if(to>n)
		to=to/2;
	long long int m=1+n-to;
	long long int l=(to/2)-1+min(to/2,m);
	long long int mm=0;
	long long int r=(to/2)-1+max(mm,m-(to/2));
	return(((C(n-1,l)%mod)*(fac(l)%mod)*(fac(r)%mod))%mod);
}
int main()
{
	long long int t,n,m,ans;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		long long int ans=fac(n);
		if(ans==m)
			cout<<"correct"<<endl;
		else
			cout<<"incorrect"<<endl;
	}
	return 0;
}
