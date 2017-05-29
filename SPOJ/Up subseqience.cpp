#include <bits/stdc++.h>
using namespace std;
vector<pair<char,int> >ans;
int ma=1;
bool cmp(pair<char,int> a,pair<char,int> b)
{
	if(a.second>b.second)
	{
		return false;
	}
	else if(a.second<b.second)
	{
		return 	true;
	}
	else
	{
		if(a.first>b.first)
			return false;
		return true;
	}
}
void printtt(int ind,char data[], int value, char c)
{
	if(value==ma)
	{
		for(int i=0;i<ma;i++)
			cout<<data[i];
		cout<<endl;
		return;
	}
	for(int i=ans.size()-1;i>=ind+1;i--)
	{
		if(ans[i].second==value+1)
		{
			if(ans[i].first>=c)
			{
				data[value]=ans[i].first;
				int iind=i;
				int vvalue=value+1;
				char cc=ans[i].first;
				printtt(iind,data,vvalue,cc);
			}
		}
	}
	return;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int lis[s.size()],rev[s.size()];
		int start=0;
		lis[0]=1;
		for(int i=1;i<s.size();i++)
		{
			lis[i]=1;
			for(int j=0;j<i;j++)
			{
				if(s[j]<=s[i])
				{
					if((lis[j]+1)>lis[i])
						lis[i]=lis[j]+1;
				}
			}
			if(lis[i]>ma)
			ma=lis[i];
		}
		rev[s.size()-1]=1;
		for(int i=s.size()-2; i>=0; i--)
		{
			rev[i] = 1;
			for(int j=i+1; j<s.size(); j++)
			{
				if(s[j]>=s[i])
				{
					if((rev[j]+1)>rev[i]) 
					{
						rev[i]=rev[j]+1;
					}
				}
			}
		}
		bool check=true;
		for(int i=0; i<s.size(); i++)
		{
			if((lis[i]+rev[i])>ma)
			{
				ans.push_back(make_pair(s[i],lis[i]));
			}
		}
		char data[ma];
		// cout<<ma<<endl;
		//sort(ans.begin(),ans.end(),cmp);
		// for(int i=0;i<s.size();i++)
		// 	cout<<s[i]<<lis[i]<<" ";
		// cout<<endl;
		// cout<<endl;
		// for(int i=0;i<ans.size();i++)
		// 	cout<<ans[i].first<<" "<<ans[i].second<<endl;
		// cout<<endl;
		printtt(-1,data,0,'A');
		ma=-1;
		for(int i=0;i<ans.size();i++)
			ans.clear();
	}
	return 0;
}