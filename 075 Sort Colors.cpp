class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors(3,0);
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            colors[nums[i]]++;
        }
        
        for(int i=0;i<n;++i)
        {
            if(colors[0])
            {
                nums[i]=0;colors[0]--;
            }
            else if(colors[1])
            {
                nums[i]=1;colors[1]--;
            }
            else
            nums[i]=2;
        }
    }
};
