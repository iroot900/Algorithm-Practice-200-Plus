class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(), n=p.size();
        
        int i=0;
        int j=0;
        int pos=-1;
        int start=-1;
        // abcxxxefgxxxcdf
        // abc*efg*cdf
        while(i<m)  /// position of j is important.  when p's out, should still try to match if it's *.
        {
            if(j<n&&s[i]==p[j]||p[j]=='?')
            {
                ++i;++j;
            }
            else if(j<n&&p[j]=='*')
            {
                ++j;
                start=j;
                pos=i;
            }// another logic 
            else if(pos!=-1)
            {
                j=start;
                i=++pos;
            }
            // can't move anymore. 
            else return false;
        }
        
        while(j<n&&p[j]=='*') ++j;
        return (j==n);
    }
};
