class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> visited;
        for(auto word:words)
        visited[word]++;
        unordered_map<string,int> dict;
        vector<int> result;
        int n=s.size();
        int size=(int)words.size();
        if(size==0) return result;
        int len=(int)words.front().size();
        int m=size*len;
        for(int i=0;i<n-m+1;i++)
        {
            dict=visited;
            if(isSubstring(s.substr(i,m),dict,len))
            result.push_back(i);
        }
        return result;
    }
    
    bool isSubstring(const string& s,unordered_map<string,int>& dict,int len)
    {
        for(int i=0;i<s.size();i+=len)
        {
            auto it=dict.find(s.substr(i,len));
            if(it==dict.end()) return false;
            else
            {
                if(it->second==0)
                {
                    return false;
                }
                else it->second=it->second-1;
            }
        }
        return true;
    }
};
