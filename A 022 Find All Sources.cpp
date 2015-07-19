// Given an arr, each value means the steps each node could jump (to left or right)
// input a node's index. return indexs of nodes which could reach it. 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

// construct a (directed) graph from arr
vector<int> sources(const vector<int> & arr, int p)
{
	unordered_map<int,vector<int>> graph;
	int n=arr.size();
	for(int i=0;i<n;++i)
	{
		for(int j=1;j<=arr[i];++j)
		{
			if(i+j<n) graph[i+j].push_back(i);
			if(i-j>=0) graph[i-j].push_back(i);
		}
	}

	//result is all the nodes reachable by p. 
	//BFS or DFS Ok

	vector<int> ret;
	unordered_set<int> visited;
	queue<int> que; 
	que.push(p);
	visited.insert(p);

	while(!que.empty())
	{
		int node=que.front(); que.pop();
		for(auto nei:graph[node])
		{
			if(visited.count(nei)==0)
			{
				visited.insert(nei);
				que.push(nei);
				ret.push_back(nei);
			}
		}
	}
	return ret;
}

int main()
{
	vector<int> arr={1,3,0,2,4,7};
	for(int i=0;i<arr.size();++i)
	{
		auto ret=sources(arr,i);
		cout<<i<<" : "<<endl;
		for(auto node:ret)
			cout<<node<<" ";
		cout<<endl;
	}
	return 0;
}
