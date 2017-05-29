#include <bits/stdc++.h>
using namespace std;
int main()
{
	/*
	3UB   |  6UB  
	2MB   |  5MB  
	1LB   |  4LB  
	7SL   |  8SU*/
	int t;
	cin>>t;
	char data[8][3];
	data[0][0]='S';
	data[0][1]='L';
	data[1][0]='L';
	data[1][1]='B';
	data[2][0]='M';
	data[2][1]='B';
	data[3][0]='U';
	data[3][1]='B';
	data[4][0]='L';
	data[4][1]='B';
	data[5][0]='M';
	data[5][1]='B';
	data[6][0]='U';
	data[6][1]='B';
	data[7][0]='S';
	data[7][1]='U';
	while(t--)
	{
		int n;
		cin>>n;
		int nn=n%8;
		int tt=nn;
		int nnn=n/8;
		if(nn==1)
			nn=(nnn)*8+nn+3;
		else if(nn==2)
			nn=(nnn)*8+nn+3;
		else if(nn==3)
			nn=(nnn)*8+nn+3;
		else if(nn==4)
			nn=(nnn)*8+nn-3;
		else if(nn==5)
			nn=(nnn)*8+nn-3;
		else if(nn==6)
			nn=(nnn)*8+nn-3;
		else if(nn==7)
			nn=(nnn+1)*8;
		else if(nn==0)
			nn=(nnn)*8-1;
		cout<<nn<<data[tt][0]<<data[tt][1]<<endl;
	}
	return 0;
}