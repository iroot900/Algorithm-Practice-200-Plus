class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> p=prefix(needle);
        int m=needle.size();
        int n=haystack.size();
        if(m>n) return -1;
        int i=0;
        while(i<=n-m)  
        {
            int temp=i,j=0;
            for(  ;j<m;j++)
            {
                if(haystack[temp]==needle[j]) {++temp;continue;}
                else
                {
                    if(j!=0)
                    {i+=j-p[j-1];break;}
                    else 
                    {i+=1; break;}
                }
            }
            if(j==m) return i;
        }
        return -1;
    }
    
    vector<int> prefix(const string & str)
    {
        int len=0, n=str.size();
        vector<int> p(n);
        for(int i=1;i<n;i++)
        {
            while(len>0&&str[i]!=str[len]) len=p[len-1];//same idea as KMP
            //len and last, len'  first few = len's last few.so len's first=last
            if(str[i]==str[len]) len++;
            p[i]=len;
        }
        return p;
    }
};
