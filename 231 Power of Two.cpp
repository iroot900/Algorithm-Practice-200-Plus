class Solution {
public:
    bool isPowerOfTwo(int n) { // power of 4. 
        //   1 2 4 8 .  one is 1 other's zeros.
        int count=0;
        if(n<1) return false;
        for(int i=0;i<32;++i)
        {
            count+=(n>>i)&1;
        }
        return count==1;
    }
};
