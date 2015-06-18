class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ret=0;
        
        for(int i=0;i<32&&m;++i)
        {
            if(n-m==0&&(n&1)) ret+=(1<<i);
            n=n>>1;m=m>>1;
        }
        return ret;
    }
};
