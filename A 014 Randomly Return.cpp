#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int myRand(int n)
{
	for(int i=0;i<n;++i)
		if(rand()&1) return 0;
	return 1;
}

int main()
{
	srand(time(0));
	for(int i=0;i<100;++i)
		cout<<myRand(3)<<" ";
	cout<<endl;
}
