//Longest Increasing Subsequence
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//6 1 7 4 2 3 7 5 3 9
//again dynamic programming.

// important what's f[]?
// the equation.
// subsequence. 
// as in max subarr. --- f[] is the len end with here. not necessary  the longest for the whole .

int longestIncrSub(vector<int> &nums)
{
	int n = nums.size();
	vector<int> f(n,1);
	f[0] = 1;

	for (int i = 1; i < n; ++i)
	{
		for (int j = i-1; j >= 0; --j) //second update. 
		{
			if (nums[i]>nums[j])
				f[i] = max(f[i], f[j] + 1);
		}
	}
	return *max_element(begin(f),end(f));
}

int main()
{
	vector<int> data = { 6, 1, 7, 2, 3, 7, 5, 2, 9 };
	cout << longestIncrSub(data) << endl;
}
