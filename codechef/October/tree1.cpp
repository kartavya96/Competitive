#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int t,ans=1;
	cin>>t;
	while(t--)
	{
		string s1,s2,s3;
		long long int k;
		bool gaga=true;
		cin>>s1>>s2>>s3>>k;
		while(k--)
		{
			s1.append(s2);
		}
		s1.append(s3);
		ans=1;
		while(gaga)
		{
			bool jh=false,kj=false,zer=true;
			long long int carry = 0,lo=0;
			for(long long int i=0;i<s1.size();i++)
			{
				if(s1[i]=='1')
					zer=false;
			}
			if(zer)
			{
				cout<<ans<<endl;
				gaga=false;
				break;
			}
			for(long long int i=s1.size()-1;i>=0;i--)
			{
				if(s1[i]=='0' && !jh)
				{
					s1[i]='0';
					jh=true;
				}
				else if(!jh)
				{
					s1[i]='0';
				}
				if(i==s1.size()-1 && s1[i]=='1')
					lo++;
				else if(s1[i]=='0')
					lo++;
				if(i<s1.size()-1)
				{
        			if(s1[i]=='0')
        			{
        				if(carry)
        				{
        					s1[i]='0';
        					carry=1;
        				}
        				else
        				{
        					s1[i]='1';
        					carry=0;
        				}
        			}
        			else if(s1[i]=='1')
        			{
        				if(carry)
        				{
        					s1[i]='1';
        					carry=1;
        				}
        				else
        				{
        					s1[i]='0';
        					carry=1;
        				}
        			}
				}
				if(s1[i]=='0' && !kj)
				{
					s1[i]='1';
					kj=true;
				}
				else if(!kj)
					s1[i]='0';
			}
			if(lo==s1.size())
			{
				cout<<ans<<endl;
				gaga=false;
				break;
			}
    		else if(carry)
    		{
				if(!kj)
					s1='1' + s1;
				ans++;
    		}
			else
			{
				cout<<ans<<endl;
				gaga=false;
				break;
			}
		}
	}
	return 0;
}