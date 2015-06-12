class Solution {
public:
    double myPow(double x, int n) {
        return myPowHelper(x,n);
    }
    
    
    double myPowHelper(double x, long n)
    {
        if(n<0) return 1/myPowHelper(x,-n);
        if(n==0) return 1;
        double a=myPowHelper(x,n/2);
        if(n&1) return a*a*x;
        else return a*a;
    }
};
