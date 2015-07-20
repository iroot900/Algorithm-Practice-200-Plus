#include <iostream>
using namespace std;

bool power4(int x)
{
	if(x<1) return false;
	return (x&(x-1))==0&&( (x&0xAAAAAAAA)==0);
}

int odd_even(int x)
{
	int odd=x&0xAAAAAAAA;
	int even=x&0x55555555;
	return (odd<<1)|(even>>1);
}


bool power2(int x) // well 32 times, not so efficient. 
{
	if(x<0) return false;
	int one=0;
	for(int i=0;i<32;++i)//31 would be ok.
	{
		if((x>>i)&1) ++one;
	}
	return one==1;
}

bool power2_(int x)
{
	if(x<1) return false;
	return (x&(x-1))==0;
}


int main()
{
	for(int i=-1;i<17;++i)
		cout<<i<<" : "<<power2_(i)<<endl;
	cout<<endl;
	for(int i=-1;i<17;++i)
		cout<<i<<" : "<<power4(i)<<endl;
	cout<<endl;
}
