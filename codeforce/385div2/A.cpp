#include <bits/stdc++.h>
using namespace std;
int main()
{	
	string s;
	cin>>s;
	string check[s.size()];
	for(int i=0;i<s.size();i++)
		check[i]=s;
	int j=0;
	while(j<s.size())
	{
		for(int i=0;i<s.size();i++)
		{
			if(i-j>=0)
			{
				check[j][i-j]=s[i];
			}
			else
			{
				check[j][s.size()+i-j]=s[i];
			}
		}
		j++;
	}
	int ans=s.size();
	bool vis[s.size()];
	memset(vis,false,sizeof(vis));
	for(int i=0;i<s.size() && !vis[i];i++)
	{
		for(int j=i+1;j<s.size();j++)
		{
			if(check[i]==check[j])
			{
				vis[j]=true;
				ans--;
			}
		}
	}	
	cout<<ans<<endl;
	return 0;
}		