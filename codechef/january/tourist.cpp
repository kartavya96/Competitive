#include <bits/stdc++.h>
using namespace std;
list<long long int> *ans;
class Graph
{
	long long int V;
	list<long long int> *adj; 
public:
	Graph(long long int V)
	{ 
		this->V = V;	
		adj = new list<long long int>[V];	
		ans = new list<long long int>[V];
	}
	~Graph()			
	{ 
		delete [] adj;	
	}
	void addEdge(long long int u, long long int v) 
	{	
		adj[u].push_back(v); 
		adj[v].push_back(u); 
	}
	void rmvEdge(long long int u, long long int v);
	bool printEulerTour();
	void printEulerUtil(long long int s,int anu);
	long long int DFSCount(long long int v, bool visited[]);
	long long int DFS1Count(long long int v, bool visited[],long long int x,long long int y);
	bool isValidNextEdge(long long int u, long long int v,int ann);
};
bool Graph::printEulerTour()
{
	long long int u = 0;
	bool chec=true;
	for (long long int i = 0; i < V; i++)
	{
		if(adj[i].size()%2!=0 || adj[i].size()==0)
		{
			chec=false;
		}
	}
	if(chec)
	{
		bool visited[V];
		memset(visited, false, V);
		long long int count1 = DFSCount(0, visited);
		if(count1==V)
		{
			cout<<"YES"<<endl;
			printEulerUtil(0,V);
			return true;
		}
		else
		{
			cout<<"NO"<<endl;
			return false;
		}
	}
	else
	{
		cout<<"NO"<<endl;
		return false;
	}
}
void Graph::printEulerUtil(long long int u,int anu)
{
	list<long long int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		long long int v = *i;

		if (v != -1 ){
			int ann=isValidNextEdge(u, v,anu);
			if(ann!=-1)
			{
				ans[u].push_back(v);
				rmvEdge(u, v);
				printEulerUtil(v,ann);
			}
		}
	}
}
bool Graph::isValidNextEdge(long long int u, long long int v,int ann)
{
	long long int count = 0; 
	list<long long int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
		 if (*i != -1)
				count++;
	if (count == 1)
		return ann-1;
	bool visited[V];
	//memset(visited, false, V);
	//long long int count1 = DFSCount(u, visited);
	memset(visited, false, V);
	long long int count2 = DFS1Count(u, visited,u,v);
	return (ann > count2)? -1: ann;
}
void Graph::rmvEdge(long long int u, long long int v)
{
	list<long long int>::iterator iv = find(adj[u].begin(), adj[u].end(), v);
	*iv = -1;
	list<long long int>::iterator iu = find(adj[v].begin(), adj[v].end(), u);
	*iu = -1;
}
long long int Graph::DFSCount(long long int v, bool visited[])
{
	visited[v] = true;
	long long int count = 1;
	list<long long int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
			if (*i != -1 && !visited[*i])
					count += DFSCount(*i, visited);
	return count;
}
long long int Graph::DFS1Count(long long int v, bool visited[],long long int x,long long int y)
{
	visited[v] = true;
	long long int count = 1;
	list<long long int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
			if (*i != -1 && !visited[*i] && !((*i==x && v==y)||(*i==y && v==x)))
			{
					count += DFS1Count(*i, visited,x,y);
			}
	}
	return count;
}
int main()
{
	long long int n,m;
	cin>>n>>m;
	long long int mm=m;
	Graph g(n);
	vector<pair<long long int, long long int> >che;
	while(mm--)
	{
		long long int p,q;
		cin>>p>>q;
		che.push_back(make_pair(p-1,q-1));
		g.addEdge(p-1,q-1);
	}
	if(g.printEulerTour())
	{
		for(long long int i=0;i<m;i++)
		{
			long long int pp=che[i].first;
			long long int qq=che[i].second;
			list<long long int>::iterator vi=find(ans[pp].begin(),ans[pp].end(),qq);
			if(vi!=ans[pp].end())
				cout<<pp+1<<" "<<qq+1<<endl;
			else
				cout<<qq+1<<" "<<pp+1<<endl;
		}
	}
	return 0;
}		