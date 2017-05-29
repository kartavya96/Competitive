#include <bits/stdc++.h>
using namespace std;
bool cmp(long long int p,long long int q)
{
	if(p>=q)
		return true;
	return false;
}
int main()
{			
	long long int n,t;  
	cin>>n; 
	t=n;
	while(n--)
	{		
		long long int a,b;
		cin>>a>>b;
		long long int x[b],count=0;
		bool k=true;
		for(int i=0;i<b;i++)
			cin>>x[i];
		sort(x,x+b,cmp);
		// for(int i=0;i<b;i++)
		// 	cout<<x[i];
		long long int sum=0;
		for(int i=0;i<b && k;i++)
		{
			if(sum>=a)
			{
				cout<<"Scenario #"<<t-n<<":"<<endl<<count<<endl<<endl;
				k=false;
			}
			sum=sum+x[i];		
			count++;
		}
		if(sum>=a && k)
			cout<<"Scenario #"<<t-n<<":"<<endl<<count<<endl<<endl;
		else if(k==true)
			cout<<"Scenario #"<<t-n<<":"<<endl<<"impossible"<<endl<<endl;
	}		
}
