#include <bits/stdc++.h>
using namespace std;
string result;
bool loo=false;
int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0 ; i < len2 - len1 ; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0 ; i < len1 - len2 ; i++)
            str2 = '0' + str2;
    }
    return len1;
}
void addBitStrings(string first, string second)
{
    int length = makeEqualLength(first, second);
    int carry = 0;
    for (int i = length-1 ; i >= 0 ; i--)
    {
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';
        int sum = (firstBit ^ secondBit ^ carry)+'0';
        result = (char)sum + result;
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }
    if (carry)
        result = '1' + result;

    return;
}
void addStrings(string first, string second)
{
    int length = makeEqualLength(first, second);
    int carry = 0;
    for (int i = length-1 ; i >= 0 ; i--)
    {
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';
        int sum = (firstBit ^ secondBit ^ carry)+'0';
        result = (char)sum + result;
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }
    if (carry)
    {
    	string ff=result;
    	result.clear();
    	addBitStrings(ff,"1");
    }
    else
    	loo=true;

    return;
}
long long int po(long long int k)
{
	long long int y;
	for(int i=0;i<k;i++)
		y=y*2;
	return y;
}
int main()
{
	long long int L,ans=1;
	cin>>L;
	while(L--)
	{
		string s1,s2,s3,ss1="1";
		long long int k,s;
		bool gaga=true;
		cin>>s1>>s2>>s3>>k;
		for(int i=0;i<k;i++)
			s1.append(s2);
		s1.append(s3);
		ans=1;
		while(gaga)
		{
			string st1,rs1;
			st1.clear();
			for(int i=0;i<s1.size();i++)
			{
				if(s1[i]=='0')
					st1.append("1");
				else
					st1.append("0");
			}
			result.clear();
			rs1.clear();
			addBitStrings(st1,ss1);
			//cout<<"s1     "<<s1<<endl<<"st1    "<<st1<<endl;
			long long int length=makeEqualLength(result,s1);
			for(int i=0;i<length;i++)
			{
				if(result[i]=='0'|| s1[i]=='0')
					rs1.append("0");
				else
					rs1.append("1");
			}
			//cout<<"result "<<result<<endl<<"rs1    "<<rs1<<endl;
			string hh="0",hj="0";
			hh.append(s1);
			hj.append(rs1);
			for(int i=0;i<hj.size();i++)
			{
				if(hj[i]=='0')
					hj[i]='1';
				else
					hj[i]='0';
			}
			cout<<"hh     "<<hh<<endl<<"hj     "<<hj<<endl;
			result.clear();
			loo=false;
			addStrings(hh,hj);
			cout<<"result "<<result<<endl;
			if(loo)
			{
				cout<<ans<<endl;
				gaga=false;
			}
			else
			{
				// s1=NULL;
				// s1.append(result);
				long long int su=0;
				int kkk=s1.size()-1;
				for(int i=kkk;i>=0;i--)
				{
					if(s1[i]=='1')
						su=su+pow(2,kkk-i);
				}
				//cout<<su<<endl;
				s1=result;
				ans++;
			}
			// gaga=false;
		}
	}
	return 0;
}