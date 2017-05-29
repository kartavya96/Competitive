#include <bits/stdc++.h>
using namespace std;
int n;
int d1,c1,d2,c2,ans=0;
void fac(int t,int e,int k)
{
	if(k==n)
	{
		ans=(ans%1000000007+1)%1000000007;
		return;
	}
	if(t==0)
	{
		if(e>d2)
			return;
	}
	if(t==1)
	{
		if(e>d1)
			return;
	}
	if(t==1)
	{
		fac(1,e+1,k++);
		fac(0,0,k++);
	}
	if(t==0)
	{
		fac(1,0,k++);
		fac(0,e+1,k++);
	}
}
int main()
{
	cin>>d1>>c1>>d2>>c2;
	n=d1+c1;
	fac(1,0,1,1,1);
	fac(0,0,1,1,1);
	cout<<ans;
	return 0;
}
