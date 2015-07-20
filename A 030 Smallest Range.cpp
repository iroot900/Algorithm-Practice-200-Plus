//You have k lists of sorted integers. Find the smallest range that includes at least one number from each of the k lists.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <queue>
using namespace std;
 
class comp
{
public:
	bool operator() (pair<int,int> left, pair<int,int> right) const 
	{
		return right.first < left.first;
	}
};

pair<int, int> smallRange(vector<vector<int>>& dataList)
{
	int row = dataList.size();
	
	pair<int, int> range;
	int mmax = INT_MIN;
	priority_queue < pair<int, int>, vector<pair<int, int>>, comp>  heap;
	vector<int> index(row, 0);
	for (int i = 0; i < row; ++i) { mmax = max(mmax, dataList[i][0]); heap.push({ dataList[i][0], i }); };
	range.first = heap.top().first; range.second = mmax;
	while (1)
	{
		int minRow = heap.top().second;
		if (index[minRow] == dataList[minRow].size() - 1) break;
		index[minRow]++;
		heap.pop(); heap.push({ dataList[minRow][index[minRow]], minRow }); mmax = max(mmax, dataList[minRow][index[minRow]]); 
		if ((mmax - heap.top().first) < (range.second - range.first))
		{	
			range.first = heap.top().first; range.second = mmax;
		}
	}
	return range;
} 

int main()
{
	vector<vector<int>> data = { { 1, 2, 4, 8, 14, 20 }, { 6, 10, 21, 25, 30 }, { 3, 7, 9, 15, 25 } };
	auto ret = smallRange(data);
	cout << ret.first << " " << ret.second << endl;


	vector<vector<int>> data1 = { { 1, 2, 3 }, { 5, 10 }, { 4, 12 }  };
	auto ret1 = smallRange(data1);
	cout << ret1.first << " " << ret1.second << endl;

	vector<vector<int>> data2 = { { 4, 10, 15, 24, 26 }, { 0, 9, 12, 20 }, { 5, 18, 22, 30 } };
	auto ret2 = smallRange(data2);
	cout << ret2.first << " " << ret2.second << endl;

	return 0;
}
