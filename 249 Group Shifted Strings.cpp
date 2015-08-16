class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string>> groups;
         
            for(auto str:strings)
            {
                string pattern;
                for(int i=1;i<str.size();++i)
                {
                    pattern+=char((str[i]+26-str[i-1])%26);
                }
                groups[pattern].push_back(str);
            }
            
            vector<vector<string>> ret;
            for(auto pir:groups)
            {
                     sort(begin(pir.second),end(pir.second));
                     ret.push_back(pir.second);
            }
            return ret;
    }
};
