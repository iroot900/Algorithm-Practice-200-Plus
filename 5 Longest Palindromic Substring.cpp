class Solution {
public:
    string longestPalindrome(string s) {
        // use all the middle and update longest,  N^2;
        // dynamic programming , N^2 and more space so, not good for this. good for partition though
        int n=s.size();
        int longest=0;
        int start=0;
        for(int i=0;i<n;i++)
        {
            int left=i-1,right=i+1;
            int len=1;
            while(left>=0&&right<n&&s[left]==s[right])
            {
                --left;++right;  len+=2;
            }
            if(longest<len)
            {
               longest=len; start=left+1;
            }
       }
        for(int i=0;i<n-1;i++)
        {
            int left=i,right=i+1;
            int len=0;
            while(left>=0&&right<n&&s[left]==s[right])
            {
                --left;++right;len+=2;
            }
            if(longest<len)
            {
               longest=len; start=left+1;
            }
        }
        return s.substr(start,longest);
    }
};
