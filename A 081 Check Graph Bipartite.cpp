#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;


// build a graph. 
template<typename T=int> 
class Graph
{
	public:
		Graph(bool directed_=false):directed(directed_){}
		
		void addEdges(T a,T b)
		{
			if(neighbors.size()==0) node=a;
			neighbors[a].push_back(b);
			if(!directed)
			{
				neighbors[b].push_back(a);
			}
		}

		bool cycle()
		{
			if(directed) return cycle2();

			queue<T> que;
			unordered_map<T,T> visited;
			que.push(node); visited[node]=T();
			while(!que.empty())
			{
				auto nod=que.front(); que.pop();
				for(auto neigh:neighbors[nod])
				{
					if(visited.count(neigh)!=0)
					{
						if(visited[nod]!=neigh) {return true;}
					}
					else 
					{
						que.push(neigh);
						visited[neigh]=nod;
					}
				}
			}
			return false;
		}

		bool DFS(T node, unordered_set<T>& path, unordered_set<T>& visited)
		{
			if(path.count(node)!=0) return true;
			path.insert(node);
			if(visited.count(node)) return false;
			for(auto neigh:neighbors[node])
			{
				if(DFS(neigh,path,visited)) return true;
			}
			path.erase(node);
			return false;
		}

		bool cycle2()
		{
			//directed should use deep first search.  if go back to the path. return true 
			unordered_set<T> path;
			unordered_set<T> visited;
			return DFS(node,path,visited);
		}

		bool bipartite()
		{
			//directed graph ? undirected graph ?  doesn't matter
			//start from one neighbor not visited give other color inque. visited check color
			enum COLOR {RED,BLUE};
			unordered_map<T,COLOR> visited;
		    queue<T> que;
			if(neighbors.size()==0) return false;
			que.push(node);
			visited[node]=BLUE;

			while(!que.empty())
			{
				auto node=que.front(); que.pop();
				for(auto neigh:neighbors[node])
				{
					if(visited.count(neigh)==0) 
					{
						visited[neigh]=(visited[node]==RED?BLUE:RED);
						que.push(neigh);
					}
					else 
					{
						if(visited[neigh]==visited[node]) return false;
					}
				}
			}
			return true;
		}

	private:
		unordered_map<T,vector<T>> neighbors;
		T node;
		bool directed=false;
};

int main()
{
	Graph<int> graph;
	graph.addEdges(1,13);
	graph.addEdges(1,12);
	graph.addEdges(1,19);
	graph.addEdges(2,15);
	graph.addEdges(2,18);
	graph.addEdges(2,19);
	graph.addEdges(3,18);
	graph.addEdges(3,14);
	graph.addEdges(3,11);
	graph.addEdges(4,11);
	graph.addEdges(4,14);
	graph.addEdges(4,14);
	graph.addEdges(4,16);
	graph.addEdges(4,17);
	graph.addEdges(5,14);
	graph.addEdges(5,13);
	graph.addEdges(5,17);
	
	cout<<graph.bipartite()<<endl;
	graph.addEdges(5,4);
	cout<<graph.bipartite()<<endl;

	Graph<string> graph2;
	graph2.addEdges("chicago","ann arbor");
	graph2.addEdges("chicago","san jose");
	cout<<graph2.cycle()<<endl;
	
	graph2.addEdges("ann arbor","san jose");
	cout<<graph2.cycle()<<endl;
	
	Graph<string> graph3(true);
	graph3.addEdges("chicago","ann arbor");
	graph3.addEdges("ann arbor","detroit");
	graph3.addEdges("ann arbor","lansing");
	graph3.addEdges("detroit","lansing");
	cout<<graph3.cycle()<<endl;
	graph3.addEdges("lansing","detroit");
	cout<<graph3.cycle()<<endl;
	return 0;
}
