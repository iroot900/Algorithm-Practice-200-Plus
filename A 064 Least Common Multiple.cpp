#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	if(a<b) swap(a,b);
	if(a%b!=0)
		return gcd(b,a%b);
	return b;
}

int lcm(int a,int b)
{
	return a/gcd(a,b)*b;
}

int main()
{
	cout<<lcm(10,8)<<endl;
	return 0;
}
