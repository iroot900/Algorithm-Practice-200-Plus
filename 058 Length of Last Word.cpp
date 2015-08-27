class Solution {
public:
    int lengthOfLastWord(string s) {
        int start=0; 
        int end=0;
        int len=0;
        while(1)
        {
            start=s.find_first_not_of("     ",end);
            if(start==string::npos) break;
            end=s.find_first_of("   ",start);
            if(end==string::npos) end=s.size();
            len=end-start;
        }
        return len;
    }
};
