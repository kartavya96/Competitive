#include <iostream>
#include <string.h>

using namespace std;
int main()
{
	int n,k;
	cin>>n;
	k=1;
	char str[1000000];
	while(k<=n)
	{
		if(k==n)
		{
			if(k%2==0)
			{
				strcat(str,"I love it");
				cout<<str;
				return 0;
			}
			else
			{
				strcat(str,"I hate it");
				cout<<str;
				return 0;
			}
		}
		else if((k%2)==0)
		{
			strcat(str,"I love that ");
		}
		else if((k%2)!=0)
		{
			strcat(str,"I hate that ");
		}
		k++;
	}
	return 0;
}