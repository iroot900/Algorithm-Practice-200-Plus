class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=0;
        int digit=0;
        vector<int> result(n,0);
        if(n==0)
        {
            result.push_back(1); return result;
        }
        result[n-1]=(digits[n-1]+1)%10;
        carry=(digits[n-1]+1)/10;
        for(int i=n-2;i>=0;--i)
        {
            result[i]=(digits[i]+carry)%10;
            carry=(digits[i]+carry)/10;
        }
        if(carry)
        result.insert(begin(result),carry);
        return result;
    }
};
