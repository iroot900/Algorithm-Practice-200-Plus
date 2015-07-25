#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//base from 1-9

void multiply(string& ret, string &base)
{
	int n=ret.size();
	int m=base.size();
	//
	vector<int> digit(n+m,0);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			digit[i+j]+= (ret[i]-'0')*(base[j]-'0') ;
		}
	}
	
	int carry=0;
	int num=0;
	ret.clear();
	for(int i=0;i<m+n;++i)
	{
		num=(carry+digit[i])%10;
		ret+=num+'0';
		carry=digit[i]/10;
	}
	ret.resize(n);
}

string lastKdigits(int base,int n, int k)
{
	if(base>10||base<1||n<0||k<=0) return "";
	
	string ret=string(k-1,'0')+'1';
	if(base==1||n==0) return ret;
	string baseStr=to_string(base);

	reverse(begin(ret),end(ret));
	for(int i=0;i<n;++i)
	{
		multiply(ret,baseStr);
	}

	reverse(begin(ret),end(ret));
	return ret;
}

int main()
{
	cout<<lastKdigits(1,5,2)<<endl;
	cout<<lastKdigits(1,5,1)<<endl;
	cout<<lastKdigits(5,0,2)<<endl;

	cout<<lastKdigits(5,10,10)<<endl;
	cout<<lastKdigits(5,20,10)<<endl;
	cout<<lastKdigits(2,30,10)<<endl;
	cout<<lastKdigits(2,40,10)<<endl;
}

