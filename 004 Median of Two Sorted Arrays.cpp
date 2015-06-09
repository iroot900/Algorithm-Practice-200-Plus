class Solution {
public:
    //I'm not happy with this solution. too easy to make a mistake. 
    //The argument use to be array[] which make things way more easy to handle by passing array address
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int len=m+n;                   
        if(len&1) return findK(nums1,nums2,len/2+1,0,0);
        else  return (findK(nums1,nums2,len/2,0,0)+findK(nums1,nums2,len/2+1,0,0))/2;
    }
    
      double findK(vector<int>& nums1, vector<int>& nums2, int k,int left, int right)
    {   //  1   2    4 , 3
        //main logic and boundary condition
        if(left==(int)nums1.size()) return nums2[right+k-1];
        if(right==(int)nums2.size()) return nums1[left+k-1];
        
        if(k==1) return min(nums1[left],nums2[right]);  
        int ln=k/2; //1   
        if(ln>(int)nums1.size()-left)
        {
            if(nums1.back()<nums2[right+k-(nums1.size()-left)-1])
            return findK(nums1,nums2,k-((int)nums1.size()-left),nums1.size(),right);
            else
            return findK(nums1,nums2,nums1.size()-left,left,right+k-(nums1.size()-left));
        }
        
        int rn=k-k/2; //1
        if(rn>(int)nums2.size()-right) 
        {
            if(nums2.back()<nums1[left+k-(nums2.size()-right)-1])
            return findK(nums1,nums2,k-((int)nums2.size()-right),left,nums2.size());
            else return findK(nums1,nums2,nums2.size()-right,left+k-(nums2.size()-right),right);
        }
        //2   0 ,  1        0+2-1   [1]
        if(nums1[left+ln-1]==nums2[right+rn-1]) return nums1[left+ln-1];
        else if(nums1[left+ln-1]>nums2[right+rn-1]) return findK(nums1,nums2,k-rn,left,right+rn);
        if(nums1[left+ln-1]<nums2[right+rn-1]) return findK(nums1,nums2,k-ln,left+ln,right);
    }
};
