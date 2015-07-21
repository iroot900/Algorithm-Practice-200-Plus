// Example program
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> missing(vector<int>& nums, int n)
{
    vector<int> ret;
    int m=nums.size();
    int index=0;
    int i=1;
    for(;i<=n;++i)
    {
        if(nums[index]==i)
        {
            ++index; while(index<m&&nums[index]==nums[index-1]) ++index;
            if(index==m) {++i ;break;}
        }
        else if(nums[index]>i) ret.push_back(i);
    }
    for(;i<=n;++i)
    {
        ret.push_back(i);
    }
	return ret;
}

int main()
{
	vector<int> data={2,3,4,4,4,5,5,7 };
	auto ret=missing(data,9);
	for(auto digit:ret) cout<<digit<<" ";
	cout<<endl;
}
