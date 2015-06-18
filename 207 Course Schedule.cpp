class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int,int>>& prerequisites) {
        
        unordered_map<int,vector<int> > courses;
        vector<int> incoming(numCourses,0);
        
        for(auto par:prerequisites)
        {
            courses[par.second].push_back(par.first);
            ++incoming[par.first];
        }
        
        queue<int> que;
        // those who can be visited immediately. 
        
        for(int i=0;i<numCourses;i++)
        {
            if(incoming[i]==0) que.push(i);
        }
        
        while(!que.empty())
        {
            int cur=que.front();
            que.pop();
            for(auto cor:courses[cur])
            {
                --incoming[cor];
                if(incoming[cor]==0) que.push(cor);
            }
        }
        
        for(auto cor:incoming)
        if(cor!=0) return false;
        return true;
    }
};
