#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    if(a>=b)
        return 0;
        
    return 1;
}
int main()
{
    long long int n,i=2,ans=0;
    cin>>n;
    vector<int> a;
    while(i < sqrt(n))
    {
        if(n%i==0) 
        {
            a.push_back(i);
            if (i != (n / i))
            {
                a.push_back(n/i);
            }
        } 
        i++;
    }
    long long int y=a.size();
    long long int b[y];
    for(int i=0;i<a.size();i++)
    {
        b[i]=a[i];
    }
    sort(b,b+y,cmp);
    for(int i=0;i<y;i++)
    {
        cout<<b[i]<<" ";
    }
/*    long long int k=0;
    while(1)
    {
        if(b[k]*b[k]<=n)
        {
            cout<<b[k]*b[k]<<" "; 
        }
        else
            break;
        k++;
    }*/ 
    return 0;
}