#include <iostream>
#include <vector>
#include <random>
#include <time.h>
using namespace std;

vector<int> sampling(int n,int k)
{
	vector<int> data(k);
	for(int i=0;i<k;++i) data[i]=i+1;

	for(int i=k;i<n;++i)
	{
		int rd=rand()%(i+1);
		if(rd<k) data[rd]=i+1;
	}
	return data;
}

int main()
{
	srand(time(0));
	auto ret=sampling(100,10);
	for(auto digit:ret) cout<<digit<<" ";
	cout<<endl;
}
