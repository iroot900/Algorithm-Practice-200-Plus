class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //next_permutation(begin(nums),end(nums));
        
        //         if increasing then can't make it more, so find the first decrease, then, that's where it all start, then, 
        //         1 2 3 4 
        //         1 2 4 3    
        //         1 3 2 4
        //         1 4 3 2 
        
        // find the one violate increasing. 
        // fint the one , find the next larger one , put it front, and move front back,  swap so.
        // next reverse the rest. just need the next lager one....

        int i=(int)nums.size()-2;
        for(;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            break;
        }
        // 1 2 
        int j=(int)nums.size()-1;
        for(;j>=0;j--)
        {
            if(nums[j]>nums[i]) break;
        }
        if(i>=0&&j>=0)// this is important 
        swap(nums[j],nums[i]);
      
        reverse(begin(nums)+i+1,end(nums));
    }
};
