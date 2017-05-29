#include <bits/stdc++.h>
using namespace std;
int n,k,d;
int main()
{		
	cin>>n>>k>>d;
	char a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(a[k-1]==a[d-1])
		cout<<"0"<<endl;
	else
	{
		int ans=0,ans1=0,an=0;
		if(a[d-1]=='1')
		{
			int kk=k-1;
			for(int i=k-1;i<n;i++)
			{
				if(a[i]=='1')
				{
					ans=max(i-kk,kk-i);
					break;
				}
				else
					kk=i;
			}
			kk=k-1;
			for(int i=k-1;i>=0;i--)
			{
				if(a[i]=='1')
				{
					ans1=max(i-kk,kk-i);
					break;
				}
				else
					kk=i;
			}
			if(ans!=0 && ans1!=0)
				an=min(ans,ans1);
			else if(ans==0)
				an=ans1;
			else if(ans1==0)
				an=ans;
		}
		else
		{
			int kk=k-1;
			for(int i=k-1;i<n;i++)
			{
				if(a[i]=='0')
				{
					ans=max(i-kk,kk-i);
					break;
				}
				else
					kk=i;
			}
			kk=k-1;
			for(int i=k-1;i>=0;i--)
			{
				if(a[i]=='0')
				{
					ans1=max(i-kk,kk-i);
					break;
				}
				else
					kk=i;
			}
			if(ans!=0 && ans1!=0)
				an=min(ans,ans1);
			else if(ans==0)
				an=ans1;
			else if(ans1==0)
				an=ans;
		}
		cout<<an<<endl;
	}
	return 0;
}		