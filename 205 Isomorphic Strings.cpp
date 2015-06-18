class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mapping(256,-1);
        vector<int> used(256,0);
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            if(mapping[s[i]]==-1){
                mapping[s[i]]=t[i];
                if(used[t[i]]==1) return false;
                used[t[i]]=1;
            }
            else
            {
                if(mapping[s[i]]!=t[i]) return false;
            }
        }
        return true;
    }
};
