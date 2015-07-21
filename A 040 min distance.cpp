#include <iostream>
#include <vector>
using namespace std;
//main logic
// see a word keep it new's position
// if other exist update distance also. 
int minDistance(vector<int> & nums, int x, int y)
{
	int n=nums.size();
	pair<int, int> candidateA(x,-1);
	pair<int, int> candidateB(y,-1);

	int diff=INT_MAX;
	for(int i=0;i<n;++i)
	{
		if(nums[i]==candidateA.first)
		{
			candidateA.second=i;
			if( candidateB.second!=-1)
				diff=min(candidateA.second-candidateB.second,diff);
		}
		if(nums[i]==candidateB.first)
		{
			candidateB.second=i;
			if( candidateA.second!=-1)
				diff=min(candidateB.second-candidateA.second,diff);
		}
	}
	return diff;
}

int main()
{
	vector<int> data={2,5,3,5,4,4,2,3};
	cout<<minDistance(data,2,3)<<endl;
}
