#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> zeroSum(vector<int> & nums)
{
	int m=nums.size();
	unordered_map<int,int> sums;
	int cursum=0;
	sums[0]=-1;
	int start=-1;
	int end=-2;
	for(int i=0;i<m;++i)
	{
		cursum+=nums[i];
		if(sums.count(cursum)==0)
		{
			sums[cursum]=i;
		}
		else 
		{
			if((i-sums[cursum]-1)>(end-start) )
			{
				start=sums[cursum]+1;
				end=i;
			}
		}
	}
	vector<int> result;
	for(int i=start;i<=end;++i)
	{
		result.push_back(nums[i]);
	}
	return result;
}

int main()
{
	vector<int> nums={1,2,-3,1,5,-5,6};
	auto ret=zeroSum(nums);
	for(auto dig:ret)
		cout<<dig<<" ";
	cout<<endl;
}
