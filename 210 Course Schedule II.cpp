class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // graph
        // incoming count;
        // que, in all the one with incoming zeros, then, visit neighbor, when incoming zero , enque;
        unordered_map<int,int> incomings;
        unordered_map<int,vector<int>> neighbors;
        vector<int> result;
        
        //it's directed 
        for(auto pir:prerequisites)
        {
            incomings[pir.first]++;
            neighbors[pir.second].push_back(pir.first);
        }
        queue<int> que;
        for(int i=0;i<numCourses;++i)
        {
            if(incomings.find(i)==incomings.end()) {que.push(i);result.push_back(i);}
        }
        
        while(!que.empty())
        {
            int node=que.front(); que.pop();
           
            for(auto neg:neighbors[node])
            {
                incomings[neg]--;
                if(incomings[neg]==0)
                {
                    que.push(neg);  result.push_back(neg);
                }
            }
        }
        if (none_of(begin(incomings),end(incomings), [] (pair<int,int> node ) {return node.second>0;}))
        {
            return result;
        }
        else return vector<int> ();
    }
};
