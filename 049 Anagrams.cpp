class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> groups;
        for(auto str:strs)
        {
            auto temp=str;
            sort(begin(str),end(str));
            groups[str].push_back(temp);
        }
        vector<string> result;
        for(auto group:groups)
        {
           if(group.second.size()>1)
           for(auto anag:group.second)
           {
               result.push_back(anag);
           }
        }
        return result;
    }
};
