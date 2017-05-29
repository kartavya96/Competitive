#include <bits/stdc++.h>
using namespace std;
bool a[100001];
int main()
{
	memset(a,false,sizeof(a));
	for (int i=2; i<100001; i++) 
    {
        bool prime=true;
        for (int j=2; j*j<=i; j++)
        {
            if (i % j == 0) 
            {
                prime=false;
                break;    
            }
        }   
        if(prime) a[i]=true;
    }
	int t;
	cin>>t;
	while(t--)
	{
		int c,b,ans=0;
		cin>>c>>b;
		while(1)
		{
			if(c==b)
			{
				cout<<c<<endl;
				break;
			}
			c++;
			if(c==b)
			{
				cout<<c<<endl;
				break;
			}
			if(a[c])
				b++;
			else
				b--;
		}
	}
	return 0;
}
