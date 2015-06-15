class Solution {
public:
    int jump(vector<int>& nums) {
        //jump min steps.
        //fix step. furthest could be reach. 
        int n=nums.size();
        if(n<2) return 0;
        int last=nums[0];
        int next=nums[0];
        int step=1;
        for(int i=1;i<n;++i)
        {
            // 0 1 2 3 4
            if(i>last)
            {
                last=next;
                ++step;
            }
            next=max(next,nums[i]+i);
        }
        return step; 
    }
};
