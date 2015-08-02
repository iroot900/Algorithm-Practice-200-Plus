class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        if(n<2) return s;
        //     aaacd   dcaaa
        string rstr=string(s.rbegin(),s.rend());
        string str=s+rstr;
        auto pre=prefix(str);
        int len=n-pre[2*n-1];
        return rstr.substr(0,len)+s; 
    }
    
    vector<int> prefix(string str)
    {
        int n=str.size();
        vector<int> pre(n,0);
        pre[0]=0;
        
        for(int i=1;i<n;++i)
        {
            int last=pre[i-1];
            while(last>0&&(str[i]!=str[last]||last>=n/2)) { last=pre[last-1]; }
            if(str[i]==str[last]) pre[i]=last+1;
        }
        return pre;
    }
};
