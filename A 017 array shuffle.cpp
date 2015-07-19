#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

void Myshuffle(vector<int>& data)
{
	for(int i=data.size()-1;i>=0;--i)
	{
		swap(data[i],data[rand()%(i+1)]);
	}
}

int main()
{
	srand(time(0));
	vector<int> data={1,2,3,4,5,6,7,8};
	Myshuffle(data);
	for(auto digit:data) cout<<digit<<" ";
	cout<<endl;

	cout<<"--"<<endl;

	random_shuffle(begin(data),end(data));
	for(auto digit:data) cout<<digit<<" ";
	cout<<endl;
}
