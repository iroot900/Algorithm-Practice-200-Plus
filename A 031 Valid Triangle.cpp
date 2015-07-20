#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <queue>
using namespace std;

int validTriangle(vector<int> & nums)
{
	sort(begin(nums), end(nums));
	int n = nums.size();
	int count = 0;
	for (int i = 0; i < n-2; ++i)
	{
		int k = i + 2;
		for (int j = i+1; j < n - 1; ++j)
		{
			while (k < n&&nums[i] + nums[j]>nums[k]) ++k; 
			count += k - j - 1; // there is a mechanism here. if(k not move this time. next time. sure it will move )
			//if (k == j + 1) ++k; this way would make more sense. 
		}
	}
	return count;
}

vector<vector<int>>  allTriangle(vector<int> & nums)
{
	sort(begin(nums), end(nums));

	int n = nums.size();
	vector<vector<int>> result;
	for (int i = 0; i < n - 2; ++i)
	{
		int k = i + 2;
		for (int j = i + 1; j < n - 1; ++j)
		{
			while (k < n&&nums[i] + nums[j]>nums[k]) ++k;
			for (int m = j + 1; m < k; ++m)
			{
				result.push_back({ nums[i], nums[j], nums[m] });
			}
			//if (k == j + 1) ++k; this way would make more sense.  
		}
	}
	return result;
}

int main()
{
	vector<int> segments = { 1,2, 3, 4, 5, 11, 20, 35 };
	cout <<"Number of valid triangles: "<< validTriangle(segments) << endl<<endl;

	auto ret = allTriangle(segments);
	for (auto tri : ret)
	{
		for (auto seg : tri)
		{
			cout << seg << " ";
		}
		cout << endl;
	}
	cout << endl;
}
