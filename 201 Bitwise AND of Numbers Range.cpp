class Solution {
public:
    int rangeBitwiseAnd(int m, int n) { 
        
        for(int i=30;i>=0;--i)
        {
            if ((m>>i)!=(n>>i)) return (m>>i+1)<<(i+1);
        }
        return m;
    }
};
