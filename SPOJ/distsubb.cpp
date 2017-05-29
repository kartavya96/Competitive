#include <bits/stdc++.h>
using namespace std;
string s;
int ans=0;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>s;
		bool vis[30];
		memset(vis,false,sizeof(vis));
		vector<string> node;
		for(int i=0;i<s.size();i++)
		{
			node.push_back(s.substr(i));
		}
		sort(node.begin(),node.end());
		for(int i=0;i<s.size();i++)
		{
			cout<<node[i]<<endl;
		}
	}
}