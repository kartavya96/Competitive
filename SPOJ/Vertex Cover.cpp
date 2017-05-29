// You are given an unweighted, undirected tree. Write a program to find a vertex set of minimum size in this tree
// such that each edge has as least one of its end-points in that set.
// Input
// The first line of the input file contains one integer N --- number of nodes in the tree (0 < N <= 100001).
// Next N-1 lines contain N-1 edges of that tree ---
// Each line contains a pair (u, v) means there is an edge between node u and node v (1 <= u,v <= N).
// Output
// Print number of nodes in the satisfied vertex set on one line.
// Example 1
// Input:
// 3
// 1 2
// 1 3
// Output:
// 1
// Explanation:
// The set can be {1}
// Example 2
// Input:
// 3
// 1 2
// 2 3
// Output:
// 1
// Explanation:
// The set can be {2}
#include <bits/stdc++.h>
using namespace std;
list<int> adj[100005];
int dp[100005][2];
int n;
int fun(int v,int sel,int par)
{
	int k=0;
	if(sel==0)
	{
		list<int>::iterator i;
		for(i=adj[v].begin();i!=adj[v].end();i++)
		{
			if(*i!=par)
			{
				if(dp[*i][1]==-1)
					k+=fun(*i,1,v);
				else
					k+=dp[*i][1];
			}
		}
		dp[v][sel]=k;
		return (dp[v][sel]);
	}
	else
	{
		list<int>::iterator i;
		for(i=adj[v].begin();i!=adj[v].end();++i)
		{
			if(*i!=par)
			{
				int p=0,q=0;
				if(dp[*i][1]==-1)
					p=fun(*i,1,v);
				else
					p=dp[*i][1];
				if(dp[*i][0]==-1)
					q=fun(*i,0,v);
				else
					q=dp[*i][0];
				k+=min(p,q);
			}
		}
		k=k+1;
		dp[v][sel]=(k);
		return (dp[v][sel]);
	}
}
int main()
{
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout<<min(fun(0,1,-1),fun(0,0,-1));
	cout<<endl;
	return 0;
}
/*
17
1 2
2 3
2 4
4 5
4 6
5 7
5 8
6 9
7 10
8 11
9 12
9 13
12 14
12 15
13 16
13 17
*/
// 1
// 0 2 3
// 1
// 1 4 5
// 3 6 7
// 3 8
// 4 9
// 4 10
// 5 11 12
// 6
// 7
// 8 13 14
// 8 15 16
// 11
// 11
// 12
// 12
