#include <bits/stdc++.h>
using namespace std;
bool kk=false;
long long int in1=-1,fi1=-1,in2=-1,fi2=-1,dif=1000000009,n;


bool cmp(pair<long long int,long long int> a,pair<long long int,long long int> b)
{
    if(a.first<b.first)
        return 1;
    if(a.first>b.first)
        return 0;
    if(a.second<b.second)
        return 1;
    return 0;
}
long long int BinarySearch(pair<long long int,long long int> a[],long long int l,long long int r,long long int key,long long int pos)
{
    long long int m;
    while(l<=r && l>0 && r<n)
    {
        m=l+(r-l)/2;
        
            if(a[m].first==key)
            {
                if(a[m].second>pos)
                {
                    kk=true;
                    while(1)
                    {
                        if(a[m-1].first==key && a[m-1].second>pos)
                            m--;
                        else
                            return (a[m].second);
                   }
                }
                else
                {
                    while(m+1<n && a[m+1].first==key)
                    {
                        if(a[m+1].second>pos)
                        {
                            kk=true;
                            return (a[m+1].second);
                        }
                        m++;
                    }
                   return -1;
                }
            } 
            if(a[m].first<key) 
            {
                l=m+1;
            }
            else
                r=m-1;

    }
    return -1;
}
int main()
{
    long long int m;
    cin>>n>>m;
    pair<long long int,long long int> a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a,a+n,cmp);
  while(m--)
    {
        long long int k,in,fi;
        in1=-1,fi1=-1,in2=-1,fi2=-1,dif=1000000009;
        cin>>k;
        kk=false;
        for(long long int i=0;i<n;i++)
        {
            in1=a[i].first;
            fi1=a[i].first+k;
            in2=a[i].second;
            fi2=BinarySearch(a,i+1,n-1,fi1,a[i].second);
            if(fi2>=0)
            {
                if((fi2-in2)<dif)
                {
                    in=in2+1;
                    fi=fi2+1;
                    dif=fi2-in2;
                }
            }
        }
        if(kk)
            cout<<in<<" "<<fi<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0;
}