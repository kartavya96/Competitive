#include <bits/stdc++.h>
using namespace std;
int a[50010];
int ma;
int divi(int start,int end,int st[],int si)
{
	if(end==start)
	{
		st[si]=a[end];
		return(a[end]);
	}
	int mid=(end+start)/2;
	st[si]=divi(start,mid,st,si*2+1)+divi(mid+1,end,st,si*2+2);
	return(st[si]);
}
int sumit(int st[],int start,int end,int qstar,int qend,int si)
{
	int mid=(end+start)/2;
	if(start==end)
	{
		ma=max(ma,st[si]);
		return(st[si]);
	}
	if(qend<start || qstar>end)
		return 0;
	int kleft=sumit(st,start,mid,qstar,qend,si*2+1);
	int kright=sumit(st,mid+1,end,qstar,qend,si*2+2);
	int kk=kleft+kright;
	ma=max(ma,kk);
	ma=max(ma,kleft);
	ma=max(ma,kright);
	return kk;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
    int x = (int)(ceil(log2(n))); 
    int max_size = (2*((int)pow(2, x)))-1; 
    int st[max_size];
    memset(st,0,sizeof(st));
    divi(0,n-1,st,0);
    int nn;
    cin>>nn;
    while(nn--)
    {
    	int f,g;
    	cin>>f>>g;
    	f--;
    	g--;
    	ma=a[f];
    	ma=max(ma,sumit(st,0,n-1,f,g,0));
   		cout<<ma;
    }
	return 0;
}