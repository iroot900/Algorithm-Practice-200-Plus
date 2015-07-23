
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

//Find the intersection of two sorted arrays.
#include <algorithm>
using namespace std;
 
vector<int> interSection(vector<int> A, vector<int> B)
{
	int m = A.size(), n = B.size();
	if (m == 0 || n == 0) return{};
	int i = 0, j = 0; vector<int> ret;
	while (i < m&&j < n)
	{
		if (A[i] < B[j]) ++i;
		else if (A[i] > B[j]) ++j;
		else { ret.push_back(A[i]); ++i; ++j; }
	}
	return ret;
}

int main()
{
	vector<int> data1 = { 1, 3, 4, 5, 7, 9 };
	vector<int> data2 = { 2, 3, 5, 6, 7, 8, 10, 12 };
	auto ret = interSection(data1, data2);
	for (auto num : ret) cout << num << " ";
	cout << endl;
}
