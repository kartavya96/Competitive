#include <bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long int t;
	cin>>t;
	while(t--)
	{
		unsigned long long int n;
		cin>>n;
		queue<pair<string,unsigned long long int> >q;
		q.push_back(make_pair("1",1));
		unsigned long long int t=2;
		bool kk=true;
		while(kk || !q.empty())
		{
			pair<string,unsigned long long int> s=q.front();
			q.pop();
			string s1=s.first+"0";
			string s2=s.first+"1";
			unsigned long long int s11=s.second*10;
			unsigned long long int s22=s.second*10+1;
			if(s11%n==0)
			{
				cout<<s11;
				kk=false;
				break;
			}
			else
				q.push_back(make_pair(s1,s11));
			if(s22%n==0)
			{
				cout<<s22;
				kk=false;
				break;
			}
			else
				q.push_back(make_pair(s2,s22));
		}
	}
}