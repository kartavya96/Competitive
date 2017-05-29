#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{	
	int ma=0;	
	cin>>n;
	int a[n],s[n],s1[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		s[i]=1;
		s1[i]=1;
	}
	if(n==1 || n==2)
	{
		cout<<n<<endl;
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]>a[i-1])
			s[i]=s[i-1]+1;
	}
	for(int i=n-2;i>=0;i--)
	{
		if(a[i]<a[i+1])
			s1[i]=s1[i+1]+1;
	}
	for(int i=1;i<n;i++)
	{
		ma=max(ma,s[i]); 		
	}
	// for(int i=0;i<n;i++)
	// {
	// 		cout<<s[i]<<" ";	
	// }
	// cout<<endl;
	// 	for(int i=0;i<n;i++)
	// {
	// 		cout<<s1[i]<<" ";	
	// }
	for(int i=1;i<n-1;i++)
	{
		if(s[i]==1)
		{
			if(a[i-1]<a[i+1] && a[i+1]-a[i-1]>1)
			{
				ma=max(ma,s[i-1]+s1[i+1]+1);
			}
		}
	}
	ma=max(ma,max(s[n-2]+1,s1[1]+1));
	cout<<ma<<endl;
	return 0;
}		