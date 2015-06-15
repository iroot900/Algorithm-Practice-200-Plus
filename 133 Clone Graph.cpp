/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    // BFS. 
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==nullptr) return node;
        queue<UndirectedGraphNode*> que;
        unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> visited;// each node will be visited. and mean while check his neighbor.. when visited. first time create node. when it's neighbor. include neigbhors. 
        UndirectedGraphNode* root=new UndirectedGraphNode(node->label);
        que.push(node);
        visited[node]=root;
        while(!que.empty())
        {
            auto vert=que.front();que.pop();
            for(auto neigb:vert->neighbors)
            {
                auto it=visited.find(neigb);
                if(it==visited.end())//not visited. 
                {
                    auto clone=new UndirectedGraphNode(neigb->label);
                    visited[neigb]=clone;
                    que.push(neigb);
                    visited[vert]->neighbors.push_back(clone);
                }
                else
                {
                    visited[vert]->neighbors.push_back(visited[neigb]);
                }
            }
        }
        return root;
    }
};
