#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

pair<int,int> distance(vector<pair<int, int>> points)
{
	int n = points.size();
	if (n < 2) return {};

	map<pair<int, int>, int> dist;

	sort(begin(points), end(points), 
		[](pair<int, int> left, pair<int, int> right) {return left.first < right.first; });
	vector<int> xdist(n);
	xdist[0] = 0;
	for (int i = 1; i < n; ++i) { xdist[0] += points[i].first - points[0].first; } 

	dist[{points[0].first, points[0].second}] = xdist[0];
	for (int i = 1; i < n; ++i)
	{
		xdist[i] = xdist[i-1] + (-(n - i) + i)*(points[i].first - points[i-1].first); 
		dist[{points[i].first, points[i].second}] = xdist[i];
	}

	sort(begin(points), end(points), 
		[](pair<int, int> left, pair<int,int> right) {return left.second < right.second; });
	vector<int> ydist(n);
	ydist[0] = 0;
	for (int i = 1; i < n; ++i) { ydist[0] += points[i].second - points[0].second; } 
	dist[{points[0].first, points[0].second}] += ydist[0];
	for (int i = 1; i < n; ++i)
	{
		ydist[i] = ydist[i - 1] + (-(n - i) + i)*(points[i].second - points[i - 1].second); 
		dist[{points[i].first, points[i].second}] += ydist[i];
	}

	auto minDist = dist.begin()->second;
	pair<int, int> ret; 
	for (auto pir : dist)
	{
		cout <<"("<< pir.first.first <<","<<pir.first.second<< " )  " << pir.second << endl;
		if (pir.second <= minDist) { minDist = pir.second; ret = pir.first; }
	}
	return ret;
}
 
// 1     3    6   8     9
// 22   16    13  15    18 

// 22
// 22-2*4+2*1 -3
// 16-3*3+3*2 -1
// 13 -2*2+2*3 +1

int main()
{ 
	vector<pair<int, int>> points = { {8,8}, {6,2}, {9,4}, {1,5}, {3,0}};
	auto ret=distance(points);
	cout << ret.first << " " << ret.second << endl;
} 
