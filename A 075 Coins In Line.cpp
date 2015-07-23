#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int coinsInLine(vector<int> nums)
{
		int n = nums.size();
			if (n == 0) return 0;
				vector<vector<int>> f(n,vector<int> (n,0));

					for (int len = 0; len < n; ++len)
							{
										for (int i = 0 ,j = i+len; j < n; ++i, ++j)
													{
																	if (i == j) f[i][j] = nums[i];
																				else if (i + 1 == j) f[i][j] = max(nums[i],nums[j]);
																							else
																											{
																																f[i][j] = max(nums[i] + min(f[i+2][j],f[i+1][j-1]), //i+1,j
																																							nums[j] + min(f[i + 1][j - 1], f[i][j - 2]));  //i,j-1;
																																			}
																									}
													}
					return f[0][n-1];
}

int main()
{
		vector<int> data = {1,3,2,7,4,6};
			cout<<coinsInLine(data)<<endl;
				return 0;
}
