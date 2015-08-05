class Solution {
public:
     void DFS(vector<bool>& used, vector<int>& nums, vector<vector<int>>& result, vector<int>& solu)
    {
    	if (solu.size() == nums.size()) { result.push_back(solu); return; }
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if (!used[i])
    		{
    			used[i] = true;
    			solu.push_back(nums[i]);
    			DFS(used, nums, result, solu);
    			solu.pop_back();
    			used[i] = false;
    			while (i + 1<nums.size() && nums[i + 1] == nums[i]) ++i; // same level no twice // 
    		}
    	}
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	sort(begin(nums), end(nums));
    	vector<int> solu;
    	vector<vector<int>> result;
    	int n = nums.size();
    	vector<bool> used(n, false);
    	DFS(used, nums, result, solu);
    	return result;
    }
};
