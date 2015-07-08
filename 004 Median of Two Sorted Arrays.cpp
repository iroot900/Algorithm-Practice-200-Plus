class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // find median of two sorted array.  /
        int m=nums1.size();
        int n=nums2.size();
        int total=m+n;
        if(total&1)  
        return findKth(nums1, 0, nums2,  0,  (m+n)/2+1);
        else 
        return (findKth(nums1,  0, nums2,  0,  (m+n)/2+1)+findKth(nums1,  0, nums2,  0,  (m+n)/2))/(2.0); 
    } 
    int findKth(vector<int>& nums1, int left, vector<int>& nums2, int right, int k)
    {
        
        // boundary one
        if(nums1.size()==left) return nums2[right+k-1];
        if(nums2.size()==right) return nums1[left+k-1];
        // boundary two 
        if(k==1)    return min(nums1[left],nums2[right]);
        
        //  one side could be gone so go middle or the small side. k==2 k==3 k==4 
        int len=k/2;
        
        // left as a bench
        if(len>nums1.size()-left)
        {
            len=nums1.size()-left; // left side is too small. take all left. 
        }
        else if(k-len>nums2.size()-right) // right side is too small. 
        {
            len=(k-(nums2.size()-right)) ;
        }
        
        if(nums1[left+len-1]==nums2[right+(k-len)-1]) return nums1[left+len-1];
        else if (nums1[left+len-1]>nums2[right+(k-len)-1]) return findKth(nums1,  left, nums2,  right+(k-len),  k-(k-len));// keep left
        else return findKth(nums1,  left+len, nums2,  right,  k-len);
    }
};
