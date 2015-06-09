class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //char, so longest window is 256
        int window[256];
        fill(begin(window),end(window),-1);
        int n=s.size();
        int start=0;
        int mmax=0;
        for( int i=0;i<n;i++)
        {
            if(window[s[i]]>=start)
            {
                mmax=max(mmax,i-start);
                start=window[s[i]]+1;
            }
            window[s[i]]=i;
        }
        mmax=max(mmax,n-start);
        return mmax;
    }
};
