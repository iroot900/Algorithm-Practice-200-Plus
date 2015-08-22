class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum=0;
        for(int i=0;i<32;i++)
        {
            sum+=(n&1);
            n>>=1;
        }
        return sum;
        
        /* more efficient way
        int count=0;   
        while(n) {n=n&(n-1); ++count; }
        return count;
        */
    }
    
    
};
