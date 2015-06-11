class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int p=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[p]) {nums[++p]=nums[i];}
        }
        return ++p;
    }
};
