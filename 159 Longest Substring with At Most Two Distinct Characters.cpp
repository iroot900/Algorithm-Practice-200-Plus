class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        //logic   ---- go till a third one show up....  then, move to the one start. 
        // main
        // boudnary
        unordered_set<char> set;
        int longest=0;
        int len=0;
        int start=0;
        int next=0;
        
        int n=s.size();
        if(n<3) return n;
        set.insert(s[0]);
        int i=1;
        for(;i<n;++i)
        {
            if(set.size()<2) 
            {
                set.insert(s[i]);
                if(s[i]!=s[start])
                next=i;
            }
            else if(set.find(s[i])==set.end())// new char shows up
            {
                set.erase(s[next-1]);
                longest=max(longest,i-start);
                start=next;
                set.insert(s[i]);
                next=i;
            }
            else // old again  aaaabbaaaaa 
            {
                if(s[i]!=s[next])
                next=i;
            }
            // if a new one show's up... go to next and update longest;
            // else . update the next
        }
        return max(longest,i-start);
    }
};
