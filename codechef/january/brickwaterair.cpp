#include <bits/stdc++.h>
using namespace std;
int main()
{		
	long long int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		bool ans=true;
		int what[m];
		//air=0 brick=1 water=2
		memset(what,0,sizeof(what));
		for(int i=0;i<n;i++)
		{	
			string a;
			cin>>a;
			for(int j=0;j<m;j++)
			{
				if(a[j]=='A')
				{	
					if(what[j]==0)
					{
						if((a[j+1]=='W') && j<m-1)
							ans=false;
					}
					else
						ans=false;
					what[j]=0;
				}
				else if(a[j]=='B')
				{
					what[j]=1;
				}
				else
				{
					if(what[j]==1)
						ans=false;
					if(a[j+1]=='A' && j<m-1)
						ans=false;
					if(j==0 && a[j]=='W')
						ans=false;
					if(j==m-1 && a[j]=='W')
						ans=false;
				}
			}
		}
		if(ans)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}