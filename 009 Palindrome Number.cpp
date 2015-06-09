class Solution {
public:
    bool isPalindrome(int x) {
        // don't need to deal like string, take advantage of int
        if(x<0) return false;
        long  sum=0;
        int temp=x;
        while(x)
        {
            sum=sum*10+x%10;
            x/=10;
        }
        return sum==temp;
    }
};
