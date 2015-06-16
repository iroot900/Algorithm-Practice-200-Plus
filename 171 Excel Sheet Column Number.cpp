class Solution {
public:
    int titleToNumber(string s) {
    int num=0;
    int n=s.size();
    for(int i=0;i<n;++i)
    {
        num=num*26+(s[i]-'A'+1);
    }
    return num;
    }
};
