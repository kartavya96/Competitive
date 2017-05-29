#include <bits/stdc++.h>
using namespace std;
long long int a[100005],n;
long long int seg(long long int ss,long long int se,long long int st[],long long int si)
{
	if(ss==se)
		return(st[si]=a[ss]);
	long long int mid=(ss+se)/2;
	return(st[si]=seg(ss,mid,st,si*2+1)+seg(mid+1,se,st,si*2+2));
}
void upseg(long long int st[],long long int ss,long long int se,long long int qs,long long int qe,long long int value,long long int si,long long int lazy[])
{
	if(lazy[si]!=0)
	{
		st[si]+=(se-ss+1)*lazy[si];
		if(ss!=se)
		{
			lazy[si*2+1]+=lazy[si];
			lazy[si*2+2]+=lazy[si];
		}
		lazy[si]=0;
	}
	if(ss>qe || se<qs || ss>se)
		return;
	if(ss>=qs && se<=qe)
	{
		st[si]+=(se-ss+1)*value;
		if(ss!=se)
		{
			lazy[si*2+1]+=value;
			lazy[si*2+2]+=value;
		}
		return ;
	}
	long long int mid=(ss+se)/2;
	upseg(st,ss,mid,qs,qe,value,si*2+1,lazy);
	upseg(st,mid+1,se,qs,qe,value,si*2+2,lazy);
	st[si] = st[si*2+1] + st[si*2+2];
}
long long int getsum(long long int ss,long long int se,long long int qs,long long int qe,long long int si,long long int st[],long long int lazy[])
{
	if(lazy!=0)
	{
		st[si]+=(se-ss+1)*lazy[si];
		if(ss!=se)
		{
			lazy[si*2+1]+=lazy[si];
			lazy[si*2+2]+=lazy[si];
		}
		lazy[si]=0;
	}
	if(qs>se || qe<ss || ss>se)
		return 0;
	if(ss>=qs && se<=qe)
		return st[si];
	long long int mid=(ss+se)/2;
	return(getsum(ss,mid,qs,qe,si*2+1,st,lazy)+getsum(mid+1,se,qs,qe,si*2+2,st,lazy));
}
int main()
{
	long long int cas;
	cin>>cas;
	while(cas--)
	{
		long long int n,t;
		cin>>n>>t;
		long long int x = (long long int)(ceil(log2(n))); 
		long long int max_size = (2*((long long int)pow(2, x)))-1; 
		long long int st[max_size],lazy[max_size];
		memset(lazy,0,sizeof(lazy));
		memset(st,0,sizeof(st));
		seg(0,n-1,st,0);
		while(t--)
		{
			long long int wha;
			cin>>wha;
			if(wha==1)
			{
				long long int qs,qe;
				cin>>qs>>qe;
				qs--;
				qe--;
				cout<<getsum(0,n-1,qs,qe,0,st,lazy)<<endl;
			}
			else
			{
				long long int qs,qe,up;
				cin>>qs>>qe>>up;
				qs--;
				qe--;
				upseg(st,0,n-1,qs,qe,up,0,lazy);
				// for(long long int hh=0;hh<max_size;hh++)
				// 	cout<<st[hh]<<" ";
				// cout<<endl;
			}
		}
	}
	return 0;
}