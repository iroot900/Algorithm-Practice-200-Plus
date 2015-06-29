class Solution {
public:
    void reverseWords(string &s) {
        //  eulb si yks eht 
        //  blue is sky the
        reverse(begin(s),end(s));
        int n=s.size();
        int left=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]==' ')
            {
                reverse(s.begin()+left,s.begin()+i);
                left=i+1;
            }
        }
        reverse(s.begin()+left,end(s));
    }
};
