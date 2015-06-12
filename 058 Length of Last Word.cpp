class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int start=-1;
        int i=0;
        int lastLen=0;
      //  if(n==0) return 0;
        for(;i<n;++i)
        {
            if(s[i]==' ') 
            {
                lastLen=i-start-1;
                start=i;
             while(i+1<n&&s[i+1]==' ')
             {
                 ++i;
                 start=i;
             }
             }

        }
        if(s[i-1]==' ') return lastLen;
        return i-1-start;
    }
};
