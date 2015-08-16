class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cha(256,0);
        int m=s.size();
        if(m!=t.size()) return false;
        
        for(int i=0;i<m;++i)   cha[s[i]]++; 
        
        for(int i=0;i<m;++i)
        {
             cha[t[i]]--;
             if(cha[t[i]]<0) return false;
        }
        return true;
    }
};
