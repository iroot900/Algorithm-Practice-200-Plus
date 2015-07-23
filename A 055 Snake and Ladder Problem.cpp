#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//what is actually a graph.  a vertex with neighbor and with nei...

int snakeLadder(vector<int> board)
{
	int n=board.size();
	queue<pair<int,int>> que;
	que.push({0,0});
	vector<int> visited(n,false);
	visited[0]=true;
	while(!que.empty())
	{
		auto cur=que.front().first; int depth=que.front().second; que.pop();
		for(int i=cur+1;i<min(cur+7,n);++i)
		{
			if(i==n-1) return depth+1;
			int next=i;
			if(board[i]!=-1)
			{
				next=board[i];
			}
			if(!visited[next])
			{
				que.push({next,depth+1});
				visited[next]=true;
			}
		}
	}
}

int main()
{
	vector<int> board(30,-1);
	board[2]=21;
	board[4]=7;
	board[10]=25;
	board[19]=28;
	board[26]=0;
	board[20]=8;
	board[16]=3;
	board[8]=6;
	cout<<snakeLadder(board)<<endl;
	cout<<endl;
}
