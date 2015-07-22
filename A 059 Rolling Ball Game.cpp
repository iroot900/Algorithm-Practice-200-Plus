#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

//return a matrix. distance is the closet cops
//for each cop do a BFS record the distance. 
//update the result distance, if new cop distance is closer. 
//k.cop. k*n*n


//search grid. used a visited map to record distance, a updated result matrix. 
bool BSF(vector<vector<char>> &grid )
{
	int m = grid.size(); if (m == 0) return true;
	int n = grid.front().size();
	vector<vector<bool>> visited(m, vector<bool> (n,false));

	queue < pair<int, int>> que;
	que.push({ 0, 0 });
	visited[0][0] = true;
	while (!que.empty())
	{
		auto xx = que.front().first; auto yy = que.front().second; que.pop(); 
		//neighbor rules are now all different 
		int left = yy - 1;
		while (left - 1 >= 0 && grid[xx][left ]!='1' &&grid[xx][left - 1] == '0') --left;

		int up = xx - 1;
		while (up - 1 >= 0 && grid[up ][yy] != '1'&& grid[up - 1][yy] == '0') --up;

		int right = yy + 1;
		while (right + 1 < grid.front().size() && grid[xx][right ] != '1'&& grid[xx][right + 1] == '0') ++right;

		int down = xx + 1;
		while (down + 1 < grid.size() && grid[down][yy] != '1'&& grid[down + 1][yy] == '0') ++down;

		pair<int, int> pairs[4] = { { xx, left}, { xx, right }, { up, yy }, { down, yy } };
		for (auto pir : pairs)
		{
			auto x_ = pir.first; auto y_ = pir.second;
			if (x_ >= 0 && y_ >= 0 && x_ < grid.size() && y_ < grid.front().size() && !visited[x_][y_] && grid[x_][y_]!='1')// not visited yet. 	
			{
				if (grid[x_][y_] == 'E') return true;
				visited[x_][y_] = true; 
					que.push({ x_, y_ });
			}
		}
	}
	return false;
}

int main()
{
	vector<vector<char>> grid = {
		{ 'B', '0', '0', '0', '0', '0', '0', '0', '1', },
		{ '0', '0', '0', '0', '0', '0', '0', '0', '0', },
		{ '0', '0', '0', '0', '0', '0', '0', '0', '0', },
		{ '1', '0', '0', '0', '0', '0', '0', '0', '0', },
		{ '0', '0', '0', '0', '0', '0', '0', '1', '0', },
		{ '0', '0', '0', '0', '0', '0', '0', '0', '1', }, 
		{ '1', '0', '0', '0', '0', '0', '0', '0', 'E', },
	};

	for (auto line : grid)
	{
		for (auto cell : line)
			cout << cell << " ";
		cout << endl;
	}
	cout << endl;
	cout<<BSF(grid)<<endl;
	cout << endl << endl;


	grid[6][6] = '1';
	for (auto line : grid)
	{
		for (auto cell : line)
			cout << cell << " ";
		cout << endl;
	}
	cout << endl;
	cout << BSF(grid) << endl;
	cout << endl << endl;
	return 0;
}
