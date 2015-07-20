//X times 7 without + - / * %;
#include <iostream>
using namespace std;

int binaryAdd(int a,int b)
{
	int digit=0;
	int result=0;
	int base=1;
	int carry=0;
	while(a||b)
	{
		int left=a&1, right=b&1;
		if(left&&right&&carry) {digit=1; carry=1;}
		else if(!(left|right|carry)) {digit=0; carry=0;}
		else if(left^right^carry) {digit=1;carry=0;}
		else {digit=0; carry=1;}

		a=a>>1;b=b>>1;
		if(digit) result=result|base;
		base=base<<1;
	}
	if(carry) result=result|base;
	return result;
}
// time 8 is easy (<<3)  -- > times*8
int time7(int x)
{
	return binaryAdd(x<<2, binaryAdd(x<<1,x) );
}

int main()
{
	cout<<time7(1)<<endl;
	cout<<time7(2)<<endl;
	cout<<time7(3)<<endl;
	return 0;
}
