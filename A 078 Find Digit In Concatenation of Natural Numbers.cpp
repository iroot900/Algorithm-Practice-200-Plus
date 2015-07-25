#include <iostream>
#include <math.h>
using namespace std;

int nthConcat(int n)
{
	if(n<0) return -1;
	int digit=1;
	int nums=9;
	while(n-nums>0)
	{
		n=n-nums;
		++digit;
		nums=digit*(pow(10,digit)-pow(10,digit-1));
	}
	//n is at leat 1. 
	// 1 2 3 4 5 / 5
	int pos=(n-1)/digit;
	int remain=digit-(n-1)%digit-1;
	int base=pow(10,digit-1);
	
	int numPos=base+pos;
	while(remain)
	{
		--remain;
		numPos/=10;
	}
	return numPos%10;
}

int main()
{
	for(int i=1;i<=500;++i)
		cout<<nthConcat(i)<<" ";
	cout<<endl;
}
