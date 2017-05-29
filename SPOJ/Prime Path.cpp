#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int a,b,flag=0;
	vector<long long int>prim;
	for(long long int i=1001;i<=9999;i++)
	{
		flag=0;
		for(long long int j=2; j<=i/2; ++j)
    	{
        	if(i%j==0)
       	 	{
            	flag=1;
            	break;
        	}
    	}
    	if(flag==0)
    		prim.push_back(i);
    }
    list<long long int> adj[prim.size()];
    for(long long int i=0;i<prim.size()-1;i++)
    {
    	for(long long int j=i+1;j<prim.size();j++)
    	{
    		long long int d1[4],d2[4];
    		long long int number1=prim[j],number2=prim[i];
   			d1[0] = number1%10;
    		number1 /= 10;
    		d1[1] = number1%10;
    		number1 /= 10;
    		d1[2] = number1%10;
    		number1 /= 10;
    		d1[3] = number1%10;
    		number1 /=10;
    		d2[0] = number2%10;
    		number2 /= 10;
    		d2[1] = number2%10;
    		number2 /= 10;
    		d2[2] = number2%10;
    		number2 /= 10;
    		d2[3] = number2%10;
    		number2 /=10;	
    		if( (d1[0]==d2[0] && d1[1]==d2[1] && d1[2]==d2[2] && d1[3]!=d2[3]) || (d1[0]!=d2[0] && d1[1]==d2[1] && d1[2]==d2[2] && d1[3]==d2[3])  || (d1[0]==d2[0] && d1[1]!=d2[1] && d1[2]==d2[2] && d1[3]==d2[3]) || (d1[0]==d2[0] && d1[1]==d2[1] && d1[2]!=d2[2] && d1[3]==d2[3]))
    		{
    			adj[i].push_back(j);
    			adj[j].push_back(i);	
    		}
    	}
    }
    long long int n;
    cin>>n;
    while(n--)
    {
    	bool vis[prim.size()];
    	long long int ans=0,kk=1;
		cin>>a>>b;
		for(long long int i=0;i<prim.size();i++)
		{
			if(prim[i]==a)
				a=i;
			if(prim[i]==b)
				b=i;
		}
		//cout<<a<<" "<<b<<endl;
		memset(vis,false,sizeof(vis));
		queue<pair<long long int,long long int> >q;
		q.push(make_pair(a,0));
		while(!q.empty() && kk)
		{
			pair<long long int,long long int> temp;
			temp=q.front();
			q.pop();
			if(temp.first==b)
			{
				ans=temp.second;
				kk=0;
				break;
			}
			if(vis[temp.first]==false)
			{
				//cout<<prim[temp.first]<<" "<<temp.second<<endl;
				vis[temp.first]=true;
				list<long long int>::iterator i;
    			for (i=adj[temp.first].begin();i!=adj[temp.first].end();i++)
    			{
    				if(vis[*i]==false)
    				{
    					if(temp.first==b)
						{
							ans=temp.second+1;
						}
    					q.push(make_pair(*i,temp.second+1));
    				}
    			}
    		}	
		}
		if(kk==0)
			cout<<ans<<endl;
		else
			cout<<"Impossible"<<endl;
	}
	return 0;
}