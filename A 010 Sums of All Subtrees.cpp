//Given a vector of Treenode, each Treenode has ID and ParentID, also Value
//return sums of of subtrees. (from each Node go down is a subtree)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class TreeNode
{
	public:
	int id;
	int parentId;
	int value;
};

unordered_map<int,int> subSums(const vector<TreeNode>& nodes)
{
	unordered_map<int,TreeNode> nodeInfo;
	// find all the non parent ones. 
	vector<int> leafs;
	unordered_set<int> parents;
	unordered_map<int,bool> used;

	for(auto node:nodes)
	{
		nodeInfo[node.id]=node;
		used[node.id]=false;
		parents.insert(node.parentId);
	}

	for(auto node:nodes)
	{
		if(parents.count(node.id)==0)
			leafs.push_back(node.id);
	}

	unordered_map<int,int> subSums; //(id and sum)
	
	int curId=-1;
	for(auto leafId:leafs)
	{
		curId=leafId;
		cout<<leafId<<" : "<<endl;
		while(1)
		{
			int parentId=nodeInfo[curId].parentId;
			if(parentId==-1) break;
			if(used[curId]) subSums[parentId]+=nodeInfo[leafId].value;
			else 
			{
				subSums[curId]+=nodeInfo[curId].value;
				subSums[parentId]+=subSums[curId];
				used[curId]=true;
			}
			cout<<subSums[curId]<<" "<<subSums[parentId]<<endl;
				curId=parentId;
		}
	}
	subSums[curId]+=nodeInfo[curId].value;

	return subSums;
}

int main()
{
	// modern c++ write constructor only when you need deep copy/con
	// for value, {} could do the job for you 
	vector<TreeNode> Nodes={{0,-1,1},{1,0,2},{2,0,3},{3,1,4},{4,1,5}};

	auto result=subSums(Nodes);
	for(auto sub:result)
	{
		cout<<"SubRootId "<<sub.first<<" sum: "<<sub.second<<endl;
	}
	return 0;
}
