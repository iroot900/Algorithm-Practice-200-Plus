#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int randomMax(const vector<int>& data)
{
	int count=0;
	int mmax=INT_MIN;
	int index=0;
	for(int i=0;i<data.size();++i)
	{
		if(data[i]>mmax)
		{
			index=i;
			count=1;
			mmax=data[i];
		}
		else if(data[i]==mmax)
		{
			++count;
			if(rand()%count==0)  index=i;
		}
	}
	return index;
}

int main()
{
	srand(time(0));
	vector<int> data={2,1,2,1,5,4,5,5};
	cout<<randomMax(data)<<endl;
}
