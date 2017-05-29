#include <bits/stdc++.h>
using namespace std;
long long int ans=0,nka,n;
set<long long int> qp;
bool cmp(long long int a,long long int b)
{
    if(a>=b)
        return 0;
        
    return 1;
}
void combinationUtil(long long int arr[],long long int data[],long long int start,long long int end,long long int index,long long int r)
{

    if (index == r)
    {
        long long kk=1;
        for (long long int j=0; j<r; j++)
        {
            kk=kk*data[j];
            if(kk>=nka)
                return;
        }
        if(kk<nka && (nka%kk)!=0)
        {
            //cout<<nka<<" "<<kk<<endl;
            qp.insert(kk);
        }
        return;
    }
    for (long long int i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}
void printCombination(long long int arr[],long long int n,long long int r)
{
    // for(int i=0;i<n;i++)
    //     cout<<arr[i]<<" ";
    long long int data[r];
    combinationUtil(arr, data, 0, n-1, 0, r);
}

int main()
{
    cin>>n;
    nka=n;
    vector<long long int> a;
    while(n%2==0)
    {
        a.push_back(2);
        n=n/2;
    }
    for (long long int i = 3;i<=sqrt(n);i=i+2)
    {
        while (n%i== 0)
        {
            a.push_back(i);
            n = n/i;
        }
    }
    if (n>2)
        a.push_back(n);
    
  /*  for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";*/

    long long int j=0,b[2*a.size()];
    for(long long int i=0;i<a.size();i++)
    {
        b[j]=a[i];
        b[j+1]=a[i];
        j++;
        j++;
    }
   /* for(int i=0;i<2*a.size();i++)
        cout<<b[i]<<" ";*/

    for(long long int r=2;r<2*a.size();r++)
    {
        printCombination(b,2*a.size(),r);
    }
    set <long long int> :: iterator itr;
  /*  for (itr = qp.begin(); itr != qp.end(); ++itr)
    {
        cout << '\t' << *itr;
    }
*/
    cout<<qp.size();
    return 0;
}