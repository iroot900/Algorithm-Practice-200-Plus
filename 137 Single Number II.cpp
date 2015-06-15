class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> digits(sizeof(int)*8,0);
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<sizeof(int)*8;++j)
            {
                digits[j]+=(nums[i]&1) ;
                nums[i]>>=1;
            }
        }
        
        int single=0;
        for(int j=0;j<sizeof(int)*8;++j)
        {
            digits[j]=digits[j]%3 ;
            single+=(digits[j]<<j);
        }
        return single;
    }
};
