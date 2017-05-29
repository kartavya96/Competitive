#include <bits/stdc++.h>
using namespace std;
int main()
{			
	long long int n;  
	cin>>n; 
	while(n--)
	{		
		string a,b,c,x,y;
		bool k=true;
		cin>>a>>b>>c>>x>>y;
		for(long long int i=0;i<a.size() && k;i++)
		{
			if(a[i]=='m')
			{
				long long int q=stoi(c);
				long long int r=stoi(y);
				cout<<(r-q)<<" + "<<q<<" = "<<r<<endl;
				k=false;
			}	
		}
		for(long long int i=0;i<c.size() && k;i++)
		{
			if(c[i]=='m')
			{
				long long int p=stoi(a);
				long long int r=stoi(y);
				cout<<p<<" + "<<(r-p)<<" = "<<r<<endl;
				k=false;
			}	
		}4
		for(long long int i=0;i<y4.size() && k;i++)
		{
			if(y[i]=='m')
			{
				long long int q=stoi(c);
				long long int p=stoi(a);
				cout<<p<<" + "<<q<<" = "<<p+q<<endl;
				k=false;
			}	
		}
	}		
}
