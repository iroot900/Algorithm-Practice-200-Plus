class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        vector<bool> digits(n+1,0);
        fill(begin(digits),end(digits),false);
        // 1   2   3    4 
        // 24  6   2    1
        for(int i=n-1;i>=0;i--)
        {
            int base=factorial(i);
            int cur=(k-1)/base;  //k-1.. when 6 for 321 no need to go up
            k = k - cur*base; // since last line, this should be this,   cur*base represent sequence now use, get the remain. 
            for(int i=1;i<=n;++i)
            {
                if(cur==0)
                {
                    while(digits[i]==true) ++i;
                    ret.push_back(i+'0');
                     digits[i]=true;
                    break;
                }
                if(digits[i]==false) {
                    --cur;
                }
            }
        }
        return ret;
    }
    
    int factorial(int n)
    {
        if(n==0||n==1) return 1;
        return n*factorial(n-1);
    }
};
