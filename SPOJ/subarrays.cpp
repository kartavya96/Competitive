#include <bits/stdc++.h>
using namespace std;
long long int a[1000005];
long long int r;
long long int divi(long long int start,long long int end,long long int st[],long long int si)
{
	if(end==start)
	{
		st[si]=a[end];
		return(a[end]);
	}
	long long int mid=(end+start)/2;
	st[si]=max(divi(start,mid,st,si*2+1),divi(mid+1,end,st,si*2+2));
	return(st[si]);
}
long long int sumit(long long int st[],long long int start,long long int end,long long int qstar,long long int qend,long long int si)
{
	long long int mid=(end+start)/2;
	if(qstar<=start && qend>=end)
	{
		return st[si];
	}
	if(qend<start || qstar>end)
		return 0;

	long long int kleft=sumit(st,start,mid,qstar,qend,si*2+1);
	long long int kright=sumit(st,mid+1,end,qstar,qend,si*2+2);
	long long int ktotal=max(kleft,kright);
	return ktotal;
}
int main()
{
	long long int n;
	cin>>n;
	for(long long int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long int x = (long long int)(ceil(log2(n))); 
	long long int max_size = (2*((long long int)pow(2, x)))-1; 
	long long int st[max_size];
	memset(st,0,sizeof(st));
	divi(0,n-1,st,0);
	cin>>r;
	long long int ma=-1;
	for (long long int i=0;i<=n-r;i++)
	{
		cout<<sumit(st,0,n-1,i,i+r-1,0)<<" ";
	}
	return 0;
}