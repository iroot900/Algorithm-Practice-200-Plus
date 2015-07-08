class Solution {
public:
    int countDigitOne(int n) {
        if(n<0) return 0;
        long base=1;
        int high=0; int low=0;
        int count=0;
        
        while(n/base)
        {
            int digit=(n/base)%10;
            int high= (n/base)/10;
            int low= n%base;
            switch(digit)
            {
                case 0: count+=high*base; break;
                case 1: count+=high*base+low+1; break;
                default: count+=(high+1)*base; break;
            }
            base*=10;
        }
        return count;
    }
};
