#include <bits/stdc++.h>
using namespace std;

#define rep(n) for(long long int  i=0;i<n;i++)
#define loop(a,b) for(long long int  j=a;j<b;j++)
long long int  n,k;
int  main()
{
	cin>>n>>k;
	long long int  a[n][n];
	long long int  p=(n*n)-n+k;
	long long int  q=1;
	for(long long int  i=0;i<n;i++)
	{
//		cout<<p<<q<<endl;
		long long int  h=k-1,o;
		o=p;
		while(1)
		{
			if(h>=n)
				break;
			a[i][h]=o;
			o++;
			h++;
		}
		h=0;
		long long int  u=q;
		while(1)
		{
			if(h>=(k-1))
				break;
			a[i][h]=u;
			u++;
			h++;
		}
		p=p-(n-k+1);
		q=u;
	}
	long long int  sum=0;
	for(long long int  i=0;i<n;i++)
		sum=sum+a[i][k-1];
	cout<<sum<<endl;
	for(long long int  i=0;i<n;i++)
	{
		for(long long int  j=0;j<n;j++)
		cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}