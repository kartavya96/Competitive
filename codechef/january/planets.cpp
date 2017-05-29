#include <bits/stdc++.h>
using namespace std;
bool fun(pair<int, int> a,pair<int, int> b)
{
	if(a.second>=b.second)
		return true;
	else
	{
		return false;
	}
}
bool fun1(pair<int, int> a,pair<int, int> b)
{
	if(a.second>=b.second)
		return true;
	else
	{
		return false;
	}
}
int main()
{		
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int b[n];
		vector <pair<int,int> > a;
		vector <pair<int,int> > lis[n];
		for(int i=0;i<n;i++)
		{
			int hh;
			cin>>hh;
			b[i]=hh;
			a.push_back(make_pair(i,hh));
		}
		sort(a.begin(),a.end(),fun);
		for(int i=0;i<n-1;i++)
		{
			int p,q;
			cin>>p>>q;
			lis[i].push_back(make_pair(i,b[i]));
			lis[p-1].push_back(make_pair(q-1,b[q-1]));
			lis[q-1].push_back(make_pair(p-1,b[p-1]));
		}
		for(int i=0;i<n;i++)
		{
			sort(lis[i].begin(),lis[i].end(),fun1);
		}
		for(int i=0;i<n;i++)
		{
			int k=0;
			for(int j=0;j<lis[i].size();)
			{
				if(a[k].second!=lis[i][j].second && a[k].first!=i)
				{ 
					break;
				}
				else
				{
					k++;
					j++;
				}
			}
			cout<<a[k].first+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}		