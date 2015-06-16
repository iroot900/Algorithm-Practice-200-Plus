class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while(n>0)
        {
            int digit=(n-1)%26;
            result.push_back(digit+'A');
            n=(n-1)/26;
        }
        reverse(begin(result),end(result));
        return result;
    }
};
