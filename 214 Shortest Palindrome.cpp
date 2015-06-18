class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        if(n<2) return s;
        string temp=s+string(s.rbegin(),s.rend());
        int m=temp.size();
        vector<int> prefix(m);
        prefix[0]=0;
        int last=0;
        for(int i=1;i<m;++i)
        {
            while(last>0&&temp[i]!=temp[last])
            {
                last=prefix[last-1];
            }
            if(temp[last]==temp[i])
            last++;
            prefix[i]=last;
        }
        int len=n-prefix[m-1];
        return string(s.rbegin(),s.rbegin()+len)+s;
    }
};
