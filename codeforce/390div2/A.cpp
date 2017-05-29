#include <bits/stdc++.h>
using namespace std;
int main()
{		
	std::ios_base::sync_with_stdio(false); 
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int sum=0,l=0;
	vector<pair<int, int> > b;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		if(i==n-1 && sum!=0)
		{
			b.push_back(make_pair(l+1,i+1));
		}
		if(sum==0 && l+1<=i)
		{
			b.push_back(make_pair(l+1,i));
			l=i;
			sum=0;
			i--;	
		}
	}
	if(b.size()!=0)
	{
		if(b[0].first==1 && b[b.size()-1].second==n)
		{
			cout<<"YES"<<endl;
			cout<<b.size()<<endl;
			for(int i=0;i<b.size();i++)
			{
				cout<<b[i].first<<" "<<b[i].second<<endl;
			}
		}
		else
			cout<<"NO"<<endl;
	}
	else
		cout<<"NO"<<endl;
	return 0;
}