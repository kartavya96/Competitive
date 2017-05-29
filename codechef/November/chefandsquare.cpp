#include <bits/stdc++.h>
using namespace std;
int n;
int a[401][401];
bool funn(int x,int y,bool vis_row[],bool vis_col[],int l)
{
	// if(x>=n && y>=n)
	// 	return true;
	a[x][y]=l;
	vis_row[(x-1)*n+l]=true;
	vis_col[(y-1)*n+l]=true;
	bool check=false;
	for(int i=1;i<=n;i++)
	{
		if(vis_row[(x-1)*n+i]==false && vis_col[(y-1)*n+i]==false)
		{
			if(x+1<=n && y<=n && a[x+1][y]==0)
			{
				if(funn(x+1,y,vis_col,vis_row,i))
				{
					check=true;
				}
				else
					return false;
			}
			else
				check=true;
			if(y+1<=n && x<=n && check && a[x][y+1]==0)
			{
				if(funn(x,y+1,vis_col,vis_row,i))
					return true;
				else
					return false;
			}
		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		bool vis_row[(n+2)*(n+2)+5];
		bool vis_col[(n+2)*(n+2)+5];
		for(int k=1;k<=n;k++)
		{
			memset(vis_row,false,sizeof(vis_row));
			memset(vis_col,false,sizeof(vis_col));
			memset(a,0,sizeof(a));
			if(funn(1,1,vis_col,vis_row,k))
				int ll=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
						cout<<a[i][j]<<" ";
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
