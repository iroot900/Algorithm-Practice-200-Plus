class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char,int> dict;
        int count=0;
        int start=0;
        int len=0;
        for(int i=0;i<s.size();++i)
        {
            if(dict.count(s[i])==0) // find a new cha. 
            {
                if(count<2){ dict[s[i]]++ ; ++count;}// not two add one. 
                else // count is two . already have two distince remove previous till only one unique 
                {
                    len=max(len,i-start);
                    for(int j=start;j<i;++j)
                    {
                            dict[s[j]]--;
                            if(dict[s[j]]==0)
                            {
                                dict.erase(s[j]); 
                                start=j+1;
                                break;
                            }
                    }
                    dict[s[i]]++;
                }
            }
            else 
            {
                dict[s[i]]++ ;
            }
        }
        len=max(len,(int)s.size()-start);
        return len;
    }
};
