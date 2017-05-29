	#include <bits/stdc++.h>
	using namespace std;
	long long int n,a[205],dp[205][205][205];
	long long int getit(long long int x,long long int y,long long int z,long long int u)
	{
		if(x>=n)
			return 0;
		long long int b=1000000000,bb=1000000000,bbb=1000000000;
		if(z!=1000000000 || u!=1000000000 || z!=-1 || u!=-1)
		{
			if(dp[x][z][u]==-1)
			{	
				if(a[x]<=a[z])
				{		
					bb=getit(x+1,0,x,u);	
				}		
				if(a[x]>=a[u])
				{
					bbb=getit(x+1,1,z,x);
				}
				b=getit(x+1,2,u,z);
				return (dp[x][z][u]=(min(b+1,min(bb,bbb))));
			}
			else
				return dp[x][z][u];
		}
		else
		{
			if(z==1000000000)
			{
				bb=getit(x+1,0,x,u);	
			}
			else
			{
				if(a[x]<=a[z])
				{
					bb=getit(x+1,0,x,u);
				}			
			}
			if(u==-1)
			{
				bbb=getit(x+1,1,z,x);
			}
			else
			{
				if(a[x]>=a[u])
				{
					bbb=getit(x+1,1,z,x);		
				}				
			}
			b=getit(x+1,2,u,z);
			return (min(b+1,min(bb,bbb)));
		} 		
	}
	int main()
	{
		// W-D B-A
		while(1)
		{
			cin>>n;
			if(n==-1)
				return 0;
			for(long long int i=0;i<n;i++)
				cin>>a[i];
			memset(dp,-1,sizeof(dp));
			//cout<<min(getit(1,0,0,-1),min(getit(1,1,1000000000,0),getit(1,2,1000000000,-1)+1))<<endl;
		}
		return 0;
	}