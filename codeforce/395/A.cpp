#include <bits/stdc++.h>
using namespace std;
long long int lcm(long long int a,long long int b)
{
    long long int m,n;

    m=a;
    n=b;

    while(m!=n)
    {
	if(m < n)
	{
	m=m+a;
	}
	else
	{
	    n=n+b;
	    }
    }

    return(m);
}
int main()
{	
	long long int n,m,z;
	cin>>n>>m>>z;
	long long int cm=lcm(n,m);
	cout<<(z/cm)<<endl;
	return 0;
}		