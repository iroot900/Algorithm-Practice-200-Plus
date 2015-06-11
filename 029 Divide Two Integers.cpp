class Solution {
public:
    int divide(int dividend, int divisor) {
        long a=dividend, b=divisor;
        int sign=0;
        if(dividend<0) {a=-a;++sign;}
        if(divisor<0) {b=-b;++sign;}
        long result=0;
        while(a>=b)
        {
            for(long i=1;a-i*b>=0;i=i<<1)
            {
                a-=i*b;
                result+=i;
            }
        }
        if(sign&1) return -result; 
        else return result>INT_MAX?INT_MAX:result;
    }
};
