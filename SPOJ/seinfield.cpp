#include <bits/stdc++.h>
using namespace std;
int main()
{
    int p=1;
    while(1)
    {
        string s;
        cin>>s;
        if(s[0]=='-')
            return 0;
        int l=0;
        int i=0,cou=0,cou2=0;
        for(i=0;i<s.size();i++)
        {
            if(s[i]=='{')
            {
                cou++;
            }
            else 
            {
                if(cou==0)
                {
                    cou2++;
                    cou++;
                }
                else
                    cou--;
            }
        }
        cout<<p<<". "<<((cou2)+(cou)/2)<<endl;
        p++;
    }
	return 0;
}