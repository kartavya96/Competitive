#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	if(a>=b)
		return false;
	return true;
}
int main()
{	
	int t;		
	cin>>t;
	/*
	3
	3 1
	2 5 4
	3 2
	5 2 4
	3 3
	2 5 4*/
	while(t--)
	{
		int n,k,min=1000000000;
		cin>>n>>k;
		int x[n];
		for(int i=0;i<n;i++)
			cin>>x[i];
		// for(int i=0;i<n;i++)
		// 	cout<<x[i];
		// cout<<endl;
		sort(x,x+n,cmp);
		for(int i=0;i<n-k+1;i++)
		{
			if((x[i+k-1]-x[i])<=min)
				min=x[i+k-1]-x[i];
		}
		cout<<min<<endl;
	} 
	return 0;
}
