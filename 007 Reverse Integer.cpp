class Solution {
public:
    int reverse(int x) {
        if(x<0) 
        {
             //INT_MIN TO positive will overflow and it's reverse will overlow too.
             if(x==INT_MIN) return 0; return -reverse(-x);
        }
        long sum=0;
        while(x)
        {
            sum=sum*10+x%10; x/=10;
        }
        if(sum>INT_MAX) return 0;
        return sum;
    }
};
