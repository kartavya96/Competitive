#include <bits/stdc++.h>
using namespace std;
long long int n;
long long int b[100005];
vector<pair<long long int,bool> > d;
long long int ans(long long int s)
{
	if(s==0)
		return b[0];
	else if(s==-1)   
		return 0;
	if(d[s].second==false)
	{
		long long int p=ans(s-1);
 		long long int q=(s+1)*b[s]+ans(s-2);
		//cout<<d[s].first<<endl;
		d[s].second=true;
 		return (d[s].first=max(p,q)); 
 	}
 	else
 		return (d[s].first);
}
int main()
{
	cin>>n;
	long long int a[n],ma=-1;
	memset(b,0,sizeof(b));
	for(long long int i=0;i<n;i++)
	{
		cin>>a[i];
		long long int c=a[i];
		b[c-1]++;
		if(c>ma)
			ma=c;
	}
	for(long long int i=0;i<=ma;i++)
		d.push_back(make_pair(0,false));
	cout<<ans(ma-1);
	return 0;
}