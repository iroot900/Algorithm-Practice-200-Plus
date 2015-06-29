class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m=s.size(), n=t.size();
        if(abs(m-n)>1) return false;
        
        if(m==n)
        {
            int miss=0;
            for(int i=0;i<m;++i)
            {
                if(s[i]!=t[i])  ++miss;
            }
            if(miss==1) return true; 
            else return false;
        }
        
        if(m>n) swap(s,t);
        
        bool insert=false;
        for(int j=0, i=0;i<t.size();++i,++j)
        {
            if(s[j]!=t[i])
            {
                if(insert==true) return false;
                --j; insert=true;
            }
        }
        return insert==true;
    }
};
