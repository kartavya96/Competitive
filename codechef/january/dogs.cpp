#include <bits/stdc++.h>
using namespace std;
int main()
{		
	long long int n;
	cin>>n;
	while(n--)
	{
		long long int c,d,L;
		cin>>c>>d>>L;
		if((L%4)!=0)
		{
			cout<<"no"<<endl;
		}
		else
		{
			long long int ma=(c+d)*4;
			long long int mi=0;
			if(c<=d)
				mi=d*4;
			else
			{
				if(c<=2*d)
					mi=d*4;
				else
					mi=(d+(c-(2*d)))*4;
			}
			if(L>=mi && L<=ma && L%4==0)
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		}
	}
	return 0;
}		