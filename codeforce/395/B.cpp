#include <bits/stdc++.h>
using namespace std;
int main()
{	
	long long n;
	cin>>n;
	long long a[n];
	for(long long i=0;i<n;i++)
		cin>>a[i];

	if(n%2!=0)
	{
		long long z=n/2,count=0;
		if(z%2==0)
		{
			for(long long i=z;i>=0;i--)
			{
				if(count%2==0)
				{
					long long temp=a[i];
					a[i]=a[z+count];
					a[z+count]=temp;
				}
				count++;
			}
		}
		else
		{
			for(long long i=z;i>=0;i--)
			{
				if(count%2!=0)
				{
					long long temp=a[i];
					a[i]=a[z+count];
					a[z+count]=temp;
				}
				count++;
			}
		}
	}
	else
	{
		long long z=n/2,count=0;
		if(z%2==0)
		{
			for(long long i=z-1;i>=0;i--)
			{
				if(count%2!=0)
				{
					long long temp=a[i];
					a[i]=a[z+count];
					a[z+count]=temp;
				}
				count++;
			}		
		}
		else
		{
			for(long long i=z-1;i>=0;i--)
			{
				if(count%2==0)
				{
					long long temp=a[i];
					a[i]=a[z+count];
					a[z+count]=temp;
				}
				count++;
			}
		}
	}
	for(long long i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}		