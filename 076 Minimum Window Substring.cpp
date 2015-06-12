class Solution {
public:
    string minWindow(string s, string t) {
        //start point, end point. shrink start point.
        //need to know when contains all and shrink policy. 
        
        //main logic.  if belong to put word in, 
        unordered_map<char,int> dict;
        for(auto cha:t)
        dict[cha]--;
        int count=0;
        int n=s.size(), m=t.size();
        if(n<m) return "";
        int start=0; 
        string result=s+"1"; 
        for(int i=0;i<n;++i)
        {
            auto it=dict.find(s[i]);
            if(it!=dict.end())// if find it. 
            {
                dict[s[i]]++;
                if(dict[s[i]]<=0) ++count;
                if(count==m)// full, start to move.
                {
                    while(1)
                    {
                        if(dict.find(s[start])==dict.end())
                        {
                            ++start;
                        }
                        else if(dict[s[start]]>0)
                        {
                            dict[s[start]]--;++start; 
                        }
                        else if(dict[s[start]]==0)
                        {
                            break;
                        }
                    }
                    if(result.size()>(i-start+1))
                    result=s.substr(start,i-start+1);
                }
            }// not found, just go.
        }
        if(result==s+"1") return "";
        return result;
    }
    
    bool full(const unordered_map<char,int>& dict)
    {
        if(none_of(begin(dict),end(dict),[](pair<char,int> x){return x.second<0;}) )
        return true;
        else return false;
    }
};
