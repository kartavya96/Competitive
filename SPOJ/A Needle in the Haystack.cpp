#include <bits/stdc++.h>
using namespace std;

int main()
{
	// ios_base::sync_with_stdio(false);
 //    cin.tie(NULL); 
	char needle[1000000+10],haystack[10000000+10];
	int n;
	while((scanf("%d",&n)!=EOF))
	{
		cin>>needle;
		cin>>haystack;
		int l=strlen(needle);
		int lcp[l];
		int j=0;
		lcp[j]=0;
		memset(lcp,0,sizeof(lcp));
		for(int i=1;i<l;)
		{
			if(needle[i]==needle[j])
			{
				lcp[i]=j+1;
				j++;
				i++;
			}
			else
			{
				if(j!=0)
				{
					j=lcp[j-1];
				}
				else
				{
					lcp[i]=0;
					i++;
				}
			}
		}
		j=0;
		vector<int> ans;
		int ll=strlen(haystack);
		for(int i=0;i<ll;)
		{
			if(needle[j]==haystack[i])
			{
				j++;
				i++;
			}
			if(j==l)
			{
				ans.push_back(i-l);
				j=lcp[l-1];	
			}
			else if(i<ll && needle[j]!=haystack[i])
			{
				if(j!=0)
					j=lcp[j-1];
				else
					i++;
			}
		}
		if(ans.size()==0)
			cout<<endl;
		else
		{
			for(int i=0;i<(ans).size();i++)
				cout<<ans[i]<<endl;
		}
	} 
	return 0;
}