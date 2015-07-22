//a grid with obstacle, and K already known points. 
//find the point, the sum of it's distance to all the k is smallest
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

void BFS(int x,int y, const vector<vector<char>>& grid, vector<vector<int>>& visited)
{
	// BFS. a queue and a visited map.   while() { top. pop. {for neighbor}  .three steps. done!}
	queue<pair<int,int>> que;
	que.push({x,y});
	while(!que.empty())
	{
		int xx=que.front().first, yy=que.front().second; que.pop();
		pair<int,int> pairs[4]={ {1,0},{0,1},{-1,0},{0,-1}};
		for(auto pir:pairs)
		{
			if((xx+pir.first)>=0&&(xx+pir.first)<grid.size()&&(yy+pir.second>=0)&&(yy+pir.second)<grid.front().size()&& !visited[xx+pir.first][yy+pir.second]&&grid[xx+pir.first][yy+pir.second]!='1'&&grid[xx+pir.first][yy+pir.second]!='x')
			{
				que.push({xx+pir.first,yy+pir.second});
				visited[xx+pir.first][yy+pir.second]=visited[xx][yy]+1;
			}
		}
	}
}

vector<vector<int>> minDistance(vector<vector<char>>& grid)
{
	int m=grid.size();
	int n=grid.front().size();

	vector<vector<int>> result(m, vector<int>(n,0));
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(grid[i][j]=='1')
			{
				vector<vector<int>> visited(m, vector<int>(n,0));
				DFS( i, j, grid, visited);
				cout<<i<<" "<<j<<" : "<<endl;
				for(int k=0;k<m;++k)
				{
					for(int t=0;t<n;++t)
					{
						result[k][t]+=visited[k][t];
						cout<<setw(3)<<visited[k][t]<<" ";
					}
					cout<<endl;
				}
				cout<<endl;
			}
		}
	}
	return result;
}

//main logic:
// Start from all the '1' find it's distance to the whole graph. 
// BFS for distance. one visited graph. if(=='x'or '1') don't care.  
// Queue need pair for (x,y) visited graph also for distance 
// Rechord a distance graph. -->add visited graph to distance graph. 
// Distance graph. find min distance sum. ('1' and 'x' distance set as INT_MAX)


int main()
{
	vector<vector<char>> grid={
		{'0','x','0','1','0','0','0','0','0'},
		{'0','0','0','0','0','0','0','1','0'},
		{'0','0','0','x','0','0','x','0','0'},
		{'0','1','0','0','0','0','0','0','0'},
		{'0','0','0','0','1','0','1','0','0'},
		{'0','x','0','0','x','0','0','0','0'},
		{'1','0','0','0','0','0','0','0','0'},
		{'0','0','0','0','0','0','0','0','1'},
		{'0','0','0','1','0','0','x','0','0'},
	};
	for(auto line:grid)
	{
		for(auto cell:line)
			cout<<cell<< " ";
		cout<<endl;
	}
	cout<<endl<<endl;
	auto ret=minDistance(grid);
	for(auto line:ret)
	{
		for(auto cell:line)
			cout<<setw(3)<<cell<< " ";
		cout<<endl;
	}
	cout<<endl;
	return 0;
}
