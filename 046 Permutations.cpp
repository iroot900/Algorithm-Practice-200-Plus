class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
       // sort(begin(nums),end(nums));
        vector<int> visited(nums.size(),0);// when duplicates. binary state(bool) is insufficient. use integer to tackle it. 
        //if it's unique then, permuation is n!
        //and takes n^n; no need to sort!
        
        vector<int> solution;
        vector<vector<int>> result;
         DFS(0, nums,result, solution, visited);
        return result;
    }
    
    void DFS(int depth, vector<int>& nums,vector<vector<int>> &result,vector<int>& solution,vector<int>& visited)
    {
        if(depth==nums.size())
        {
            result.push_back(solution);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]==0)
            {
                visited[i]=1;
                solution.push_back(nums[i]);
                DFS(depth+1, nums,result, solution, visited);
                solution.pop_back();
                visited[i]=0;
            }
        }
    }
};
