class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> deq;
        if(nums.size()==0) return {};
        for(int i=0;i<k;++i)
        {
            while(!deq.empty()&&deq.back().first<=nums[i])
            deq.pop_back();
            deq.push_back(make_pair(nums[i],i));
            
        }
        int n=nums.size();
        vector<int> result(n-k+1,0);
        result[0]=deq.front().first;
        for(int i=k;i<n;++i)
        {
            if((i-deq.front().second)==k) deq.pop_front();
            while(!deq.empty()&&deq.back().first<=nums[i])
            deq.pop_back();
            deq.push_back(make_pair(nums[i],i));
            result[i-k+1]=deq.front().first;
        }
        return result;
    }
};
