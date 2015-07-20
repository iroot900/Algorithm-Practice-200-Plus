#include <iostream>
using namespace std;

bool power4(int x)
{
	if(x<1) return false;
	int even=0b10101010101010101010101010101010;
	return (x&(x-1))==0&&( (x&even)==0);
}

int odd_even(int x)
{
//	int even=x&0xAAAAAAAA;
//	int odd=x&0x55555555;
	int odd=x&0b01010101010101010101010101010101;
	int even=x&0b10101010101010101010101010101010;
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
