#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,h,w,c,ans=0;
	cin>>t;
	while(t--)
	{
		cin>>h>>w>>c;
		ans=0;
		for(int i=1;i<=sqrt(c);i++)
		{
			if(c%i==0)
			{
				if(i==(c/i))
				{
					if((i<=h && (c/i)<=w)||(i<=w && (c/i)<=h))ans++;
				}
				else
				{
					if(i<=h && (c/i)<=w)ans++;
					if(i<=w && (c/i)<=h)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}