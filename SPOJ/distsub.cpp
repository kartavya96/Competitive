#include <bits/stdc++.h>
using namespace std;
string s;
int ans=0;
void cal(int pos)
{
	if(pos>=s.size())
		return;

	bool vis[30];
	memset(vis,false,sizeof(vis));
	for(int i=pos;i<s.size();i++)
	{
		if(vis[int(s[i]-'A')]==false)
		{
			cal(i+1);
			vis[int(s[i]-'A')]=true;
		}
		else
			ans++
	}
}
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
		for(int i=0;i<s.size();i++)
		{
			// cout<<int(s[i]-'A');
			if(vis[int(s[i]-'A')]==false)
			{
				ans++;
				cal(i+1);
				vis[int(s[i]-'A')]=true;
			}
		}
		cout<<ans<<endl;
	}
}