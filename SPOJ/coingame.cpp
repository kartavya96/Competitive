#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k,l,m;
	cin>>k>>l>>m;
	bool game[1000001];
	memset(game,false,sizeof(game));
	game[0]=false;
	for(int i=1;i<1000001;i++)
	{
		if(!game[i-1])
		{
			game[i]=true;
			continue;
		}
		if(i>=k && !game[i-k])
		{
			game[i]=true;
			continue;
		}
		if(i>=l && !game[i-l])
		{
			game[i]=true;
			continue;
		}
		game[i]=false;
	}
	while(m--)
	{
		int h;
		cin>>h;
		if(game[h])
			cout<<'A';
		else
			cout<<'B';
	}
	cout<<endl;
}