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
// do BFS from multiple sources. n*n. brilliant and natural!!!! -- nothing change, but initial queue(sources).


//search grid. used a visited map to record distance, a updated result matrix. 
void BSF(int x, int y, vector<vector<char>> &grid, vector<vector<int>>& visited)
{
	queue < pair<int, int>> que;
	que.push({ x, y });
	visited[x][y] = 0;
	while (!que.empty())
	{
		auto xx = que.front().first; auto yy = que.front().second; que.pop(); 
		pair<int, int> pairs[4] = { { 0, -1 }, { -1, 0 }, { 1, 0 }, { 0, 1 } };
		for (auto pir : pairs)
		{
			auto x_ = xx + pir.first; auto y_ = yy + pir.second;
			if (x_ >= 0 && y_ >= 0 && x_ < grid.size() && y_ < grid.front().size() && visited[x_][y_] == -1)// not visited yet. 	
			{
				visited[x_][y_] = visited[xx][yy]+1;
				if (grid[x_][y_] != 'x')
					que.push({ x_, y_ });
			}
		}
	}
}

vector<vector<int>> distance(vector<vector<char>> & grid)
{
	int m = grid.size(); if (m == 0) return{};
	int n = grid.front().size();

	vector<vector<int>> ret(m, vector<int>(n, INT_MAX));
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (grid[i][j] == 'c')
			{
				vector<vector<int>> visited(m, vector<int>(n, -1));
				BSF(i, j, grid, visited);
				for (int t = 0; t < m; ++t)
				{
					for (int k = 0; k < n; ++k)
					{
						ret[t][k] = min(ret[t][k], visited[t][k]);
					}
				}
			}
		}
	}

	return ret;
}


vector<vector<int>> multiBFS(vector<vector<char>> & grid)
{
	int m = grid.size(); if (m == 0) return{};
	int n = grid.front().size();

	vector<vector<int>> visited(m, vector<int>(n, -1));
	queue < pair<int, int>> que;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (grid[i][j]=='c')
			{
				que.push({ i, j });
				visited[i][j] = 0;
			}
		}
	}

	while (!que.empty())
	{
		auto xx = que.front().first; auto yy = que.front().second; que.pop();
		pair<int, int> pairs[4] = { { 0, -1 }, { -1, 0 }, { 1, 0 }, { 0, 1 } };
		for (auto pir : pairs)
		{
			auto x_ = xx + pir.first; auto y_ = yy + pir.second;
			if (x_ >= 0 && y_ >= 0 && x_ < grid.size() && y_ < grid.front().size() && visited[x_][y_] == -1)// not visited yet. 	
			{
				visited[x_][y_] = visited[xx][yy] + 1;
				if (grid[x_][y_] != 'x')
					que.push({ x_, y_ });
			}
		}
	}
	return visited;
}


int main()
{
	vector<vector<char>> grid = {
		{ '0', 'c', 'x', '0', '0', '0', 'c', 'x', '0', },
		{ '0', '0', '0', 'c', '0', '0', '0', 'x', '0', },
		{ 'x', '0', '0', '0', '0', 'x', '0', '0', 'c', },
		{ '0', '0', '0', '0', '0', '0', '0', '0', '0', },
		{ '0', '0', 'c', 'x', '0', 'c', 'x', '0', 'x', },
		{ '0', 'x', '0', '0', '0', '0', '0', '0', '0', },
		{ 'x', '0', '0', '0', '0', '0', '0', 'x', '0', },
		{ '0', '0', '0', '0', 'x', '0', '0', '0', '0', },
		{ 'c', '0', 'x', '0', '0', '0', 'c', '0', '0', },
	};

	for (auto line : grid)
	{
		for (auto cell : line)
			cout << cell << " ";
		cout << endl;
	}
	cout << endl << endl;
	auto ret = distance(grid);

	for (auto line : ret)
	{
		for (auto cell : line)
			cout << cell << " ";
		cout << endl;
	}

	cout << endl << endl;
	auto ret2 = multiBFS(grid);
	for (auto line : ret2)
	{
		for (auto cell : line)
			cout << cell << " ";
		cout << endl;
	}
}
