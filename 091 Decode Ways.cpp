class Solution {
public:
    int numDecodings(string s) {
           int n=s.size();
           if(n==0) return 0;
           vector<int> f(n+1,0);
           f[1]=1;
           f[0]=1;
           if(s[0]=='0') return 0;
           for(int i=2;i<=n;++i)
           {
                if(s[i-1]=='0'&&s[i-2]!='1'&&s[i-2]!='2') return 0;
                if(s[i-2]=='1'&&s[i-1]>'0'&&s[i-1]<='9'|| s[i-2]=='2'&&s[i-1]>'0'&&s[i-1]<='6')
                {
                    if(i<n&&(s[i-1]=='1'||s[i-1]=='2')&&s[i]=='0')
                    f[i]=f[i-1];
                    else
                    {
                        f[i]=f[i-1]+f[i-2];
                    }
                }
                else 
                f[i]=f[i-1];
           }
           return f[n];
    }
};
