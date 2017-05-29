#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,k,ans=0;
	cin>>n>>k;
	long long int aa[n+1];
	vector<pair<long long int,long long int> > c;
	memset(aa,0,sizeof(aa));
	long long int ii=0;
	vector<pair<int,bool> vis[n+1];
	while(k--)
	{
		long long int a,b;
		cin>>a>>b;
		if(a==1)
		{
			c.push_back(make_pair(b,ii));
			vis[b].second=true;
			ii++;
			aa[b]++;
			ans++;
		}
		else if(a==2)
		{
			ans=ans-aa[b];
			aa[b]=0;
			vis[b].first=ii;
			vis[b].second=false;
		}
		else if(a==3)
		{
			for(long long int g=0;g<c.size() && g<b;g++)
			{
				if(!c[g].second)
				{
					c[g].second=true;
					long long int y=c[g].first;
					aa[y]--;
					ans--;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}