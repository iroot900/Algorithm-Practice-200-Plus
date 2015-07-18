//There are n nodes numbered from 0 to n-1 and a set of edges (undirected). Please determine if it is a valid tree.

//Valid tree. must be all connected and no cycle

// Method A:  undirected graph using DFS to check connection(all visited) and cycle(no visited neighbor except parent).
bool DFS(int cur, int parent,unordered_map<int,vector<int>>& graph, unordered_set<int>& visited) // need a starting point. assume '0'
{
    visited.insert(cur);
    for(auto neigh:graph[cur])
    {
        //check if parent
        if(neigh==parent) continue;
        if(visited.count(neigh)!=0) return false;
        if(DFS( neigh, cur, graph, visited)) continue;
        else return false;
    }
    return true;
}

bool valid_tree(vector<vector<int>>& edges, int n) {
    unordered_map<int,vector<int>> graph;  // ordinary graph. 
    for(auto edge:edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    // dfs to check cycle and record visited node. 
    unordered_set<int> visited;
    if(!DFS(0, -1, graph, visited)) return false;
    
    for(int i=0;i<n;++i)
    {
        if(visited.count(i)==0) return false;
    }
    return true;
}


// Method B:  union find.   vertex parent vector. union by edges. when try to union two vertex have the same parent-->cycle. 
//                          check parent. [parents[i]=i]. more than one not connected graph. 

class UnionFind
{
    public:
	UnionFind(int n)
	{
		parents.resize(n);
		for (int i = 0; i < n; ++i)
		{
			parents[i] = i;
		}
	}

	void Union(int x, int y)
	{
		//if (parents[x] == parents[y]) return;
		int xParent = Find(x);
		int yParent = Find(y);
		parents[xParent] = yParent;
	}

	int Find(int x)
	{
		if (parents[x] == x) return x;
		parents[x] = Find(parents[x]);
		return parents[x];
	}

	bool unique()
	{
	    int count=0;
		for(int i=0;i<parents.size();++i)
		{
		    if(parents[i]==i) ++count;
		}
		return count==1;
	}
private:
	vector<int> parents;
};
 
 
 bool valid_tree(vector<vector<int>>& edges, int n) {

	if (n < 2) return true;
	UnionFind uFind(n);
	for (auto edge : edges)
	{
		int x = edge[0];
		int y = edge[1];
		if (uFind.Find(x) == uFind.Find(y))
			return false;
		uFind.Union(x,y);
	}
	return uFind.unique();
}
