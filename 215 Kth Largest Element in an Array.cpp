class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        return quickSelect(nums, 0, n-1, k);
    }
    
    int partition(vector<int>& nums, int left, int right)
    {
        int l=left,r=right-1;
        while(1)
        {
            // 2 1
            
            while(nums[l]<nums[right]) ++l;
            while(nums[r]>=nums[right]) --r;
            if(l>=r) break;
            swap(nums[l],nums[r]);
        }
        swap(nums[l],nums[right]);// this make sure it's ordered. 
        return l;
    }

    int quickSelect(vector<int>& nums, int left, int right,int k)
    {
        // 1 2-- 21 ..
        if(left==right&&k==1) return nums[left];
        if(left>right) return -1;
        int p=partition(nums, left, right);
        if(right-p==k-1) return nums[p];
        if(right-p>k-1)
        return quickSelect(nums, p+1 ,right, k); 
        else return quickSelect(nums, left, p-1, k-(right-p+1));
    }
};
