class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        int n=strs.size();
        if(n==0) return prefix;
        int len=INT_MAX;
        for(auto str:strs)
        {
            len=min(len,(int)str.size());
        }
        for(int i=0;i<len;++i)
        {
            for(int j=1;j<n;++j)
            {
                if(strs[j][i]!=strs[0][i])
                return prefix;
            }
            prefix+=strs[0][i];
        }
        return prefix;
    }
};
